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
    this.backNode = this.backNode.bind(this);
console.log(this.props.action);
  }

  handle(id) {
     const nodes = this.state.data;
     this.props.action(id);
     nodes.push(id);
     this.setState({data: nodes});
   //  console.log(this.state.data);
  }
  backNode(id) {
     if (id===0) {
       return;
     }
//   alert(this.state.data[id]);
const arr = this.state.data.slice(0, id);
console.log(arr);
this.setState({data: arr});

//   this.state.data = this.state.data.slice(0, id);
   //  const nodes = this.state.data;
   //  nodes.push(id);
   //  this.setState({data: nodes});
   //  console.log(this.state.data);
  }
  render() {
  const list = this.state.data.map((item, i) => (<span onClick={()=>this.backNode(i)} className="glyphicon glyphicon-folder-open">{item} ></span>));
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
const node = numbers.map((number, index) => (<span onClick={()=>this.props.click(numbers[index])} key={index} > {number} </span>));
    return (
     <span>
      {node}
     </span>
    );
  }
}
