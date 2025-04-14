const ESLintPlugin = require('eslint-webpack-plugin');
const TerserPlugin = require('terser-webpack-plugin');
const CopyPlugin = require('copy-webpack-plugin');
const path = require('path');
const fs = require('fs');

const optimization = {
  minimizer: [
    new TerserPlugin({
      parallel: true,
      terserOptions: {
        compress: false,
        ecma: 6,
        mangle: false,
        sourceMap: true,
      },
      extractComments: false,
    }),
  ],
};

const resolve = {
  alias: {
    util: path.resolve(__dirname, './htdocs/js/util'),
    jsx: path.resolve(__dirname, './jsx'),
    jslib: path.resolve(__dirname, './jslib'),
    Breadcrumbs: path.resolve(__dirname, './jsx/Breadcrumbs'),
    DataTable: path.resolve(__dirname, './jsx/DataTable'),
    DynamicDataTable: path.resolve(__dirname, './jsx/DynamicDataTable'),
    Filter: path.resolve(__dirname, './jsx/Filter'),
    FilterableDataTable: path.resolve(__dirname, './jsx/FilterableDataTable'),
    FilterForm: path.resolve(__dirname, './jsx/FilterForm'),
    Form: path.resolve(__dirname, './jsx/Form'),
    Loader: path.resolve(__dirname, './jsx/Loader'),
    Markdown: path.resolve(__dirname, './jsx/Markdown'),
    Modal: path.resolve(__dirname, './jsx/Modal'),
    MultiSelectDropdown: path.resolve(__dirname, './jsx/MultiSelectDropdown'),
    PaginationLinks: path.resolve(__dirname, './jsx/PaginationLinks'),
    Panel: path.resolve(__dirname, './jsx/Panel'),
    ProgressBar: path.resolve(__dirname, './jsx/ProgressBar'),
    StaticDataTable: path.resolve(__dirname, './jsx/StaticDataTable'),
    Tabs: path.resolve(__dirname, './jsx/Tabs'),
    TriggerableModal: path.resolve(__dirname, './jsx/TriggerableModal'),
    Card: path.resolve(__dirname, './jsx/Card'),
  },
  extensions: ['*', '.js', '.jsx', '.json', '.ts', '.tsx'],
  fallback: {
    fs: false,
  },
};

const mod = {
  rules: [],
};

const chunkPbPath = path.join(
  __dirname,
  'modules/electrophysiology_browser/jsx/react-series-data-viewer/src/protocol-buffers/chunk_pb.js'
);

if (!fs.existsSync(chunkPbPath)) {
  mod.rules.push({
    test: /react-series-data-viewer\/src\/chunks/,
    use: 'null-loader',
  });
}

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
    use: ['style-loader', 'css-loader'],
  },
  {
    test: /\.tsx?$/,
    use: [
      {
        loader: 'ts-loader',
        options: { onlyCompileBundledFiles: true },
      },
    ],
  }
);

function lorisModule(mname, entries, override = false) {
  const entry = {};
  const base = override ? './project/modules' : './modules';

  entries.forEach((e) => {
    entry[e] = path.join(base, mname, 'jsx', `${e}.js`);
  });

  return {
    entry,
    output: {
      path: path.resolve(__dirname, base, mname, 'js'),
      filename: '[name].js',
      library: ['lorisjs', mname, '[name]'],
      libraryTarget: 'window',
    },
    externals: {
      react: 'React',
      'react-dom': 'ReactDOM',
    },
    devtool: 'source-map',
    plugins: [],
    optimization,
    resolve,
    module: mod,
    mode: 'none',
    stats: 'errors-warnings',
  };
}

let mode = 'production';
try {
  const configFile = fs.readFileSync('project/config.xml', 'latin1');
  const match = configFile.match(/<\s*sandbox\s*>(.*?)<\/\s*sandbox\s*>/);
  if (match && parseInt(match[1]) === 1) {
    mode = 'development';
  }
} catch {
  console.error("Error - Can't read config.xml file. Webpack mode set to production.");
}

