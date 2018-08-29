class DataTable extends React.Component {
  constructor(props) {
    super(props);
 }

  render() {
let a = this.props.Data;
    return (
 <div>
       { a.map((item, i) => (
          <div>
            <button key={i}>{item['File_name']}</button>
          </div>
        ))}
</div>
    );
    }
}

export default DataTable;
