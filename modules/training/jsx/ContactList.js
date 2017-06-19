import Contact from "./Contact";
class ContactList extends React.Component {
  constructor(props) {
    super(props);
    this.state = {search: '',
                  searchphone:''};

    this.handleChange = this.handleChange.bind(this);
  }
    this.handleChangephone = this.handleChangephone.bind(this);
  }

  handleChange(event) {
    this.setState({search: event.target.value});
  }
  handleChangephone(event) {
    this.setState({searchphone: event.target.value});
  }

      render() {
       let filterContacts = this.props.contacts.filter(
           (contact) => {
               return contact.name.toLowerCase().indexOf(this.state.search.toLowerCase()) !== -1;
           }  
       );

       return (
        <div>
          <h1> Training List </h1>
          <ul>
             {filterContacts.map((contact)=> {
              return <Contact contact={contact} key={contact.name} />
             })}
          </ul>
          <input type="text" value={this.state.search} onChange={this.handleChange} />
          <input type="text" value={this.state.searchphone} onChange={this.handleChangephone} />
        </div>
       );
      }

  }
export default ContactList;
