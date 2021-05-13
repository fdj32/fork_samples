import React, { Component } from 'react';
import { RouteConfig } from './config';
import {
    Navbar,
    NavbarBrand,
    Nav,
    NavLink,
    UncontrolledDropdown,
    DropdownToggle,
    DropdownMenu,
    DropdownItem
} from 'reactstrap';
import { Link } from 'react-router-dom';

export default class NavTop extends Component {
    render() {
        let navbar = RouteConfig.map((item, index) => {
            const dropdownlinks = item.links.map((linkItem, linkIndex) => {
                return <DropdownItem key={linkIndex}>
                    <Link className="btn btn-block text-left" to={linkItem.path}>{linkItem.label}</Link>
                </DropdownItem>;
            });
            return <UncontrolledDropdown nav inNavbar key={index}>
                <DropdownToggle nav caret><span className='text-light'>{item.category}</span></DropdownToggle>
                <DropdownMenu right>
                    {dropdownlinks}
                </DropdownMenu>
            </UncontrolledDropdown>;
        });
        return <div>
            <Navbar color="dark" light expand="md">
                <NavbarBrand href="/"><img src='Logo_Rev_4C-01.svg' alt='ActiveNetwork' /></NavbarBrand>
                <Nav className="ml-auto" navbar>
                    {navbar}
                    <NavLink className="nav-link" href="/logout"><span className='text-light'>Logout</span></NavLink>
                </Nav>
            </Navbar>
        </div>;
    }
}