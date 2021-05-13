import Customer from './Customer';
import SecurityQuestionAnswer from './SecurityQuestionAnswer';
import VaultTransitKey from './VaultTransitKey';

export const RouteConfig = [
    {
        category: 'Administrator',
        links: [
            {
                label: 'Customer',
                path: '/customer',
                component: Customer
            }, {
                label: 'Security Q & A',
                path: '/securityQuestionAnswer',
                component: SecurityQuestionAnswer
            }, {
                label: 'Vault Transit Key',
                path: '/vaultTransitKey',
                component: VaultTransitKey
            }
        ]
    }
];

export const RootUrl = window.location.protocol + '//' + window.location.hostname + ('https:' === window.location.protocol ? '' : (':' + window.location.port));
