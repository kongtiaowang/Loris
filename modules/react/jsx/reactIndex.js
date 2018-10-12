import React, {Component} from 'react';

class App extends Component {
  render() {
    return (
       <h1>hello</h1>
    );
  }
}


$(function() {
  const reactIndex = (
    <div className='page-media'>
      <App DataURL={`${loris.BaseURL}/media/?format=json`} />
    </div>
  );

  ReactDOM.render(reactIndex, document.getElementById('lorisworkspace'));
});
