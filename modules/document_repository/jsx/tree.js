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
const numbers = ['two', 'three', 'four', 'five'];
const folder = ['Root1'];
class Tree extends React.Component {
  constructor(props) {
    super(props);
    this.state = {data: folder};
    this.handle = this.handle.bind(this);
  }

  handle(id) {
     const nodes = this.state.data;
     nodes.push(id);
     this.setState({data: nodes});
     console.log(this.state.data);
  }

  render() {
  const list = this.state.data.map((item, i) => (<p key={i} >{item} > </p>));
    return (
     <div>
      {list} <TreeNode click={this.handle}/>
     </div>
    );
  }
}
export default Tree;

class TreeNode extends React.Component {
  constructor(props) {
    super(props);
    this.state = {display: 1};
    this.click = this.props.click;
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
const node = numbers.map((number, index) => (<div onClick={()=>this.props.click(numbers[index])} key={index} >{number}</div>));
    return (
     <div>
      {node}
     </div>
    );
  }
}
