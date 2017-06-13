import React from 'react';
import ReactDOM from 'react-dom';
import  Brainbrowser from '../jsx/Brainbrowser';

describe('Brainbrowser', () => {
    it('renders without crashing', () => {
        const div = document.createElement('div');
        ReactDOM.render(<Brainbrowser />, div);
    });
});
