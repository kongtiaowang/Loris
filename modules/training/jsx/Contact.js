class Contact extends React.Component {

      render() {
       return (
        <div>
             <li>
               <p>{this.props.contact.name} </p>
               <p>{this.props.contact.phone} </p>
             </li>
        </div>
       );
      }

  }
export default Contact;
