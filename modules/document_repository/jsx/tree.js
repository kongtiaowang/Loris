/**
 * Document Upload Form
 *
 * Fetches data from Loris backend and displays a form allowing
 * to upload a doc file
 *
 * @author Shen Wang
 * @version 1.0.0
 *
 * */
const stylecss = {
    color: "red",
    background: "#0f0",
    fontSize: "32px"
}  

class Tree extends React.Component {
    constructor(props, context) {
        super(props, context);

        this.onMenuClicked = this.onMenuClicked.bind(this);
    }

    onMenuClicked(ev) {
        let node = $(ev.target);

        let subMenu = node.next();

        subMenu.css('display', subMenu.css('display') == 'none' ? 'block' : 'none');
    }

const stylecss = {
    color: "red",
    background: "#0f0",
    fontSize: "32px"
}
    generateMenu(menuObj) {
        let vdom = [];
        var timer = 1;

        if (menuObj instanceof Array) {
            let list = [];
            for (let item of menuObj) {
                list.push(this.generateMenu(item));
            }
            vdom.push(
                <ul key="single" style={styles}>
                    {list}
                </ul>
            );
        } else {
            vdom.push(
                <li key={menuObj.id}>
                    <h3 onClick={this.onMenuClicked}>
                        {menuObj.category_name}
                    </h3>
                    {this.generateMenu(menuObj.nodes)}
                </li>
            );
        }
        return vdom;
    }
    render() {
        let data =
[
{
id: '128',
category_name: 'c1',
parent_id: '0',
comments: null,
nodes: [
{
id: '130',
category_name: 'c11',
parent_id: '128',
comments: null,
nodes: [
{
id: '132',
category_name: 'c4',
parent_id: '130',
comments: null,
nodes: [
{
id: '135',
category_name: 'cate_5',
parent_id: '132',
comments: null,
nodes: [],
},
],
},
],
},
{
id: '131',
category_name: 'c12',
parent_id: '128',
comments: null,
nodes: [],
},
{
id: '140',
category_name: 'k1',
parent_id: '128',
comments: null,
nodes: [],
},
],
},
{
id: '129',
category_name: 'c2',
parent_id: '0',
comments: null,
nodes: [
{
id: '141',
category_name: 'ef',
parent_id: '129',
comments: null,
nodes: [],
},
{
id: '142',
category_name: 'fdsafdas',
parent_id: '129',
comments: null,
nodes: [],
},
],
},
{
id: '133',
category_name: 'ca4',
parent_id: null,
comments: null,
nodes: [
{
id: '134',
category_name: 'dddd',
parent_id: '133',
comments: null,
nodes: [],
},
],
},
{
id: '136',
category_name: 'c6',
parent_id: null,
comments: null,
nodes: [],
},
{
id: '137',
category_name: 'c6',
parent_id: null,
comments: null,
nodes: [],
},
{
id: '138',
category_name: 'c6',
parent_id: null,
comments: null,
nodes: [
{
id: '139',
category_name: 'c61',
parent_id: '138',
comments: null,
nodes: [],
},
],
},
];

        return (
            <div>
                {this.generateMenu(data)}
            </div>
        );
    }
}
export default Tree;
