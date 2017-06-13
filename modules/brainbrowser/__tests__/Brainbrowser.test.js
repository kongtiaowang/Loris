import  Brainbrowser from '../jsx/Brainbrowser';

describe('Brainbrowser', () => {
    it('renders without crashing', () => {
        const div = document.createElement('div');
        ReactDOM.render(<Brainbrowser />, div);
    });
});
