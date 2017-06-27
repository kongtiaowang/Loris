import ModuleItem from "./ModuleItem";


class ModuleList extends React.Component {
  
  constructor(props) {
  super(props);

  this.state = {
      search: ""
    };


  }
     
  handleSearch(event) {
     console.log(event.target.value);
     this.setState({search:event.target.value});
  }

 
  render() {
      let FilterdModuleItems = this.props.ModuleItems.filter(
          (module) => {
             return module.ModuleName.toLowerCase().indexOf(this.state.search.toLowerCase()) !== -1;
          }     
          );
      const Item = FilterdModuleItems.map((module,index) =>
            {
               return <ModuleItem ModuleItem = {module} key={index} />
            }
      );
      return (
        <div> 
             <div className="row container">
                 <input type="text" className="left" name="search" placeholder="Search.." value={this.state.search} onChange={this.handleSearch.bind(this)} />
                 {Item}           
             </div>          
        </div>
      );
    }

}
export default ModuleList;
