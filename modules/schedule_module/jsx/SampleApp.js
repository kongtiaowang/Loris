import Modal from 'Modal';
import {Api} from "./Api";
import {FilterForm} from "./FilterForm";
import {EditForm} from "./EditForm";

const today = new Date();
const yesterday = new Date(today.getTime() - 24*60*60*1000);
const next30days = new Date(today.getTime() + 30 * 24*60*60*1000);
function zeroPad (str, length=2) {
    if (str.length >= length) {
        return str;
    }
    return "0".repeat(length-str.length) + str;
}
function toDateString (date) {
    const y = date.getFullYear();
    const m = zeroPad((date.getMonth()+1).toString());
    const d = zeroPad(date.getDate().toString());
    return `${y}-${m}-${d}`;
}
const tabs = [
    {
        label : "All",
        filters : {}
    },
    {
        label : "Past",
        filters : {
            StartDateMax : toDateString(yesterday)
        }
    },
    {
        label : "Next 30 Days",
        filters : {
            StartDateMin : toDateString(today),
            StartDateMax : toDateString(next30days)
        }
    },
];

export class SampleApp extends React.Component {
    constructor () {
        super();
        this.state = {
            candId : "",
            pscId : "",
            centerId : "",
            appointmentTypeId : "",
            startsAt : "",
            seen : "0",
            visitLabel : "",
            appointments : [],
            sites : [],
            visitLabels : [],
            appointmentTypes: [],
            open : {
                createAppointmentForm : false,
                editAppointmentForm : false,
            },
            tabIndex : 0,
        };
    
        this.openAppointmentForm = this.openAppointmentForm.bind(this);
        this.closeAppointmentForm = this.closeAppointmentForm.bind(this);
        this.openEditForm = this.openEditForm.bind(this);
        this.closeEditForm = this.closeEditForm.bind(this);
        this.fetchPage = this.fetchPage.bind(this);
        this.createAppointment = this.createAppointment.bind(this);
        this.setCurrAppointment = this.setCurrAppointment.bind(this)
        this.clearForm = this.clearForm.bind(this);
    }

    openAppointmentForm () {
            let open = this.state.open;
            open.createAppointmentForm = true;
            this.setState({
                open : open
            });        
    }

    closeAppointmentForm () {
            let open = this.state.open;
            open.createAppointmentForm = false;
            this.setState({
                open : open
            });
            this.clearForm();
    }    

    openEditForm () {
            let open = this.state.open;
            open.editAppointmentForm = true;
            this.setState({
                open : open
            });
    }
    
    closeEditForm () {
            let open = this.state.open;
            open.editAppointmentForm = false;
            this.setState({
                open : open
            });
    }

    setCurrAppointment (a) {
            let currAppointment = this.state.currAppointment;
            currAppointment = a;
            this.setState({currAppointment});
    }

    clearForm () {
        this.setState({
            candId : "",
            pscId : "",
            centerId : "",
            appointmentTypeId : "",
            startDate : "",
            startTime : "",
            seen : "0",
            visitLabel : "",
        });
    }
    
    createAppointment () {
        const body = [
            "CandID=" + encodeURIComponent(this.state.candId),
            "PSCID=" + encodeURIComponent(this.state.pscId),
            "CenterID=" + encodeURIComponent(this.state.centerId),
            "VisitLabel=" + encodeURIComponent(this.state.visitLabel),
            "AppointmentTypeID=" + encodeURIComponent(this.state.appointmentTypeId),
            "StartsAt=" + encodeURIComponent(this.state.startDate + " " + this.state.startTime + ":00"),
            "Seen=" + encodeURIComponent(this.state.seen),
        ].join("&");
        return fetch(
            "/schedule_module/ajax/create_appointment.php",
            {
                credentials : "include",
                method : "POST",
                body : body,
                headers : { "Content-Type":"application/x-www-form-urlencoded" }
            }
        ).then((res) => {
            return res.json()
                .then((data) => {
                    return {
                        status : res.status,
                        data : data,
                    };
                });
        }).then((result) => {
            console.log(result);
            if (result.status == 200) {
                this.setState({
                    appointments : this.state.appointments.concat(result.data)
                });
            } else {
                throw new Error(result.data.error);
            }
        });
    }

    fetchPage () {
        Api.getOrFetchSites()
            .then((data) => {
                this.setState({
                    sites : data
                });
            });
        Api.getOrFetchVisitLabels()
            .then((data) => {
                this.setState({
                    visitLabels : data
                });
            });
        Api.getOrFetchAppointmentTypes()
            .then((data) => {
                this.setState({
                    appointmentTypes : data
                });
            });
    }

    fetchTab (tabIndex) {
        if (tabIndex == undefined) {
            tabIndex = this.state.tabIndex;
        }
        Api.fetchAppointments(tabs[tabIndex].filters)
            .then((data) => {
                this.setState({
                    appointments : data
                });
            });
    }
    
