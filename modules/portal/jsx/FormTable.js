/* eslint-disable */
import React from 'react';

export default function FormTable(props) {
  return (
    <div className="FormTable" id={props.name}>
      <table>
        <thead>
          <tr>
            {props.columns.map((col) => (
              <th key={col.id}>{col.label}</th>
            ))}
          </tr>
        </thead>
        <tbody>{props.rows}</tbody>
      </table>
    </div>
  );
}
