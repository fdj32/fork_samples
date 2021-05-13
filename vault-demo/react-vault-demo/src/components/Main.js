import React, { Component } from 'react';
import { RouteConfig } from './config';
import { HashRouter, Switch, Route } from "react-router-dom";
import NavTop from './NavTop';
import ErrorBoundary from './ErrorBoundary';

export default class Main extends Component {

    render() {

        let routes = RouteConfig.map((item, index) => {
            let links = item.links.map((linkItem, linkIndex) => {
                return <Route key={index * 100 + linkIndex} path={linkItem.path} component={linkItem.component} />
            });
            return links;
        });

        return <HashRouter>
            <NavTop />
            <ErrorBoundary>
                <Switch>
                    {routes}
                </Switch>
            </ErrorBoundary>
        </HashRouter>;
    }
}