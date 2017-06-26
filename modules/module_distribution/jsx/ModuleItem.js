class ModuleItem extends React.Component {

  constructor(props) {
    super(props);
  }

  render() {
      const data = this.props.ModuleItems;
      const item = data.map((module,index) =>
           (<div className="col-lg-4">
              <h2>{module.ModuleName}</h2> <h4>--{module.Author}</h4>

             {
               module.InstallState == '1'?
                 <div className="checkbox"> 
                           <label><input type="checkbox" value="" />enable</label>
                 </div>
                  : null
             }

              <p>{module.Description}</p>
             
             {
                module.InstallState == '0' ? 
              <p><a className="btn btn-success" href="#" type="button">Install</a></p>
              :
              <p><a className="btn btn-danger" href="#" type="button">Remove</a></p>
             }
            </div>)
      );
      return (
        <div>
                 {item}
        </div>
      );
    }

}
export default ModuleItem;
