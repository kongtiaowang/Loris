/**
 * Document Upload Form
 *
 * Fetches data from Loris backend and displays a form allowing
 * to upload a doc file
 *
 * @author Shen Wang
 * @version 1.0.0
 *
 * */

class Tree extends React.Component {
  constructor(props) {
    super(props);
    this.state = {data: ['Root']};
  }

  componentDidMount() {
    this.fetchData();
  }

  fetchData() {
}
  render() {
const list = this.state.data.map((item) => (<div>{item} > </div>));
    return (
     <div>
      {list} <TreeNode /> {a} 
     </div>
    );
  }
}
export default Tree;

const numbers = [1, 2, 3, 4, 5];
class TreeNode extends React.Component {
  constructor(props) {
    super(props);
    this.state = {display:1};
  }
componentDidMount() {
}
handleClick(param, e) {
  console.log('Parameter', param);
  console.log('Event', e);
      this.setState({
      display: display+1,
    });
}
  render() {
const node = numbers.map((number, key) => (<div onClick={(e) => this.handleClick({number}, e)}>{number}</div>));
    return (
     <div>
      {node}
     </div>
    );
  }
}
