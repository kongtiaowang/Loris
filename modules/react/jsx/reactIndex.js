import React, {Component} from 'react';


class App extends Component {
constructor(props) {
    super(props);
    this.state = {
         list: [],
         searchValue: null,
    };
    this.removeItem = this.removeItem.bind(this);
    this.search = this.search.bind(this);
}

removeItem(id) {
const updatedList = this.state.list.filter((it) => it[14] !== id);
this.setState({list: updatedList});
}

search(event) {
this.setState(
   {
     searchValue: event.target.value,
   }
);
}

searching() {
}

  componentDidMount() {
    fetch('https://wangshen-dev.loris.ca/media/?format=json')
      .then((res) => res.json())
      .then(
        (result) => {
          this.setState({
            isLoaded: true,
            list: result.Data,
          });
        },
        // Note: it's important to handle errors here
        // instead of a catch() block so that we don't swallow
        // exceptions from actual bugs in components.
        (error) => {
          this.setState({
            isLoaded: true,
            error,
          });
        }
      );
  }

  render() {
      if (!this.state.list) {
return null;
}
    return (
      <div className="app">
      <Search content={this.state.searchValue} search={this.search}/>
      {
       this.state.list.map(
          (item) =>
          <div font="red" key={item[14]}>
            <h1><a>{item[0]}</a></h1>
            <h4>{item[2]}</h4>
            <BTN onClick={()=>this.removeItem(item[14])}>
               remove me
            </BTN>
          </div>
       )
      }
       </div>
    );
  }
}

class Search extends Component {
  render() {
    return (
       <form>
         <input type="text" name="first" onChange={this.props.search} />
         <button type="button" value="last" onClick={this.props.searching}>{this.props.content}</button>
       </form>
   );
  }
}
function BTN({onClick, children}) {
    return (
    <button onClick={ onClick }>
       { children }
    </button>
    );
}

$(function() {
  const reactIndex = (
    <div className='page-media'>
      <App/>
    </div>
  );

  ReactDOM.render(reactIndex, document.getElementById('lorisworkspace'));
});
