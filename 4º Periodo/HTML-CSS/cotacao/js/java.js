var request = new XMLHttpRequest();

const key ="3YR66YXJ7I8RDWIW";
//https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=XPCM11.SA&apikey="+key
//https://api.hgbrasil.com/finance/stock_price?key=60cbf0ac&symbol=bidi4
var teste2 = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=MXRF11.SA&apikey="+key;
    request.open('GET', teste2);
    request.responseType='json';
    request.send();
    request.onload = function(){
        var teste = request.response;
      
        console.log(teste["Global Quote"]); 
    } 

