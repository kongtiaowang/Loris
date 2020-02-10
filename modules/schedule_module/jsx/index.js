import {App} from './App';

window.onload = () => {
    ReactDOM.render(
    <App
      dataURL={`${loris.BaseURL}/schedule_module/list_appointments`}
      hasPermission={true}
    />,
        document.getElementById('lorisworkspace')
    );
};
