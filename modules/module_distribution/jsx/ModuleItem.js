class ModuleItem extends React.Component {

  constructor(props) {
    super(props);
  }

  render() {
      const module = this.props.ModuleItem;    
      return (<div className="col-lg-4">
              <h3>{module.ModuleName}</h3>
             {
               module.InstallState == '1'?
                 <div className="checkbox pull-right"> 
                           <label><input type="checkbox" value="" />enable</label>
                 </div>
                  : null
             }
              <h5>--{module.Author}</h5> 
              <p>{module.Description}</p>
             {
                module.InstallState == '0' ? 
                <p><a className="btn btn-success" href="#" type="button">Install</a></p>
                :
                <p><a className="btn btn-danger" href="#" type="button">Remove</a></p>
              }
            </div>);
    }

}
export default ModuleItem 
