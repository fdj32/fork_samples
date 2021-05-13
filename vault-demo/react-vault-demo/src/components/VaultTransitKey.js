import React, { Component } from 'react';
import { RootUrl } from './config';
import NProgress from 'nprogress';
import 'nprogress/nprogress.css';
import { Card, ListGroup, ListGroupItem, Nav, NavItem, NavLink, TabContent, TabPane, Row, Col, CardHeader, CardBody, Button } from 'reactstrap';

export default class VaultTransitKey extends Component {

    constructor(props) {
        super(props);
        this.state = {
            key: null,
            customer: new Map(),
            sqa: new Map(),
            activeTab: 1
        };
    }

    componentDidMount() {
        this.getKey();
        this.statCustomer();
        this.statSqa();
    }

    toggle = tab => {
        if (this.state.activeTab !== tab) this.setState({
            activeTab: tab
        });
    }

    invoke = (uri, func) => {
        NProgress.start();
        let url = RootUrl + uri;
        fetch(url).then(response => response.json()).then(data => {
            func(data);
            NProgress.done();
        }).catch(error => {
            NProgress.done();
            console.log(error);
        });
    }

    getKey = () => {
        this.invoke("/apis/vault/transit/getKey", data => this.setState({ key: data }));
    }

    rotate = () => {
        this.invoke("/apis/vault/transit/rotate", data => this.setState({ key: data }));
    }

    statCustomer = () => {
        this.invoke("/apis/customer/stat", data => this.setState({ customer: data }));
    }

    rewrapCustomer = () => {
        this.invoke("/apis/customer/rewrap", data => this.setState({ customer: data }));
    }

    statSqa = () => {
        this.invoke("/apis/sqa/stat", data => this.setState({ sqa: data }));
    }

    rewrapSqa = () => {
        this.invoke("/apis/sqa/rewrap", data => this.setState({ sqa: data }));
    }

    generate = () => {
        this.invoke("/apis/faker/generate/11", data => {
            this.statCustomer();
            this.statSqa();
        });
    }

    render() {
        return <Card className='m-1'>
            <Card className='m-1 p-5'>
                <Row>
                    <Col md={3}>
                        <Button color="primary" onClick={this.rotate}>Rotate Key</Button>
                    </Col>
                    <Col md={3}>
                        <Button color="info" onClick={this.rewrapCustomer}>Rewrap Customer</Button>
                    </Col>
                    <Col md={3}>
                        <Button color="success" onClick={this.rewrapSqa}>Rewrap Security Q&A</Button>
                    </Col>
                    <Col md={3}>
                        <Button color="warning" onClick={this.generate}>Generate Data</Button>
                    </Col>
                </Row>
            </Card>
            {
                null === this.state.key ? '' : <Card className='m-1'>
                    <CardHeader>Vault Transit Key</CardHeader>
                    <CardBody>
                        <Nav vertical tabs>
                            <NavItem className="d-flex flex-row">
                                <NavLink className={this.state.activeTab === 1 ? "active bg-primary text-white" : ""} onClick={() => this.toggle(1)}>Details</NavLink>
                                <NavLink className={this.state.activeTab === 2 ? "active bg-primary text-white" : ""} onClick={() => this.toggle(2)}>Versions</NavLink>
                            </NavItem>
                            <TabContent activeTab={this.state.activeTab} className="p-3">
                                <TabPane tabId={1}>
                                    <Row>
                                        <Col md={3}>
                                            <ListGroup>
                                                <ListGroupItem>Name: {this.state.key.name}</ListGroupItem>
                                                <ListGroupItem>Cipher Mode: {this.state.key.cipher_mode}</ListGroupItem>
                                                <ListGroupItem>Type: {this.state.key.type}</ListGroupItem>
                                            </ListGroup>
                                        </Col>
                                        <Col md={3}>
                                            <ListGroup>
                                                <ListGroupItem>Derived: {this.state.key.derived ? "true" : "false"}</ListGroupItem>
                                                <ListGroupItem>Exportable: {this.state.key.exportable ? "true" : "false"}</ListGroupItem>
                                                <ListGroupItem>Deletion Allowed: {this.state.key.deletion_allowed ? "true" : "false"}</ListGroupItem>
                                            </ListGroup>
                                        </Col>
                                        <Col md={3}>
                                            <ListGroup>
                                                <ListGroupItem>Latest Version: v{this.state.key.latest_version}</ListGroupItem>
                                                <ListGroupItem>Min Decryption Version: v{this.state.key.min_decryption_version}</ListGroupItem>
                                                <ListGroupItem>Min Encryption Version: v{this.state.key.min_encryption_version}</ListGroupItem>
                                            </ListGroup>
                                        </Col>
                                        <Col md={3}>
                                            <ListGroup>
                                                <ListGroupItem>Supports Decryption: {this.state.key.supports_decryption ? "true" : "false"}</ListGroupItem>
                                                <ListGroupItem>Supports Encryption: {this.state.key.supports_encryption ? "true" : "false"}</ListGroupItem>
                                                <ListGroupItem>Supports Derivation: {this.state.key.supports_derivation ? "true" : "false"}</ListGroupItem>
                                                <ListGroupItem>Supports Signing: {this.state.key.supports_signing ? "true" : "false"}</ListGroupItem>
                                            </ListGroup>
                                        </Col>
                                    </Row>
                                </TabPane>
                                <TabPane tabId={2}>
                                    <ListGroup>
                                        {Object.keys(this.state.key.keys).map((p, i) => <ListGroupItem key={i}>{"v" + p + ": Created at " + new Date(this.state.key.keys[p] * 1000).toISOString()}</ListGroupItem>)}
                                    </ListGroup>
                                </TabPane>
                            </TabContent>
                        </Nav>
                    </CardBody>
                </Card>
            }
            {
                undefined === this.state.customer || null === this.state.customer ? '' : <Card className='m-1'>
                    <CardHeader>Customer Statistics</CardHeader>
                    <CardBody>
                        <ListGroup>
                            {Object.keys(this.state.customer).map((p, i) => <ListGroupItem key={i}>{p + ": " + this.state.customer[p] + " records"}</ListGroupItem>)}
                        </ListGroup>
                    </CardBody>
                </Card>
            }
            {
                undefined === this.state.sqa || null === this.state.sqa ? '' : <Card className='m-1'>
                    <CardHeader>Security Q&A Statistics</CardHeader>
                    <CardBody>
                        <ListGroup>
                            {Object.keys(this.state.sqa).map((p, i) => <ListGroupItem key={i}>{p + ": " + this.state.sqa[p] + " records"}</ListGroupItem>)}
                        </ListGroup>
                    </CardBody>
                </Card>
            }
        </Card>;
    }
}