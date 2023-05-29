/* eslint-disable */
/* eslint-disable */
import React, { useEffect, useState } from 'react';
import CSSGrid from '../../../jsx/CSSGrid';
import swal from 'sweetalert2';
import 'regenerator-runtime/runtime'; 
/**
 * The main page
 *
 * @param props {object} - React props
 *
 * @return {ReactDOM}
 */
export function IndexPage(props) {
  const [CandID, setCandID] = useState(null);
  const [VisitLabel, setVisitLabel] = useState(null);
  const [cards, setCards] = useState([]);

  useEffect(() => {
    const urlParams = new URLSearchParams(window.location.search);
    const candID = urlParams.get('CandID');
    const visitLabel = urlParams.get('VisitLabel');

    if (candID && visitLabel) {
      setCandID(candID);
      setVisitLabel(visitLabel);
    }
  }, []);

  useEffect(() => {
    if (CandID === null || VisitLabel === null) {
      return;
    }
    let loadCards;

    const loadCandidate = async () => {
      try {
        const response = await fetch(
          `${props.BaseURL}/api/v0.0.3/candidates/${CandID}`
        );
        const data = await response.json();
          loadCards = props.loadCardsClosure(data, {
          CandID: CandID,
          VisitLabel: VisitLabel,
        });
        console.log('candidate', data);
        return data;
      } catch (error) {
        console.error(error);
        return null;
      }
    };

    const loadVisits = async (candidate) => {
      try {
        const visits = candidate.Visits.map(async (visit) => {
          const response = await fetch(
            `${props.BaseURL}/api/v0.0.3/candidates/${candidate.Meta.CandID}/${visit}`
          );
          const data = await response.json();
          return data;
        });
        console.log('visits', visits);
        return Promise.all(visits);
      } catch (error) {
        console.error(error);
        return [];
      }
    };

    loadCandidate()
      .then((candidate) => loadVisits(candidate))
      .then((visits) => {
        if (visits) {
          return loadCards(visits);
        }
        return [];
      })
      .then((cards) => {
        setCards(cards);
        console.log('cards', cards);
      })
      .catch((error) => {
        console.error(error);
      });
  }, [CandID, VisitLabel, props.BaseURL]);

  if (CandID === null || VisitLabel === null) {
    return <div><h1>Missing CandID or VisitLabel</h1></div>;
  }

  return <CSSGrid Cards={cards} />;
}