    componentDidMount () {
        this.fetchPage();
        this.fetchTab();
    }

    render() {
        let createAppointmentButton;
        let editAppointmentButton;     
        
        createAppointmentButton = (
            <div className='Create Appointment Button'> 
            <button className="btn btn-default" onClick={this.openAppointmentForm}>
                <span className='glyphicon glyphicon-calendar'/> Create Appointment
            </button>
            <Modal
                title='Create Appointment'
                show={this.state.open.createAppointmentForm}
                closeModal={this.closeAppointmentForm}
                throwWarning= {true}
            >
            <div className="container-fluid">
                <div className="row">
                <div className="col-lg-6 col-md-6 col-sm-6">
                    <div className="form-group">
                        <label> DCCID: </label>
                        <br/>
                        <input type="text" defaultValue={this.state.candId} onChange={(e) => {
                        this.setState({
                            candId : e.target.value
                        });
                        }}/>
                    </div>
                    <div className="form-group">
                        <label> PSCID: </label>
                        <br/>
                        <input type="text" defaultValue={this.state.pscId} onChange={(e) => {
                        this.setState({
                            pscId : e.target.value
                        });
                        }}/>
                    </div>
                </div>
                <div className="col-lg-6 col-md-6 col-sm-6">
                    <div className="form-group">
                        <label> Appointment Date: </label>
                        <br/>
                        <input type="date" defaultValue={this.state.startDate} onChange={(e) => {
                        this.setState({
                            startDate : e.target.value
                        });
                        }}/>
                    </div>
                    <div className="form-group">
                        <label> Appointment Time: </label>
                        <br/>
                        <input type="time" defaultValue={this.state.startTime} onChange={(e) => {
                        this.setState({
                            startTime : e.target.value
                        });
                        }}/>
                    </div>
                </div>
                </div>
                <div className="row">
                <div className="col-lg-6 col-md-6 col-sm-6">
                    <div className="form-group">
                        <label> Appointment Site: </label>
                        <br/>
                        <select defaultValue={this.state.centerId} onChange={(e) => {
                        this.setState({
                            centerId : e.target.value
                        });
                        }}>
                        <option value="">- Select a Site -</option>
                        {   
                            this.state.sites.map((s) => {
                                return <option key={s.CenterID} value={s.CenterID}>{s.Name}</option>;          
                            })
                        }
                        </select>
                    </div>
                    <div className="form-group">
                        <label> Visit Label: </label>
                        <br/>
                        <select defaultValue={this.state.visitLabel} onChange={(e) => {
                        this.setState({
                            visitLabel : e.target.value
                        });
                        }}>

                        <option value="">- Select a Visit Label -</option>
                        {
                            this.state.visitLabels.map((s) => {
                                return <option key={s.Visit_label} value={s.Visit_label}>{s.Visit_label}</option>;
                            })
                        }
                        </select>
                    </div>
                </div>    
                <div className="col-lg-6 col-md-6 col-sm-6">
                    <div className="form-group">
                        <label> Type of Appointment: </label>
                        <br/>
                        <select defaultValue={this.state.appointmentTypeId} onChange={(e) => {
                        this.setState({
                            appointmentTypeId : e.target.value
                        });
                        }}>
                        <option value="">- Select an Appointment Type -</option>
                        {
                            this.state.appointmentTypes.map((s) => {
                                return <option key={s.AppointmentTypeID} value={s.AppointmentTypeID}>{s.Name}</option>;
                            })
                        }
                        </select>
                    </div>
                </div>    
                <br/>
                </div>
                <br/>
                <div className="buttoncent">
                    <button onClick={() => {
                        this.createAppointment()
                            .then(() => {
                                swal("Success!", "Appointment created!", "success");
                                this.closeAppointmentForm();
                            })
                            .catch((err) => {
                                swal("Unable to create appointment", err.message, "error");
                            });
                    }}>
                        Create
                    </button>
                </div>
            </div>
            </Modal>
        </div>
        );

        editAppointmentButton = (
            <div className='Edit Appointment'>
                <Modal
                    title='Edit Appointment'
                    show={this.state.open.editAppointmentForm}
                    closeModal={this.closeEditForm}
                    throwWarning= {true}
                >
                    <EditForm
                        appointment={this.state.currAppointment}
                        onEdit={(edited) => {
                            const appointments = this.state.appointments.slice();
                            const index = appointments.findIndex(item => item.AppointmentID == edited.AppointmentID);
                            appointments[index] = edited;
                            this.setState({
                                appointments : appointments,
                                toEdit : undefined,
                            });
                            swal("Success!", "Appointment updated!", "success");
                            this.closeEditForm();
                        }}
                        onError={(err) => {
                            swal("Unable to edit appointment", err.message, "error");
                        }}
                        onCancel={() => {
                            this.setState({
                                toEdit : undefined,
                            });
                            this.closeEditForm();
                        }}
                    />
                </Modal>
            </div>
        );

        return(
            <div>
                <FilterForm
                    onApply={(filters) => {
                        this.setState({
                            tabIndex : 0
                        });
                        Api.fetchAppointments(filters)
                            .then((data) => {
                                this.setState({
                                    appointments : data
                                });
                            });
                    }}
                    onClear={() => {
                        this.fetchTab();
                    }}
                />
                <h style={{margin : "10px"}}>
                {createAppointmentButton}
                </h>
                <br/>
                <ul className="nav nav-tabs" style={{margin : "10px"}}>
                    {
                        tabs.map((tab, index) => (
                            <li key={tab.label} className={this.state.tabIndex == index ? "active" : ""}>
                                <a href="#/" onClick={() => {
                                    this.setState({
                                        tabIndex : index
                                    });
                                    this.fetchTab(index);
                                }}>
                                    {tab.label}
                                </a>
                            </li>
                        ))
                    }
                </ul>
                <div className="table-responsive">
                    <table className="table table-striped table-hover">
                        <thead style={{backgroundColor : "#064785"}}>
                            <tr>
                                <th>
                                    DCCID
                                </th>
                                <th>
                                    PSCID
                                </th>
                                <th>
                                    Site
                                </th>
                                <th>
                                    Visit Label
                                </th>
                                <th>
                                    Starts At
                                </th>
                                <th>
                                    Appointment Type
                                </th>
                                <th>
                                    Seen
                                </th>
                                <th>
                                    Data Entered At
                                </th>
                                <th>
                                    Edit
                                </th>
                                <th>
                                    Delete
                                </th>
                            </tr>
                        </thead>
                        <tbody>
                            {
                                this.state.appointments.map((a, index) => {
                                    const site = this.state.sites.find(s => s.CenterID == a.CenterID);
                                    const appointmentType = this.state.appointmentTypes
                                        .find(at => at.AppointmentTypeID == a.AppointmentTypeID);
                                    return (
                                        <tr key={a.AppointmentID}>
                                            <td>
                                                {a.CandID}
                                            </td>
                                            <td>
                                                <a href={"/" + a.CandID + "/"}>{a.PSCID}</a>
                                            </td>
                                            <td>
                                                {
                                                    (site == undefined) ?
                                                        "Site #"+a.CenterID :
                                                        site.Name
                                                }
                                            </td>
                                            <td>
                                                {a.Visit_label}
                                            </td>
                                            <td>
                                                {a.StartsAt}
                                            </td>
                                            <td>
                                                {
                                                    (appointmentType == undefined) ?
                                                        "Appointment Type #"+a.AppointmentTypeID :
                                                        appointmentType.Name
                                                }
                                            </td>
                                            <td>
                                                {a.Seen == "0" ? "No" : "Yes"}
                                            </td>
                                            <td>
                                                {a.DataEntryAt}
                                            </td>
                                            <td>
                                                <button className="btn btn-default" onClick={() => 
                                                {this.openEditForm(); this.setCurrAppointment(a);}}>
                                                    <span className='glyphicon glyphicon-edit'/> Edit
                                                </button>
                                                {editAppointmentButton}
                                            </td>
                                            <td>
                                                <button className="btn btn-default" onClick={() => {
                                                swal({
                                                    title: "Are you sure you want to delete?",
                                                    text: "Appointments cannot be recovered",
                                                    type: "warning",
                                                    showCancelButton: true,
                                                    confirmButtonClass: "btn-danger",
                                                    confirmButtonText: "Yes, delete it!",  
                                                    cancelButtonText: "No, keep appointment!",
                                                    closeOnConfirm: false,
                                                    closeOnCancel: false
                                                    },
                                                    (isConfirm) => {
                                                    if (isConfirm) {
                                                    fetch(
                                                            "/schedule_module/ajax/delete_appointment.php?AppointmentID="+a.AppointmentID,
                                                            {
                                                                credentials : "include",
                                                                method : "DELETE",
                                                            }
                                                        ).then(() => {
                                                            const index = this.state.appointments.findIndex(item => item.AppointmentID == a.AppointmentID);
                                                            if (index < 0) {
                                                                return;
                                                            }
                                                            const appointments = this.state.appointments.slice();
                                                            appointments.splice(index, 1);
                                                            this.setState({
                                                                appointments : appointments
                                                            });
                                                    });
                                                    swal.close();
                                                    } else {
                                                    //swal("Canceled", "The appointment has not been deleted", "error");
                                                    swal.close();
                                                    }
                                                    });
                                                }}>
                                                    <span className='glyphicon glyphicon-trash'/> Delete
                                                </button>
                                            </td>
                                        </tr>
                                    );
                                })
                            }
                        </tbody>
                    </table>
                </div>
            </div>
        )
    }
}