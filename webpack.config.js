const TerserPlugin = require('terser-webpack-plugin');
const CopyPlugin = require('copy-webpack-plugin');
const path = require('path');
const fs = require('fs');
const cp = require('child_process');
const {IgnorePlugin, DefinePlugin} = require('webpack');

const modulePlugins = [];

const optimization = {
  minimizer: [
    (compiler) => {
      new TerserPlugin({
        parallel: true,
        terserOptions: {
          compress: false,
          ecma: 6,
          mangle: false,
        },
        extractComments: false,
      }).apply(compiler);
    },
  ],
};

const resolve = {
  alias: {
    jsx: path.resolve(__dirname, './jsx'),
    jslib: path.resolve(__dirname, './jslib'),
    Breadcrumbs: path.resolve(__dirname, './jsx/Breadcrumbs'),
    DataTable: path.resolve(__dirname, './jsx/DataTable'),
    Filter: path.resolve(__dirname, './jsx/Filter'),
    FilterableDataTable: path.resolve(__dirname, './jsx/FilterableDataTable'),
    FilterForm: path.resolve(__dirname, './jsx/FilterForm'),
    Loader: path.resolve(__dirname, './jsx/Loader'),
    Modal: path.resolve(__dirname, './jsx/Modal'),
    MultiSelectDropdown: path.resolve(__dirname, './jsx/MultiSelectDropdown'),
    PaginationLinks: path.resolve(__dirname, './jsx/PaginationLinks'),
    Panel: path.resolve(__dirname, './jsx/Panel'),
    ProgressBar: path.resolve(__dirname, './jsx/ProgressBar'),
    StaticDataTable: path.resolve(__dirname, './jsx/StaticDataTable'),
    Tabs: path.resolve(__dirname, './jsx/Tabs'),
    TriggerableModal: path.resolve(__dirname, './jsx/TriggerableModal'),
    Card: path.resolve(__dirname, './jsx/Card'),
    Help: path.resolve(__dirname, './jsx/Help'),
  },
  extensions: ['*', '.js', '.jsx', '.json', '.ts', '.tsx'],
  fallback: {
    fs: false,
    path: false,
  },
};

const mod = {
  rules: [],
};

/*
 * ------------------------------------------------------------
 * Check if useEEGBrowserVisualizationComponents is set to TRUE
 * If not, protoc compiled file chunk.proto may not exist.
 * Deactivate compilation of the EEGBrowserVisualization files
 * to avoid import errors and optimize performance
 */

let EEGVisEnabled = false;
if ('EEG_VIS_ENABLED' in process.env) {
  EEGVisEnabled = process.env.EEG_VIS_ENABLED;
} else {
  const getConfig = cp.spawnSync('php', [
    'tools/get_config.php',
    'useEEGBrowserVisualizationComponents',
  ], {});

  try {
    EEGVisEnabled = JSON.parse(getConfig.stdout);
  } catch (e) {
    console.warn(
      '\x1b[33m',
      'WARNING: Unable to fetch DB config',
      'useEEGBrowserVisualizationComponents',
      '\x1b[0m',
    );
  }
}

modulePlugins.push(
  new DefinePlugin({
    EEG_VIS_ENABLED: EEGVisEnabled,
  })
);

if (EEGVisEnabled !== 'true') {
  modulePlugins.push(
    new IgnorePlugin({
      resourceRegExp: /react-series-data-viewer/,
    })
  );
}

/*
 * ------------------------------------------------------------
 */

mod.rules.push(
  {
    test: /\.(jsx?|tsx?)$/,
    exclude: /node_modules/,
    use: [
      {
        loader: 'babel-loader?cacheDirectory',
      },
    ],
  },
  {
    test: /\.css$/,
    use: [
      'style-loader',
      'css-loader',
    ],
  },
  {
    test: /\.tsx?$/,
    use: [
      {
        loader: 'ts-loader',
        options: {onlyCompileBundledFiles: true},
      },
    ],
  },
);

/**
 * Creates a webpack config entry for a LORIS module named
 * mname.
 *
 * @param {string} mname - The LORIS module name
 * @param {array} entries - The webpack entry points for the module
 * @return {object} - The webpack configuration
 */
function lorisModule(mname, entries) {
  let entObj = {};
  let base = './modules';

  // Check if an override exists in ./project/
  if (fs.existsSync('./project/modules/' + mname)) {
    base = './project/modules';
  }

  for (let i = 0; i < entries.length; i++) {
    entObj[entries[i]] =
      base + '/' + mname + '/jsx/' + entries[i];
  }
  return {
    entry: entObj,
    output: {
      path: path.resolve(__dirname, base) + '/' + mname + '/js/',
      filename: '[name].js',
      library: ['lorisjs', mname, '[name]'],
      libraryTarget: 'window',
    },
    externals: {
      'react': 'React',
      'react-dom': 'ReactDOM',
    },
    devtool: 'source-map',
    plugins: modulePlugins,
    optimization: optimization,
    resolve: resolve,
    module: mod,
    stats: 'errors-only',
  };
}

const plugins = [
  new CopyPlugin({
    patterns: [
      {
        from: path.resolve(__dirname, 'node_modules/react/umd'),
        to: path.resolve(__dirname, 'htdocs/vendor/js/react'),
        force: true,
        globOptions: {
          ignore: ['react.profiling.min.js'],
        },
        filter: async (path) => {
          const file = path.split('\\').pop().split('/').pop();
          const keep = [
            'react.development.js',
            'react.production.min.js',
          ];
          return keep.includes(file);
        },
      },
      {
        from: path.resolve(__dirname, 'node_modules/react-dom/umd'),
        to: path.resolve(__dirname, 'htdocs/vendor/js/react'),
        force: true,
        filter: async (path) => {
          const file = path.split('\\').pop().split('/').pop();
          const keep = [
            'react-dom.development.js',
            'react-dom.production.min.js',
          ];
          return keep.includes(file);
        },
      },
    ],
  }),
];

let config = [
  // Core components
  {
    entry: {
      PaginationLinks: './jsx/PaginationLinks.js',
      StaticDataTable: './jsx/StaticDataTable.js',
      MultiSelectDropdown: './jsx/MultiSelectDropdown.js',
      Breadcrumbs: './jsx/Breadcrumbs.js',
      CSSGrid: './jsx/CSSGrid.js',
      Help: './jsx/Help.js',
    },
    output: {
      path: __dirname + '/htdocs/js/components/',
      filename: '[name].js',
      library: ['lorisjs', '[name]'],
      libraryTarget: 'window',
    },
    externals: {
      'react': 'React',
      'react-dom': 'ReactDOM',
    },
    devtool: 'source-map',
    plugins: plugins,
    optimization: optimization,
    resolve: resolve,
    module: mod,
    stats: 'errors-warnings',
  },
];

const lorisModules = {
  survey_accounts: ['surveyAccountsIndex'],
  participant_portal: ['Participant_Portal_Index'],
};
for (const [key] of Object.entries(lorisModules)) {
  const target = process.env.target;
  if (target && target !== key) {
    // continue loop if target exists && module key doesn't match
    continue;
  }
  config.push(lorisModule(key, lorisModules[key]));
}

// Support project overrides
if (fs.existsSync('./project/webpack-project.config.js')) {
  const projConfig = require('./project/webpack-project.config.js');

  for (const [module, files] of Object.entries(projConfig)) {
    config.push(lorisModule(module, files));
  }
}

module.exports = config;
