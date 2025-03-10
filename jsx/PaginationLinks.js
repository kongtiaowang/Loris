import React, {Component} from 'react';
import PropTypes from 'prop-types';

/**
 * Pagination component
 */
class PaginationLinks extends Component {
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  constructor(props) {
    super(props);

    this.state = {

    };
    this.changePage = this.changePage.bind(this);
  }

  /**
   * Called by React when the component is updated.
   *
   * @param {object} prevProps - Previous React Component properties
   */
  componentDidUpdate(prevProps) {
    if (this.props.Total < prevProps.Total) {
      this.props.onChangePage(1);
    }
  }

  /**
   * Creates an onClick Event Handler
   * execyting this.props.onChangePage(i)
   *
   * @param {number} i - Page index
   * @return {function(Event): void} - onClick Event Handler
   */
  changePage(i) {
    return function(evt) {
      // Don't jump to the top of the page
      evt.preventDefault();

      if (this.props.onChangePage) {
        this.props.onChangePage(i);
      }
    }.bind(this);
  }

  /**
   * Renders the React component.
   *
   * @return {JSX} - React markup for the component
   */
  render() {
    let rowsPerPage = this.props.RowsPerPage;
    let pageLinks = [];
    let classList;
    let lastPage = Math.ceil(this.props.Total / rowsPerPage);
    let startPage = Math.max(1, this.props.Active - 3);
    let lastShownPage = Math.min(this.props.Active + 3, lastPage);

    if (this.props.Total === 0) {
      return <div />;
    }
    if (this.props.Total < this.props.RowsPerPage) {
      return <div />;
    }

    if ((lastShownPage - startPage) <= 7) {
      lastShownPage = startPage + 6;
      if (lastShownPage > lastPage) {
        lastShownPage = lastPage;
        startPage = lastPage - 6;
      }
    }

    if (startPage > 1) {
      pageLinks.push(
        <li
          key={'table_page_beginning_' + startPage.toString()}
          onClick={this.changePage(1)}>
          <a href='#'>&laquo;</a>
        </li>
      );
    }
    if (startPage < 1) {
      startPage = 1;
    }
    if (lastShownPage < 1) {
      lastShownPage = 1;
    }

    // If there is only 1 page, don't display pagination links
    if (startPage === lastShownPage) {
      return <div />;
    }

    for (let i = startPage; i <= lastShownPage; i += 1) {
      classList = '';
      if (this.props.Active === i) {
        classList = 'active';
      }
      pageLinks.push(
        <li
          key={'table_page_' + i.toString()}
          onClick={this.changePage(i)}
          className={classList}
        >
          <a href="#">{i}</a>
        </li>
      );
    }
    if (lastShownPage !== lastPage) {
      pageLinks.push(
        <li
          key={'table_page_more_' + lastShownPage.toString()}
          onClick={this.changePage(lastPage)}
        >
          <a href='#'>&raquo;</a>
        </li>
      );
    }

    return (
      <ul className='pagination pagination-table'>
        {pageLinks}
      </ul>
    );
  }
}
PaginationLinks.propTypes = {
  onChangePage: PropTypes.func,
  Total: PropTypes.number.isRequired,
  RowsPerPage: PropTypes.number,
  Active: PropTypes.number,
};
PaginationLinks.defaultProps = {
  RowsPerPage: 10,
  Active: 1,
};

window.PaginationLinks = PaginationLinks;

export default PaginationLinks;
