import Contact from "./Contact";
class ContactList extends React.Component {

      render() {
       return (
        <div>
          <h1> Training List </h1>
          <ul>
             {this.props.contacts.map((contact)=> {
             //console.log("map loop");             
              return <Contact contact={contact} key={contact.name} />
              // return <li>eeee</li>
//https://www.youtube.com/watch?v=It9iL4EXFWc
             })}
          </ul>
        </div>
       );
      }

  }
export default ContactList;
