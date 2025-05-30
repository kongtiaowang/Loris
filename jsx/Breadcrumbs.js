/* exported RBreadcrumbs */

/**
 * This file contains React component for Breadcrumbs.
 *
 * @author Jordan Stirling
 * @author Alex Ilea
 * @author Jake Penny
 * @version 2.0.0
 */

import React, {Component} from 'react';
import PropTypes from 'prop-types';

/**
 * Breadcrumbs Component.
 * Used for navigation on all Loris pages.
 */
class Breadcrumbs extends Component {
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  constructor(props) {
    super(props);

    this.state = {
      displayCount: 0,
    };

    this.checkScreenSize = this.checkScreenSize.bind(this);
  }

  /**
   * Called by React when the component has been rendered on the page.
   */
  componentDidMount() {
    this.checkScreenSize();
    if (typeof window !== 'undefined') {
      window.addEventListener('resize', this.checkScreenSize);
    }
  }

  /**
   * Invoked immediately before a component is unmounted and destroyed.
   */
  componentWillUnmount() {
    if (typeof window !== 'undefined') {
      window.removeEventListener('resize', this.checkScreenSize);
    }
  }

  /**
   * Used to check to current window size and
   * sets the number of breadcrumbs to show
   */
  checkScreenSize() {
    const windowWidth = window.innerWidth;
    let displayCount = 4;

    if (windowWidth <= 425) {
      displayCount = 1;
    } else if (windowWidth <= 500) {
      displayCount = 2;
    } else if (windowWidth <= 767) {
      displayCount = 3;
    } else if (windowWidth > 885 && windowWidth <= 1350) {
      displayCount = 3;
    } else if (windowWidth > 1500) {
      displayCount = 5;
    }

    this.setState({
      displayCount: displayCount,
    });
  }

  /**
   * Renders the React component.
   *
   * @return {JSX} - React markup for the component
   */
  render() {
    const baseURL = this.props.baseURL;
    const breadcrumbs = [];
    const dropdown = [];
    let breadcrumbDropdown;

    // Loop through breadcrumbs either adding them to drop down
    // or displaying them
    for (let i = 0; i < this.props.breadcrumbs.length; i++) {
      const element = this.props.breadcrumbs[i];
      const url = baseURL + element.query;
      const onClick=this.props.breadcrumbs[i].onClick
        ? this.props.breadcrumbs[i].onClick
        : () => {};

      if (i < this.props.breadcrumbs.length - this.state.displayCount) {
        dropdown.push(
          <li key={'drop_' + i}>
            <a href={url} onClick={onClick}>
              {element.text}
            </a>
          </li>
        );
      } else {
        breadcrumbs.push(
          <a key={'crumb_' + i}
            href={url}
            className='btn btn-primary'
            onClick={onClick}>
            <div>
              {element.text}
            </div>
          </a>
        );
      }
    }

    if (dropdown.length !== 0) {
      breadcrumbDropdown = (
        <div className='btn-group ellipsis btn btn-primary'>
          <button type='button'
            className='dropdown-toggle'
            data-toggle='dropdown'
            aria-haspopup='true'
            aria-expanded='false'
          >
            ...
          </button>
          <ul className='dropdown-menu'>
            {dropdown}
          </ul>
        </div>
      );
    }

    return (
      <div id='bc2' className='btn-group btn-breadcrumb'>
        <a href={baseURL} className='btn btn-primary'>
          <span className='glyphicon glyphicon-home' aria-hidden='true'/>
        </a>
        {breadcrumbDropdown}
        {breadcrumbs}
      </div>
    );
  }
}

Breadcrumbs.propTypes = {
  baseURL: PropTypes.string,
  breadcrumbs: PropTypes.array,
};

window.Breadcrumbs = Breadcrumbs;

export default Breadcrumbs;
