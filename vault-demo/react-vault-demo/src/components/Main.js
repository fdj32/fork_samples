import React, { Component } from 'react';
import { RouteConfig } from './config';
import { HashRouter, Routes, Route } from "react-router-dom";
import NavTop from './NavTop';
import ErrorBoundary from './ErrorBoundary';

export default class Main extends Component {

    render() {

        let routes = RouteConfig.map((item, index) => {
            let links = item.links.map((linkItem, linkIndex) => {
                return <Route key={index * 100 + linkIndex} path={linkItem.path} element={linkItem.component} />
            });
            return links;
        });

        return <HashRouter>
            <NavTop />
            <ErrorBoundary>
                <Routes>
                    {routes}
                </Routes>
            </ErrorBoundary>
        </HashRouter>;
    }
}