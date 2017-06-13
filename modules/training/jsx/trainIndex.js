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
    handle(){
       this.props.handle();
    }
      render() {
       return (
        <div>
          <Title title={this.props.title} />
         <p onClick={this.handle.bind(this)}> This is a Header!</p>
        </div>
       );
      }

  }
  class TrainIndex extends React.Component {
   constructor(props) {
    super(props);
    this.state = {name: "Weleocomcomcocmo"};

    // This binding is necessary to make `this` work in the callback
  } 
    handleClick() {
    this.setState({name: "Welcome!"});
  }
      render() {
       return (
        <div>
          <Header title={this.state.name} handle={this.handleClick.bind(this)} />
          <Footer />
        </div>
       );
      }
    
  }


$(function() {
  ReactDOM.render(<TrainIndex />, document.getElementById("app"));
});
