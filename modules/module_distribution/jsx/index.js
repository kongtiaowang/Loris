class Demo extends React.Component {

  render() {
      return (
        <div>
          <h1>hello world</h1>
        </div>
      );
    }

}

$(function() {

  ReactDOM.render(<Demo />, document.getElementById("lorisworkspace"));

});
