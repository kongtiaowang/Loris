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
    this.onSubmit = this.onSubmit.bind(this);
}

removeItem(id) {
const updatedList = this.state.list.filter((it) => it[14] !== id);
this.setState({list: updatedList});
}

onSubmit() {
   alert('99');
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
    return (
      <div className="app">
      <Search content={this.state.searchValue} onSubmit={this.onSubmit} />
      {
       this.state.list &&
       <Table list={this.state.list} removeItem={this.removeItem}/>
      }

      </div>
    );
  }
}

class Search extends Component {
  render() {
    return (
       <form onSubmit={this.props.onSubmit}>
         <input type="text" name="first" onChange={this.props.search} />
    <button type='submit'>
       do
    </button>
       </form>
   );
  }
}
class Table extends Component {
  render() {
  const {list, removeItem} = this.props;
    return (
     <div>
      {
       list.map(
          (item) =>
          <div font="red" key={item[14]}>
            <h1><a>{item[0]}</a></h1>
            <h4>{item[2]}</h4>
            <BTN onClick={()=>removeItem(item[14])}>
               remove me
            </BTN>
          </div>
       )
      }
      </div>
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
