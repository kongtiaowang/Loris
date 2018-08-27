class Upload extends React.Component {
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
   if (this.state.isLoaded) {
return (
    <div>
    {
        this.state.Data.map((item, i) => (
            <p key={i}>{item}</p>
        ))
    }
    </div>
      );
   } return (<p>loading</p>);
  }
}

export default Upload;

