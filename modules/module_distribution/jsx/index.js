import Title from "./Title";
import ModuleList from "./ModuleList";

class Demo extends React.Component {

  render() {
      return (
        <div>
          <Title />
          <ModuleList />
        </div>
      );
    }

}

$(function() {

  ReactDOM.render(<Demo />, document.getElementById("lorisworkspace"));

});
