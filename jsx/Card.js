/**
 * This file contains React component for Card
 *
 * @author Zaliqa Rosli
 * @version 1.0.0
 */
import React, {Component} from 'react';
import PropTypes from 'prop-types';

import Panel from 'jsx/Panel';

/**
 * Card component - Wraps children in a customizable card
 *
 */
class Card extends Component {
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  constructor(props) {
    super(props);
    this.handleClick = this.handleClick.bind(this);
    this.state = {hasError: false};
  }

  static getDerivedStateFromError(error) {
    console.error(error);
    return {hasError: true};
  }
  /**
   * Delegate clicks on the card to the onClick handler
   *
   * @param {Event} e - The event triggering the click
   */
  handleClick(e) {
    if (this.props.onClick) {
      this.props.onClick(e);
    }
  }

  /**
   * Renders the React component.
   *
   * @return {JSX} - React markup for the component
   */
  render() {
    const cursorStyle = this.props.onClick ? {
      cursor: 'pointer',
    } : null;
    let divStyling = {
      marginLeft: '5px',
      marginRight: '5px',
      boxSizing: 'border-box',
    };
    if (this.props.style) {
      divStyling = {...divStyling, ...this.props.style};
    }
    if (this.props.cardSize) {
      divStyling.height = this.props.cardSize;
    }
    return (
      <div style={divStyling}>
        <Panel
          id={this.props.id}
          title={this.props.title}
          initCollapsed={this.props.initCollapsed}
          style={{overflow: 'auto'}}
          panelSize={this.props.cardSize}
          collapsing={this.props.collapsing}
        >
          <div
            onClick={this.handleClick}
            style={cursorStyle}
          >
            {this.state.hasError ? <div>
              <strong>Something went wrong rendering this panel.
                          Please open a bug report.</strong>
            </div>
              : this.props.children}
          </div>
        </Panel>
      </div>
    );
  }
}

Card.propTypes = {
  id: PropTypes.string.isRequired,
  title: PropTypes.string.isRequired,
  onClick: PropTypes.func,
  initCollapsed: PropTypes.bool,
  style: PropTypes.object,
  cardSize: PropTypes.string,
  children: PropTypes.node,
  collapsing: PropTypes.bool,
};

Card.defaultProps = {
  onClick: null,
  initCollapsed: false,
};

export default Card;
