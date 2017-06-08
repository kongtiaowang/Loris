class Title extends React.Component {

      render() {
       return (
        <div>
          <h1> {this.props.title} </h1>
        </div>
       );
      }

  }

class Footer extends React.Component {

      render() {
       return (
        <div>
          This is a footer!
        </div>
       );
      }

  }
class Header extends React.Component {

      render() {
       return (
        <div>
          <Title title={this.props.title} />
          This is a Header!
        </div>
       );
      }

  }
  class TrainIndex extends React.Component {
     
      render() {
       return (
        <div>
          <Header title="nihao wow!!!"/>
          <Footer />
        </div>
       );
      }
    
  }


$(function() {
  ReactDOM.render(<TrainIndex />, document.getElementById("app"));
});
