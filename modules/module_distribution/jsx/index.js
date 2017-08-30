import Title from "./Title";
import ModuleList from "./ModuleList";
 const ModuleItems = [
         {ModuleName:'Instrument Manager',
          Author:'Superman',
          Description:'The Instrument Builder module is designed to create new behavioural forms on the database. Existing instruments that were created using the instrument builder can be added under the "Load Instrument (optional)" heading.',
          Version:'1.0',
          InstallState:'1'
         },
         {ModuleName:'Dicom Archive',
          Author:'Batman',
          Description:'The Dicom Archive module displays all scans that have been uploaded to LORIS, whether or not they have been inserted or not',
          Version:'1.0',
          InstallState:'0'
         },
         {ModuleName:'Help Editor',
          Author:'Wonder Woman',
          Description:'The content for any module can be edited by clicking on the Topic or Parent topic of choice.',
          Version:'1.0',
          InstallState:'0'
         },
         {ModuleName:'Ditor',
          Author:'Wonder Woman',
          Description:'The content for any module can be edited by clicking on the Topic or Parent topic of choice.',
          Version:'1.0',
          InstallState:'0'
         }
];

class Demo extends React.Component {

  render() {
      return (
        <div>
          <Title />
          <ModuleList ModuleItems={ModuleItems} />
        </div>
      );
    }

}

$(function() {

  ReactDOM.render(<Demo />, document.getElementById("lorisworkspace"));

});
