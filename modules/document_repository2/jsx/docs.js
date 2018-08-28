class Docs extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      isLoaded: false,
      Data: {},
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
          isLoaded: true,
        });
      }.bind(this),
      error: function(error) {
        console.error(error);
      },
    });
  }


  render() {
    return (<p>docs ......{this.props.FileCate}</p>);
  }
}

export default Docs;
