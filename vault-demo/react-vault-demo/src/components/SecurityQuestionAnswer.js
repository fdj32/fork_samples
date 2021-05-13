import React, { Component } from 'react';
import { RootUrl } from './config';
import NProgress from 'nprogress';
import 'nprogress/nprogress.css';
import { Card, CardHeader, CardBody, Table, Row, Col, Input, Button } from 'reactstrap';

export default class SecurityQuestionAnswer extends Component {

    constructor(props) {
        super(props);
        let securityQuestionAnswers = [];
        if (props.securityQuestionAnswers) {
            securityQuestionAnswers = props.securityQuestionAnswers;
        }
        this.state = {
            securityQuestionAnswers: securityQuestionAnswers,
            filteredSecurityQuestionAnswers: securityQuestionAnswers,
            currentPage: 0,
            totalElements: 0,
            totalPages: 0,
            question: '',
            answer: '',
            customer: {
                id: null
            },
            sqas: []
        };
    }

    componentWillReceiveProps(nextProps) {
        this.setState({
            securityQuestionAnswers: nextProps.securityQuestionAnswers
        }, this.filterSecurityQuestionAnswers);
    }

    componentDidMount() {
        if (undefined === this.props.securityQuestionAnswers)
            this.viewPage(0);
    }

    viewPage = page => {
        NProgress.start();
        let url = RootUrl + "/apis/sqa/page/" + page;
        fetch(url).then(response => response.json()).then(data => {
            this.setState({
                securityQuestionAnswers: data.content,
                totalElements: data.totalElements,
                totalPages: data.totalPages,
                currentPage: page
            }, this.filterSecurityQuestionAnswers);
            NProgress.done();
        }).catch(error => {
            NProgress.done();
            console.log(error);
        });
    }

    handleChange = (event) => {
        this.setState({
            [event.target.name]: event.target.value
        }, this.filterSecurityQuestionAnswers);
    }

    who = c => {
        NProgress.start();
        let url = RootUrl + '/apis/customer/' + c.customer;
        fetch(url).then(response => response.json()).then(data => {
            this.setState({
                customer: data
            });
            let url2 = RootUrl + "/apis/sqa/customer/" + c.customer;
            fetch(url2).then(response2 => response2.json()).then(data2 => {
                this.setState({
                    sqas: data2
                });
                NProgress.done();
            }).catch(error2 => {
                NProgress.done();
                console.log(error2);
            });
        }).catch(error => {
            NProgress.done();
            console.log(error);
        });
    }

    clear = () => {
        this.setState({
            customer: {
                id: null
            }
        });
    }

    filterSecurityQuestionAnswers = () => {
        let filtered = this.state.securityQuestionAnswers.filter(i => {
            if ("" !== this.state.question && ("" + i.question).indexOf(this.state.question) === -1) {
                return false;
            }
            if ("" !== this.state.answer && ("" + i.answer).indexOf(this.state.answer) === -1) {
                return false;
            }
            return true;
        });
        this.setState({
            filteredSecurityQuestionAnswers: filtered
        });
    }

    render() {
        return 0 === this.state.securityQuestionAnswers.length ? '' : <Card className='m-1'>
            {
                undefined !== this.props.securityQuestionAnswers ? '' : <Row className="m-2">
                    <Col md={6}>
                        <Input type="text" className="form-control" name="question" placeholder="Question" onChange={this.handleChange} />
                    </Col>
                    <Col md={6}>
                        <Input type="text" className="form-control" name="answer" placeholder="Answer" onChange={this.handleChange} />
                    </Col>
                </Row>
            }
            {
                null === this.state.customer.id ? '' : <Card className='m-1'>
                    <CardHeader>
                        <div className="float-right">
                            <Button outline size="sm" color="danger" onClick={this.clear}>X</Button>
                        </div>
                    </CardHeader>
                    <CardBody>
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
                                <tr>
                                    <td>{this.state.customer.fname}</td>
                                    <td>{this.state.customer.lname}</td>
                                    <td>{this.state.customer.birth}</td>
                                    <td>{this.state.customer.weight}</td>
                                    <td>{this.state.customer.email}</td>
                                    <td>
                                        <ul>
                                            {this.state.sqas.map((sqa, i) => <li key={i}>{"Q: " + sqa.question + " A: " + sqa.answer}</li>)}
                                        </ul>
                                    </td>
                                </tr>
                            </tbody>
                        </Table>
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
                        <th scope="col">Question</th>
                        <th scope="col">Answer</th>
                        <th scope="col">Who</th>
                    </tr>
                </thead>
                <tbody>
                    {
                        this.state.filteredSecurityQuestionAnswers.map((c, i) => <tr key={i}>
                            <td>{c.question}</td>
                            <td>{c.answer}</td>
                            <td><Button outline size="sm" color="primary" onClick={() => this.who(c)}>Who</Button></td>
                        </tr>)
                    }
                </tbody>
            </Table>
        </Card>;
    }
}
