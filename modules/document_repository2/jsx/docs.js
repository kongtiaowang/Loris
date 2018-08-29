import DataTable from './dataTable';
class Docs extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      Loaded: false,
      Data: {},
      filter: {},
    };

  this.fetchData = this.fetchData.bind(this);
 }

  componentDidMount() {
    this.fetchData();
  }


  fetchData() {
    $.ajax(this.props.DataURL, {
      method: 'GET',
      dataType: 'json',
      success: function(data) {
        this.setState({
          Data: data,
          Loaded: true,
        });
      }.bind(this),
      error: function(error) {
        console.error(error);
      },
    });
  }


  render() {
    if (this.state.Loaded) {
    return (
       <div>
           <DataTable
            Data={this.state.Data}
           />
       </div>

    );
    } return (<p>Loading....</p>);
  }
}

export default Docs;