const config = [
  {
    mode,
    entry: {
      DynamicDataTable: './jsx/DynamicDataTable.jsx',
      PaginationLinks: './jsx/PaginationLinks.jsx',
      StaticDataTable: './jsx/StaticDataTable.jsx',
      MultiSelectDropdown: './jsx/MultiSelectDropdown.jsx',
      Breadcrumbs: './jsx/Breadcrumbs.jsx',
      Form: './jsx/Form.jsx',
      Markdown: './jsx/Markdown.jsx',
      CSSGrid: './jsx/CSSGrid.jsx',
    },
    output: {
      path: path.resolve(__dirname, 'htdocs/js/components'),
      filename: '[name].js',
      library: ['lorisjs', '[name]'],
      libraryTarget: 'window',
    },
    externals: {
      react: 'React',
      'react-dom': 'ReactDOM',
    },
    devtool: 'source-map',
    plugins: [
      new ESLintPlugin({
        files: [
          'modules/',
          'jsx/',
          'jslib/',
          'htdocs/js/',
          'webpack.config.js',
        ],
        cache: true,
      }),
      new CopyPlugin({
        patterns: [
          {
            from: path.resolve(__dirname, 'node_modules/react/umd'),
            to: path.resolve(__dirname, 'htdocs/vendor/js/react'),
            flatten: true,
            force: true,
            globOptions: {
              ignore: ['react.profiling.min.js'],
            },
            filter: async (filePath) => {
              const file = path.basename(filePath);
              return ['react.development.js', 'react.production.min.js'].includes(file);
            },
          },
          {
            from: path.resolve(__dirname, 'node_modules/react-dom/umd'),
            to: path.resolve(__dirname, 'htdocs/vendor/js/react'),
            flatten: true,
            force: true,
            filter: async (filePath) => {
              const file = path.basename(filePath);
              return ['react-dom.development.js', 'react-dom.production.min.js'].includes(file);
            },
          },
        ],
      }),
    ],
    optimization,
    resolve,
    module: mod,
    stats: 'errors-warnings',
  },

  lorisModule('media', ['CandidateMediaWidget', 'mediaIndex']),
  lorisModule('issue_tracker', [
    'issueTrackerIndex',
    'index',
    'CandidateIssuesWidget',
  ]),
  lorisModule('login', ['loginIndex']),
  lorisModule('publication', ['publicationIndex', 'viewProjectIndex']),
  lorisModule('document_repository', ['docIndex', 'editFormIndex']),
  lorisModule('candidate_parameters', [
    'CandidateParameters',
    'ConsentWidget',
  ]),
  lorisModule('configuration', ['SubprojectRelations', 'configuration_helper']),
  lorisModule('conflict_resolver', ['conflict_resolver']),
  lorisModule('battery_manager', ['batteryManagerIndex']),
  lorisModule('bvl_feedback', ['react.behavioural_feedback_panel']),
  lorisModule('behavioural_qc', ['behaviouralQCIndex']),
  lorisModule('create_timepoint', ['createTimepointIndex']),
  lorisModule('candidate_list', [
    'openProfileForm',
    'onLoad',
    'candidateListIndex',
  ]),
  lorisModule('datadict', ['dataDictIndex']),
  lorisModule('data_release', ['dataReleaseIndex']),
  lorisModule('dictionary', ['dataDictIndex']),
  lorisModule('dqt', [
    'components/expansionpanels',
    'components/searchabledropdown',
    'components/stepper',
    'react.app',
    'react.fieldselector',
    'react.filterBuilder',
    'react.navigationStepper',
    'react.notice',
    'react.savedqueries',
    'react.sidebar',
    'react.tabs',
  ]),
  lorisModule('dicom_archive', ['dicom_archive']),
  lorisModule('genomic_browser', ['genomicBrowserIndex']),
  lorisModule('electrophysiology_browser', [
    'electrophysiologyBrowserIndex',
    'electrophysiologySessionView',
  ]),
  lorisModule('imaging_browser', [
    'ImagePanel',
    'imagingBrowserIndex',
    'CandidateScanQCSummaryWidget',
  ]),
  lorisModule('instrument_builder', [
    'react.instrument_builder',
    'react.questions',
  ]),
  lorisModule('instrument_manager', ['instrumentManagerIndex']),
  lorisModule('survey_accounts', ['surveyAccountsIndex']),
  lorisModule('mri_violations', [
    'mri_protocol_check_violations_columnFormatter',
    'columnFormatter',
    'columnFormatterUnresolved',
    'mri_protocol_violations_columnFormatter',
  ]),
  lorisModule('global_configuration', [
    'configuration_index',
    'global_configuration_helper',
  ]),
  lorisModule('eeg_browser', ['react.eeg_browser', 'index']),
  lorisModule('nmi', ['nmiIndex']),
];

module.exports = config;

