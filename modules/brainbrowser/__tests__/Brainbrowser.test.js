import React from 'react';
import  BrainBrowser from '../jsx/Brainbrowser';

describe('BrainBrowser', () => {
    it('renders without crashing', () => {
        const div = document.createElement('div');
        ReactDOM.render(<BrainBrowser />, div);
    });
});
