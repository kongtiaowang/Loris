import React, {Component} from 'react';
import list from './list';
class App extends Component {
constructor(props) {
    super(props);
    this.state = {
         list: list,
         searchValue: null,
    };
    this.remveItem = this.remveItem.bind(this);
    this.search = this.search.bind(this);
}

remveItem(id) {
const updatedList = this.state.list.filter((item) => item.id !== id);
this.setState({list: updatedList});
}
search(event) {
/* eslint-disable no-console */
// console.log(event);
this.setState(
   {
     searchValue: event.target.value,
   }
);
/* eslint-disable no-console */
console.log('YYYYYYY');
/* eslint-enable no-console */
/* eslint-enable no-console */
}

searching() {/* eslint-disable no-console */
console.log('xxxxxxxxxx');
/* eslint-enable no-console */
}

  render() {
/* eslint-disable no-console */
console.log(this);
/* eslint-enable no-console */
    return (
      <div className="app">
      <Search content={this.state.searchValue} search={this.search}/>
      {
       this.state.list.map(
          (item) =>
          <div key={item.id}>
            <h1><a>{item.url}</a></h1>
            <h4>{item.title}</h4>
//todo add params into searchnew
            <button type="button" onClick={()=>this.search}>remove</button>
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

$(function() {
/* eslint-disable no-console */
console.log(this);
/* eslint-enable no-console */
  const reactIndex = (
    <div className='page-media'>
      <App DataURL={`${loris.BaseURL}/media/?format=json`} />
    </div>
  );

  ReactDOM.render(reactIndex, document.getElementById('lorisworkspace'));
});
