import ContactList from './ContactList';

let contacts = [{
    name: 'Trainer 1',
    phone: '555 555 1111'
    },
    {
    name: 'Trainer 2',
    phone: '555 555 2222'
    },
    {
    name: 'Trainer 3',
    phone: '555 555 3333'
    },
    {
    name: 'Trainer 4',
    phone: '555 555 4444'
    },
    {
    name: 'Trainer 5',
    phone: '555 555 5555'
    }
]

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
    
    handleFooter(){
       this.props.handleFooter();
    }

      render() {
       return (
        <div onClick={this.handleFooter.bind(this)}>
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
    handleFooterClick() {
    this.setState({name: "Welecomfdjsfljdsklfjdklsajfdklsjfkldsa!"});
  }
      render() {
       console.log(this.props.contacts);
       return (
        <div>
          <Header title={this.state.name} handle={this.handleClick.bind(this)} />
          <Footer handleFooter={this.handleFooterClick.bind(this)} />
          <ContactList contacts={this.props.contacts} />
        </div>
       );
      }
    
  }


$(function() {
  ReactDOM.render(<TrainIndex contacts={contacts} />, document.getElementById("app"));
});
