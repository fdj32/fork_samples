import React, { Component } from 'react';
import { RootUrl } from './config';
import NProgress from 'nprogress';
import 'nprogress/nprogress.css';
import { Card, CardHeader, CardBody, Button, Table, Row, Col, Input, InputGroup, InputGroupText } from 'reactstrap';
import SecurityQuestionAnswer from './SecurityQuestionAnswer';

export default class Customer extends Component {

    constructor(props) {
        super(props);
        this.state = {
            customers: [],
            filterdCustomers: [],
            securityQuestionAnswers: [],
            currentPage: 0,
            totalElements: 0,
            totalPages: 0,
            birthAfter: null,
            birthBefore: null,
            weightMin: null,
            weightMax: null,
            name: '',
            email: ''
        };
    }

    componentDidMount() {
        this.viewPage(0);
    }

    viewPage = page => {
        NProgress.start();
        let url = RootUrl + '/apis/customer/page/' + page;
        fetch(url).then(response => response.json()).then(data => {
            this.setState({
                customers: data.content,
                totalElements: data.totalElements,
                totalPages: data.totalPages,
                currentPage: page
            }, this.filterCustomers);
            NProgress.done();
        }).catch(error => {
            NProgress.done();
            console.log(error);
        });
    }

    sqa = c => {
        let id = c.id;
        if (undefined === id) {
            let link = "";
            link = c._links.self.href;
            let lastSlashIndex = link.lastIndexOf("/");
            id = link.substring(lastSlashIndex + 1);
        }
        NProgress.start();
        let url = RootUrl + "/apis/sqa/customer/" + id;
        fetch(url).then(response => response.json()).then(data => {
            this.setState({
                securityQuestionAnswers: data
            });
            NProgress.done();
        }).catch(error => {
            NProgress.done();
            console.log(error);
        });
    }

    clear = () => {
        this.setState({
            securityQuestionAnswers: []
        });
    }

    handleChange = (event) => {
        this.setState({
            [event.target.name]: event.target.value
        }, this.filterCustomers);
    }

    filterCustomers = () => {
        let filtered = this.state.customers.filter(i => {
            if (null !== this.state.birthAfter && this.state.birthAfter > i.birth) {
                return false;
            }
            if (null !== this.state.birthBefore && this.state.birthBefore < i.birth) {
                return false;
            }
            if (null !== this.state.weightMin && this.state.weightMin > i.weight) {
                return false;
            }
            if (null !== this.state.weightMax && this.state.weightMax < i.weight) {
                return false;
            }
            if ("" !== this.state.name && (i.fname + " " + i.lname).indexOf(this.state.name) === -1) {
                return false;
            }
            if ("" !== this.state.email && ("" + i.email).indexOf(this.state.email) === -1) {
                return false;
            }
            return true;
        });
        this.setState({
            filterdCustomers: filtered
        });
    }

    render() {
        return 0 === this.state.customers.length ? '' : <Card className='m-1'>
            <Row className="m-2">
                <Col md={2}>
                    <Input type="date" className="form-control" name="birthAfter" placeholder="Birth After" onChange={this.handleChange} />
                </Col>
                <Col md={2}>
                    <Input type="date" className="form-control" name="birthBefore" placeholder="Birth Before" onChange={this.handleChange} />
                </Col>
                <Col md={2}>
                    <Input type="text" className="form-control" name="name" placeholder="Name" onChange={this.handleChange} />
                </Col>
                <Col md={2}>
                    <Input type="text" className="form-control" name="email" placeholder="Email" onChange={this.handleChange} />
                </Col>
                <Col md={2}>
                    <InputGroup>
                        <Input type="number" className="form-control" name="weightMin" placeholder="Weight Min" onChange={this.handleChange} />
                        <InputGroupText>kg</InputGroupText>
                    </InputGroup>
                </Col>
                <Col md={2}>
                    <InputGroup>
                        <Input type="number" className="form-control" name="weightMax" placeholder="Weight Max" onChange={this.handleChange} />
                        <InputGroupText>kg</InputGroupText>
                    </InputGroup>
                </Col>
            </Row>
            {
                0 === this.state.securityQuestionAnswers.length ? '' : <Card className='m-1'>
                    <CardHeader>
                        <div className="float-right">
                            <Button outline size="sm" color="danger" onClick={this.clear}>X</Button>
                        </div>
                    </CardHeader>
                    <CardBody>
                        <SecurityQuestionAnswer securityQuestionAnswers={this.state.securityQuestionAnswers} />
                    </CardBody>
                </Card>
            }
            {
                0 === this.state.totalPages || 1 === this.state.totalPages ? '' : <div className="my-2">
                    <nav>
                        <ul className="pagination justify-content-center">
                            {0 === this.state.currentPage ? '' : <li className="page-item"><button className="page-link" onClick={() => this.viewPage(0)}><span aria-hidden="true">&laquo;</span></button></li>}
                            {0 === this.state.currentPage ? '' : <li className="page-item"><button className="page-link" onClick={() => this.viewPage(this.state.currentPage - 1)}><span aria-hidden="true">&lsaquo;</span></button></li>}
                            {
                                [-3, -2, -1, 0, 1, 2, 3].map(i =>
                                    (i + this.state.currentPage) < 0 || (i + this.state.currentPage) >= this.state.totalPages ? '' : <li className={"page-item" + (0 === i ? " active" : "")}><button className="page-link" onClick={() => { if (i !== 0) this.viewPage(this.state.currentPage + i); }}>{i + 1 + this.state.currentPage}</button></li>
                                )
                            }
                            {this.state.totalPages === (this.state.currentPage + 1) ? '' : <li className="page-item"><button className="page-link" onClick={() => this.viewPage(this.state.currentPage + 1)}>&rsaquo;</button></li>}
                            {this.state.totalPages === (this.state.currentPage + 1) ? '' : <li className="page-item"><button className="page-link" onClick={() => this.viewPage(this.state.totalPages - 1)}>&raquo;</button></li>}
                        </ul>
                    </nav>
                </div>
            }
            <Table striped hover responsive>
                <thead>
                    <tr>
                        <th scope="col">First Name</th>
                        <th scope="col">Last Name</th>
                        <th scope="col">Birthday</th>
                        <th scope="col">Weight</th>
                        <th scope="col">Email</th>
                        <th scope="col">Security Q & A</th>
                    </tr>
                </thead>
                <tbody>
                    {
                        this.state.filterdCustomers.map((c, i) => <tr key={i}>
                            <td>{c.fname}</td>
                            <td>{c.lname}</td>
                            <td>{c.birth}</td>
                            <td>{c.weight}</td>
                            <td>{c.email}</td>
                            <td><Button outline size="sm" color="primary" onClick={() => this.sqa(c)}>Security Q & A</Button></td>
                        </tr>)
                    }
                </tbody>
            </Table>
        </Card>;
    }
}
