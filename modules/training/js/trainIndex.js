"use strict";

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }

var Title = function (_React$Component) {
  _inherits(Title, _React$Component);

  function Title() {
    _classCallCheck(this, Title);

    return _possibleConstructorReturn(this, (Title.__proto__ || Object.getPrototypeOf(Title)).apply(this, arguments));
  }

  _createClass(Title, [{
    key: "render",
    value: function render() {
      return React.createElement(
        "div",
        null,
        React.createElement(
          "h1",
          null,
          " ",
          this.props.title,
          " "
        )
      );
    }
  }]);

  return Title;
}(React.Component);

var Footer = function (_React$Component2) {
  _inherits(Footer, _React$Component2);

  function Footer() {
    _classCallCheck(this, Footer);

    return _possibleConstructorReturn(this, (Footer.__proto__ || Object.getPrototypeOf(Footer)).apply(this, arguments));
  }

  _createClass(Footer, [{
    key: "render",
    value: function render() {
      return React.createElement(
        "div",
        null,
        "This is a footer!"
      );
    }
  }]);

  return Footer;
}(React.Component);

var Header = function (_React$Component3) {
  _inherits(Header, _React$Component3);

  function Header() {
    _classCallCheck(this, Header);

    return _possibleConstructorReturn(this, (Header.__proto__ || Object.getPrototypeOf(Header)).apply(this, arguments));
  }

  _createClass(Header, [{
    key: "handle",
    value: function handle() {
      this.props.handle();
    }
  }, {
    key: "render",
    value: function render() {
      return React.createElement(
        "div",
        null,
        React.createElement(Title, { title: this.props.title }),
        React.createElement(
          "p",
          { onClick: this.handle.bind(this) },
          " This is a Header!"
        )
      );
    }
  }]);

  return Header;
}(React.Component);

var TrainIndex = function (_React$Component4) {
  _inherits(TrainIndex, _React$Component4);

  function TrainIndex(props) {
    _classCallCheck(this, TrainIndex);

    var _this4 = _possibleConstructorReturn(this, (TrainIndex.__proto__ || Object.getPrototypeOf(TrainIndex)).call(this, props));

    _this4.state = { name: "Weleocomcomcocmo" };

    // This binding is necessary to make `this` work in the callback
    return _this4;
  }

  _createClass(TrainIndex, [{
    key: "handleClick",
    value: function handleClick() {
      this.setState({ name: "Welcome!" });
    }
  }, {
    key: "render",
    value: function render() {
      return React.createElement(
        "div",
        null,
        React.createElement(Header, { title: this.state.name, handle: this.handleClick.bind(this) }),
        React.createElement(Footer, null)
      );
    }
  }]);

  return TrainIndex;
}(React.Component);

$(function () {
  ReactDOM.render(React.createElement(TrainIndex, null), document.getElementById("app"));
});