/*global document, $*/

function download(filename, text) {
  let element = document.createElement("a");
  element.setAttribute(
    "href",
    "data:text/plain;charset=utf-8," + encodeURIComponent(text)
  );
  element.setAttribute("download", filename);

  element.style.display = "none";
  document.body.appendChild(element);

  element.click();

  document.body.removeChild(element);
}

function getDateTime() {
  const today = new Date();

  const date =
    today.getFullYear() + "-" + (today.getMonth() + 1) + "-" + today.getDate();

  const time =
    today.getHours() + "_" + today.getMinutes() + "_" + today.getSeconds();

  return date + "-" + time;
}

function loadingAlert() {
  let alert = document.getElementById("alert");
  alert.style.display = "block";
  alert.className = "alert alert-warning";
  alert.innerHTML = "Loading...";
}

function successAlert(fileName) {
  let alert = document.getElementById("alert");
  alert.className = "alert alert-success";
  alert.innerHTML = "Successfully downloaded " + fileName;
}

function getDirectDataReportEP() {
  loadingAlert();

  request = $.ajax({
    url: loris.BaseURL + "/statistics_ibis/ajax/getDirectDataEP.php",
    type: "get",
    dataType: "json",
    data: {},
    success: function (data) {
      let data1 = data["record1"];
      let data2 = data["record2"];

      const quote = (str) => {
        str = String(str);
        if (str.indexOf(`"`) > 0 || str.indexOf(",") > 0) {
          str = str.replace(/\"/g, `""`);
          return `"${str}"`;
        } else {
          return str;
        }
      };

      const line = [
        "Test_name",
        "Visit(s)",
        "Site",
        "Number of scheduled Behavioral appointments (A)",
        "n = Collected & Entered 'All' (B)",
        "n = Not collected & Entered 'None' (C)",
        "n = Partial data collected (D)",
        "n = Nothing entered (E)",
      ];

      let csv = [];
      csv.push(line.map(quote).join(","));

      const testNames = [
        "AIMS",
        "AOSI",
        "CSBS",
        "DJAA",
        "DSM_V",
        "ESCS",
        "Head Measurement",
        "Head Measurement - Proband",
        "Neuroscreen",
        "ADOS",
      ];

      for (let i = 0; i < 70; i++) {
        for (let j = 0; j < 20; j += 4) {
          let index = i % 10;
          let visit = "";
          let site = data1[i][j].Site;
          let apptCount = 0;

          if (i < 10) {
            visit = "V06";

            switch (site) {
              case "PHI":
                apptCount = data2[0][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[1][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[2][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[3][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[4][0].appointmentCount;
                break;
            }
          } else if (i < 20 && i >= 10) {
            visit = "V06-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[5][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[6][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[7][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[8][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[9][0].appointmentCount;
                break;
            }
          } else if (i < 30 && i >= 20) {
            visit = "V12";

            switch (site) {
              case "PHI":
                apptCount = data2[10][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[11][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[12][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[13][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[14][0].appointmentCount;
                break;
            }
          } else if (i < 40 && i >= 30) {
            visit = "V12-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[15][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[16][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[17][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[18][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[19][0].appointmentCount;
                break;
            }
          } else if (i < 50 && i >= 40) {
            visit = "V24";

            switch (site) {
              case "PHI":
                apptCount = data2[20][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[21][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[22][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[23][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[24][0].appointmentCount;
                break;
            }
          } else if (i < 60 && i >= 50) {
            visit = "V06, V06-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[25][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[26][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[27][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[28][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[29][0].appointmentCount;
                break;
            }
          } else if (i < 70 && i >= 60) {
            visit = "V12, V12-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[30][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[31][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[32][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[33][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[34][0].appointmentCount;
                break;
            }
          }

          //let adminNull = data1[i][j].n;
          let adminAll = data1[i][j + 1].n;
          let adminNone = data1[i][j + 2].n;
          let adminPartial = data1[i][j + 3].n;

          /*
          let totalVisits =
            Number(adminNull) +
            Number(adminAll) +
            Number(adminNone) +
            Number(adminPartial);
            */

          let adminUnknown =
            apptCount -
            (Number(adminAll) + Number(adminNone) + Number(adminPartial));

          let tmp = [
            testNames[index],
            visit,
            site,
            apptCount,
            adminAll,
            adminNone,
            adminPartial,
            adminUnknown,
          ]
            .map(quote)
            .join(",");

          csv.push(tmp);
        }
      }

      let fileName =
        "Statistics-Data-Entry-Direct-EP_" + getDateTime() + ".csv";

      download(fileName, csv.join("\n"));

      successAlert(fileName);

      // Removes the alert after 5000ms
      /*
      setTimeout(function () {
        alert.remove();
      }, 5000);
      */
    },
  });
}

function getDirectDataReportSA() {
  loadingAlert();

  request = $.ajax({
    url: loris.BaseURL + "/statistics_ibis/ajax/getDirectDataSA.php",
    type: "get",
    dataType: "json",
    data: {},
    success: function (data) {
      let data1 = data["record1"];
      let data2 = data["record2"];

      const quote = (str) => {
        str = String(str);
        if (str.indexOf(`"`) > 0 || str.indexOf(",") > 0) {
          str = str.replace(/\"/g, `""`);
          return `"${str}"`;
        } else {
          return str;
        }
      };

      const line = [
        "Test_name",
        "Visit(s)",
        "Site",
        "Number of scheduled Behavioral appointments (A)",
        "n = Collected & Entered 'All'  (B)",
        "n = Not collected & Entered 'None' (C)",
        "n = Partial data collected (D)",
        "n = Nothing entered (E)",
      ];

      let csv = [];
      csv.push(line.map(quote).join(","));

      const testNames = [
        "ADOS",
        "BOT2",
        "DAS",
        "DSM-IV",
        "DSM-V",
        "Interv hx",
        "MASC-2 Self",
        "mQST",
        "NIH-TB",
        "WIAT-III",
      ];

      for (let i = 0; i < 30; i++) {
        for (let j = 0; j < 16; j += 4) {
          let index = i % 10;
          let visit = "";
          let site = data1[i][j].Site;
          let apptCount = 0;

          if (i < 10) {
            visit = "VSA";

            switch (site) {
              case "PHI":
                apptCount = data2[0][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[1][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[2][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[3][0].appointmentCount;
                break;
            }
          } else if (i < 20 && i >= 10) {
            visit = "VSA-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[4][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[5][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[6][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[7][0].appointmentCount;
                break;
            }
          } else {
            visit = "VSA, VSA-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[8][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[9][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[10][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[11][0].appointmentCount;
                break;
            }
          }

          //let adminNull = data1[i][j].n;
          let adminAll = data1[i][j + 1].n;
          let adminNone = data1[i][j + 2].n;
          let adminPartial = data1[i][j + 3].n;

          /*
          let totalVisits =
            Number(adminNull) +
            Number(adminAll) +
            Number(adminNone) +
            Number(adminPartial);
            */

          let adminUnknown =
            apptCount -
            (Number(adminAll) + Number(adminNone) + Number(adminPartial));

          let tmp = [
            testNames[index],
            visit,
            site,
            apptCount,
            adminAll,
            adminNone,
            adminPartial,
            adminUnknown,
          ]
            .map(quote)
            .join(",");

          csv.push(tmp);
        }
      }

      let fileName =
        "Statistics-Data-Entry-Direct-SA_" + getDateTime() + ".csv";

      download(fileName, csv.join("\n"));

      successAlert(fileName);

      // Removes the alert after 5000ms
      /*
      setTimeout(function () {
        alert.remove();
      }, 5000);
      */
    },
  });
}

function getDirectDataReportDSInfant() {
  loadingAlert();

  request = $.ajax({
    url: loris.BaseURL + "/statistics_ibis/ajax/getDirectDataDSInfant.php",
    type: "get",
    dataType: "json",
    data: {},
    success: function (data) {
      let data1 = data["record1"];
      let data2 = data["record2"];

      const quote = (str) => {
        str = String(str);
        if (str.indexOf(`"`) > 0 || str.indexOf(",") > 0) {
          str = str.replace(/\"/g, `""`);
          return `"${str}"`;
        } else {
          return str;
        }
      };

      const line = [
        "Test_name",
        "Visit(s)",
        "Site",
        "Number of scheduled Behavioral appointments (A)",
        "n = Collected & Entered 'All' (B)",
        "n = Not collected & Entered 'None' (C)",
        "n = Partial data collected (D)",
        "n = Nothing entered (E)",
      ];

      let csv = [];
      csv.push(line.map(quote).join(","));

      const testNames = [
        "AIMS",
        "AOSI",
        "CSBS",
        "DSM_V",
        "ESCS",
        "Head Measurement",
        "Head Measurement - Proband",
        "Neuroscreen",
        "ADOS",
      ];

      for (let i = 0; i < 63; i++) {
        for (let j = 0; j < 20; j += 4) {
          let index = i % 9;
          let visit = "";
          let site = data1[i][j].Site;
          let apptCount = 0;

          if (i < 9) {
            visit = "V06";

            switch (site) {
              case "PHI":
                apptCount = data2[0][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[1][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[2][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[3][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[4][0].appointmentCount;
                break;
            }
          } else if (i < 18 && i >= 9) {
            visit = "V06-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[5][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[6][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[7][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[8][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[9][0].appointmentCount;
                break;
            }
          } else if (i < 27 && i >= 18) {
            visit = "V12";

            switch (site) {
              case "PHI":
                apptCount = data2[10][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[11][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[12][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[13][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[14][0].appointmentCount;
                break;
            }
          } else if (i < 36 && i >= 27) {
            visit = "V12-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[15][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[16][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[17][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[18][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[19][0].appointmentCount;
                break;
            }
          } else if (i < 45 && i >= 36) {
            visit = "V24";

            switch (site) {
              case "PHI":
                apptCount = data2[20][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[21][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[22][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[23][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[24][0].appointmentCount;
                break;
            }
          } else if (i < 54 && i >= 45) {
            visit = "V06, V06-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[25][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[26][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[27][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[28][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[29][0].appointmentCount;
                break;
            }
          } else if (i < 63 && i >= 54) {
            visit = "V12, V12-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[30][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[31][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[32][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[33][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[34][0].appointmentCount;
                break;
            }
          }

          //let adminNull = data1[i][j].n;
          let adminAll = data1[i][j + 1].n;
          let adminNone = data1[i][j + 2].n;
          let adminPartial = data1[i][j + 3].n;

          /*
          let totalVisits =
            Number(adminNull) +
            Number(adminAll) +
            Number(adminNone) +
            Number(adminPartial);
            */

          let adminUnknown =
            apptCount -
            (Number(adminAll) + Number(adminNone) + Number(adminPartial));

          let tmp = [
            testNames[index],
            visit,
            site,
            apptCount,
            adminAll,
            adminNone,
            adminPartial,
            adminUnknown,
          ]
            .map(quote)
            .join(",");

          csv.push(tmp);
        }
      }

      let fileName =
        "Statistics-Data-Entry-Direct-DS-Infant_" + getDateTime() + ".csv";

      download(fileName, csv.join("\n"));

      successAlert(fileName);

      // Removes the alert after 5000ms
      /*
      setTimeout(function () {
        alert.remove();
      }, 5000);
      */
    },
  });
}

function getDirectDDE_EP() {
  loadingAlert();

  request = $.ajax({
    url: loris.BaseURL + "/statistics_ibis/ajax/getDirectDDE_EP.php",
    type: "get",
    dataType: "json",
    data: {},
    success: function (data) {
      // console.log(data);

      let data1 = data["record1"];
      let data2 = data["record2"];

      const quote = (str) => {
        str = String(str);
        if (str.indexOf(`"`) > 0 || str.indexOf(",") > 0) {
          str = str.replace(/\"/g, `""`);
          return `"${str}"`;
        } else {
          return str;
        }
      };

      const line = [
        "Test_name",
        "Visit(s)",
        "Site",
        "Number of scheduled Behavioral appointments (A)",
        "n = Collected & Entered 'All', DDE Complete, and Valid",
      ];

      let csv = [];
      csv.push(line.map(quote).join(","));

      const testNames = [
        "AIMS",
        "AOSI",
        "CSBS",
        "DJAA",
        "DSM_V",
        "ESCS",
        "Head Measurement",
        "Head Measurement - Proband",
        "Neuroscreen",
        "ADOS",
      ];

      for (let i = 0; i < 70; i++) {
        for (let j = 0; j < 5; j++) {
          let index = i % 10;
          let visit = "";
          let site = data1[i][j].Site;
          let apptCount = 0;

          if (i < 10) {
            visit = "V06";

            switch (site) {
              case "PHI":
                apptCount = data2[0][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[1][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[2][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[3][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[4][0].appointmentCount;
                break;
            }
          } else if (i < 20 && i >= 10) {
            visit = "V06-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[5][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[6][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[7][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[8][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[9][0].appointmentCount;
                break;
            }
          } else if (i < 30 && i >= 20) {
            visit = "V12";

            switch (site) {
              case "PHI":
                apptCount = data2[10][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[11][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[12][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[13][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[14][0].appointmentCount;
                break;
            }
          } else if (i < 40 && i >= 30) {
            visit = "V12-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[15][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[16][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[17][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[18][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[19][0].appointmentCount;
                break;
            }
          } else if (i < 50 && i >= 40) {
            visit = "V24";

            switch (site) {
              case "PHI":
                apptCount = data2[20][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[21][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[22][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[23][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[24][0].appointmentCount;
                break;
            }
          } else if (i < 60 && i >= 50) {
            visit = "V06, V06-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[25][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[26][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[27][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[28][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[29][0].appointmentCount;
                break;
            }
          } else if (i < 70 && i >= 60) {
            visit = "V12, V12-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[30][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[31][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[32][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[33][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[34][0].appointmentCount;
                break;
            }
          }

          let n = data1[i][j].n;

          let tmp = [testNames[index], visit, site, apptCount, n]
            .map(quote)
            .join(",");

          csv.push(tmp);
        }
      }

      let fileName =
        "Statistics-Data-Entry-Direct-DDE-EP_" + getDateTime() + ".csv";

      download(fileName, csv.join("\n"));

      successAlert(fileName);
    },
  });
}

function getDirectDDE_SA() {
  loadingAlert();

  request = $.ajax({
    url: loris.BaseURL + "/statistics_ibis/ajax/getDirectDDE_SA.php",
    type: "get",
    dataType: "json",
    data: {},
    success: function (data) {
      let data1 = data["record1"];
      let data2 = data["record2"];

      console.log(data);

      const quote = (str) => {
        str = String(str);
        if (str.indexOf(`"`) > 0 || str.indexOf(",") > 0) {
          str = str.replace(/\"/g, `""`);
          return `"${str}"`;
        } else {
          return str;
        }
      };

      const line = [
        "Test_name",
        "Visit(s)",
        "Site",
        "Number of scheduled Behavioral appointments (A)",
        "n = Collected & Entered 'All', DDE Complete, and Valid",
      ];

      let csv = [];
      csv.push(line.map(quote).join(","));

      const testNames = [
        "ADOS",
        "BOT2",
        "DAS",
        "DSM-IV",
        "DSM-V",
        "Interv hx",
        "MASC-2 Self",
        "mQST",
        "NIH-TB",
        "WIAT-III",
      ];

      for (let i = 0; i < 30; i++) {
        for (let j = 0; j < 4; j++) {
          let index = i % 10;
          let visit = "";
          let site = data1[i][j].Site;
          let apptCount = 0;

          if (i < 10) {
            visit = "VSA";

            switch (site) {
              case "PHI":
                apptCount = data2[0][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[1][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[2][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[3][0].appointmentCount;
                break;
            }
          } else if (i < 20 && i >= 10) {
            visit = "VSA-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[4][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[5][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[6][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[7][0].appointmentCount;
                break;
            }
          } else {
            visit = "VSA, VSA-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[8][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[9][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[10][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[11][0].appointmentCount;
                break;
            }
          }

          let n = data1[i][j].n;

          let tmp = [testNames[index], visit, site, apptCount, n]
            .map(quote)
            .join(",");

          csv.push(tmp);
        }
      }

      let fileName =
        "Statistics-Data-Entry-Direct-DDE-SA_" + getDateTime() + ".csv";

      download(fileName, csv.join("\n"));

      successAlert(fileName);
    },
  });
}

function getDirectDDE_DSInfant() {
  loadingAlert();

  request = $.ajax({
    url: loris.BaseURL + "/statistics_ibis/ajax/getDirectDDE_DSInfant.php",
    type: "get",
    dataType: "json",
    data: {},
    success: function (data) {
      // console.log(data);

      let data1 = data["record1"];
      let data2 = data["record2"];

      const quote = (str) => {
        str = String(str);
        if (str.indexOf(`"`) > 0 || str.indexOf(",") > 0) {
          str = str.replace(/\"/g, `""`);
          return `"${str}"`;
        } else {
          return str;
        }
      };

      const line = [
        "Test_name",
        "Visit(s)",
        "Site",
        "Number of scheduled Behavioral appointments (A)",
        "n = Collected & Entered 'All', DDE Complete, and Valid",
      ];

      let csv = [];
      csv.push(line.map(quote).join(","));

      const testNames = [
        "AIMS",
        "AOSI",
        "CSBS",
        "DJAA",
        "DSM_V",
        "ESCS",
        "Head Measurement",
        "Head Measurement - Proband",
        "Neuroscreen",
        "ADOS",
      ];

      for (let i = 0; i < 63; i++) {
        for (let j = 0; j < 5; j++) {
          let index = i % 10;
          let visit = "";
          let site = data1[i][j].Site;
          let apptCount = 0;

          if (i < 10) {
            visit = "V06";

            switch (site) {
              case "PHI":
                apptCount = data2[0][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[1][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[2][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[3][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[4][0].appointmentCount;
                break;
            }
          } else if (i < 20 && i >= 10) {
            visit = "V06-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[5][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[6][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[7][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[8][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[9][0].appointmentCount;
                break;
            }
          } else if (i < 30 && i >= 20) {
            visit = "V12";

            switch (site) {
              case "PHI":
                apptCount = data2[10][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[11][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[12][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[13][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[14][0].appointmentCount;
                break;
            }
          } else if (i < 40 && i >= 30) {
            visit = "V12-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[15][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[16][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[17][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[18][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[19][0].appointmentCount;
                break;
            }
          } else if (i < 50 && i >= 40) {
            visit = "V24";

            switch (site) {
              case "PHI":
                apptCount = data2[20][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[21][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[22][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[23][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[24][0].appointmentCount;
                break;
            }
          } else if (i < 60 && i >= 50) {
            visit = "V06, V06-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[25][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[26][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[27][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[28][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[29][0].appointmentCount;
                break;
            }
          } else if (i < 70 && i >= 60) {
            visit = "V12, V12-CVD";

            switch (site) {
              case "PHI":
                apptCount = data2[30][0].appointmentCount;
                break;
              case "SEA":
                apptCount = data2[31][0].appointmentCount;
                break;
              case "STL":
                apptCount = data2[32][0].appointmentCount;
                break;
              case "UNC":
                apptCount = data2[33][0].appointmentCount;
                break;
              case "UMN":
                apptCount = data2[34][0].appointmentCount;
                break;
            }
          }

          let n = data1[i][j].n;

          let tmp = [testNames[index], visit, site, apptCount, n]
            .map(quote)
            .join(",");

          csv.push(tmp);
        }
      }

      let fileName =
        "Statistics-Data-Entry-Direct-DDE-DS-Infant_" + getDateTime() + ".csv";

      download(fileName, csv.join("\n"));

      successAlert(fileName);
    },
  });
}
