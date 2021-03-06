# ITS-IoT-2019-2021
Corso di IoT tenuto presso l'ITS-ICT di Torino.

Lezioni:
* [Lezione 1](#lez1)  
* [Lezione 2](#lez2)  
* [Lezione 3](#lez3)  
* [Lezione 4](#lez4)  
* [Lezione 5](#lez5)  
* [Lezione 6](#lez6)  
* [Lezione 7](#lez7)
* [Lezione 8](#lez8)   
* [Lezione 9](#lez9)   
* [Lezione 10](#lez10)   
* [Lezione 11](#lez11)   
* [Lezione 12](#lez12)   
* [Lezione 13](#lez13)   


### <a name="lez1"></a>Lezione 1

[Slide di riferimento](https://www.slideshare.net/davide.gomba/audizione-comune-di-torino-fablab-torino-officine-innesto)

#### Alcuni link emersi a lezione
* https://en.wikipedia.org/wiki/Long_tail
* https://it.wikipedia.org/wiki/Legge_di_Moore
* https://it.wikipedia.org/wiki/Cartello_Phoebus
* https://www.reddit.com/  
* https://news.ycombinator.com/
* https://nodered.org/
* https://cloud.ibm.com/login
* https://cloud.ibm.com/catalog/starters/node-red-starter
* (per chi ha W$) https://nodered.org/docs/getting-started/windows

La teoria delle pietre!

### <a name="lez2"></a>Lezione 2

Alcuni temi tratatti nella plennary introduttiva
* Design Fiction and Ethical Things → http://www.simonerebaudengo.com/project/ethicalthings
* Il Turco Meccanico → https://en.wikipedia.org/wiki/The_Turk
* Il servizio di amazon → https://www.mturk.com/

![](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fcdn.vox-cdn.com%2Fthumbor%2FgHsmW1ItL3qFDT2JB5qwaSHaRRY%3D%2F16x15%3A586x395%2F1200x800%2Ffilters%3Afocal(16x15%3A586x395)%2Fcdn.vox-cdn.com%2Fuploads%2Fchorus_image%2Fimage%2F44273352%2FTuerkischer_schachspieler_windisch4.0.0.jpg&f=1&nofb=1)

* Le slide di oggi sono [qui](https://docs.google.com/presentation/d/1Qne9nm0K6w9GlWtO4VBmqTo1pW4Y4vOILFlhFwAxFUk/edit#slide=id.p)
* Nodo Function by Steve Cope [Using the Node-Red Function Node - Beginners Guide](http://www.steves-internet-guide.com/node-red-functions/)
* Algoritmi di [PID](https://it.wikipedia.org/wiki/Controllo_PID)
* Come si fanno a fare i casting (cambiare una stringa in un numero o viceversa)? https://discourse.nodered.org/t/string-to-number/988

Prima chiamata ad una API, quella di [Madbob per GTT](https://gpa.madbob.org/). Flow [qui](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/madbob.json).

![](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/img/madbob.jpg)

### <a name="lez3"></a>Lezione 3 API

An application programming interface (API) is a computing interface which defines interactions between multiple software intermediaries. It defines the kinds of calls or requests that can be made, how to make them, the data formats that should be used, the conventions to follow, etc. It can also provide extension mechanisms so that users can extend existing functionality in various ways and to varying degrees.[1] An API can be entirely custom, specific to a component, or it can be designed based on an industry standard to ensure interoperability. Some APIs have to be documented, others are designed so that they can be "interrogated" to determine supported functionality. Since other components/systems rely only on the API, the system that provides the API can (ideally) change its internal details "behind" that API without affecting its users.

Source: https://en.wikipedia.org/wiki/Application_programming_interface

* [Magic](https://api.magicthegathering.io/v1/cards)
* [API Ryanair](https://developer.ryanair.com/discount-api/apis/get/3/discounts
)
* [Trenitalia](https://www.lefrecce.it/msite/api/solutions?origin=MILANO%20CENTRALE&destination=ROMA%20TERMINI&arflag=A&adate=20/12/2019&atime=17&adultno=1&childno=0&direction=A&frecce=false&onlyRegional=false
)
* [Le frecce](https://www.lefrecce.it/msite/api/geolocations/locations?name=%5BINIZIALE%5D)
* [API VALUTOMETRI](https://api.borsinopro.it/api-valutometri.html
)
* [OPEN WEATHERMAP](https://openweathermap.org/)
  + api.openweathermap.org/data/2.5/weather?q={city name}&appid={api token}
)
* [QR code](https://api.qrserver.com/v1/create-qr-code/?size=150x150&data=Example): cambia example con il dato

Parsiamo un json usando [jsonata](https://jsonata.org/)

### [OpenWeather Map APi example](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/openweathermap.json)
![](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/img/openweathermap.jpg)

### <a name="lez4"></a>Lezione 4 Dashboard

Reddit ci guarda!
https://www.reddit.com/r/ItalyInformatica/comments/el9xzf/api_e_basi_di_dati_interessanti_della_nostra_cara/

Abbiamo:
* [installato Node Red](https://nodered.org/docs/getting-started/windows
) sui nostri computer virtuali
* Abbiamo creato un account su github.com
* Abbiamo scaricato github desktop ([link al corso del 2016](https://github.com/OfficineArduinoTorino/ITS-Torino-2016
))
* Alternative a Github https://about.gitlab.com/
* [Slide Dashboard](https://github.com/OfficineArduinoTorino/ITS-Torino-2016
)

“Test” omnicomprensivo della dashboard → [flow](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/dashboard.json)

![](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/img/dashboard.jpg)

### <a name="lez5"></a>Lezione 5 HTTP request

* [Slide](https://docs.google.com/presentation/d/1ddfUe1JQnyBodSQE_kUE52xVkypsvLtywHwXT7ai86g/edit#slide=id.p).  
* Varie ed eventuali by Davide Prima SC di Davide:
https://webkay.robinlinus.com/

### <a name="lez6"></a>Lezione 6 HTTP request

Slide Lezione precedente.

Link e varie:
* [Infografica Cororavirus](https://gisanddata.maps.arcgis.com/apps/opsdashboard/index.html#/bda7594740fd40299423467b48e9ecf6)
* [Javascript e Node-RED - Tutorials](https://notenoughtech.com/home-automation/nodered-home-automation/nodered-for-beginners-6/)
* [Tutorial Javascript](https://javascript.info/)
* [Altri tutorial Javascript](https://www.codecademy.com/catalog/language/javascript)

(fare riferimento alla lezione)
![](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/img/api_addizione.PNG)

[Flow usato](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/api.json), qui di seguito alcune soluzioni dei compagni

La funzione di Riccardo (vers. 1)

```Javascript
x = 0;
y = 0;

x = msg.req.query.val1;
y = msg.req.query.val2;


var total = parseInt(x) + parseInt(y);


var msg1 = { payload:x };
var msg2 = { payload:y };
msg.payload = total;


return [msg, msg1, msg2];

}
```
La funzione di Gianpaolo (un solo output)

```Javascript
x = 0;
y = 0;

x = msg.req.query.val1;
y = msg.req.query.val2;


var total = parseInt(x) + parseInt(y);


x=x.toString();
y=y.toString();
msg.payload = {total,x,y};


return msg;

```

Calcolo del tempo mancante e aggiunta nell’array

```Javascript
// definisco una variabile tempo, ci passo il tempo datomi da simple time
var time = msg.mytime;

// splitto minuti e ore
var hour = time.split(":")[0];
var min = time.split(":")[1];


for (var i = 0; i < msg.payload.length; i++){

	var bus_min = msg.payload[i].hour.split(":")[1];
	var bus_hour = msg.payload[i].hour.split(":")[0];

	var delta_min = parseInt(bus_min) - parseInt(min);
	var delta_hour = parseInt(bus_hour) - parseInt(hour);

	msg.payload[i].ETA = delta_hour * 60 + delta_min;
}
return msg;

```

### <a name="lez7"></a>Lezione 7

Temi iniziali per parlare un po', link alle slides:
* [Berlin artist uses 99 phones to trick Google into traffic jam alert](https://www.theguardian.com/technology/2020/feb/03/berlin-artist-uses-99-phones-trick-google-maps-traffic-jam-alert)
* [link alle slides](https://www.theguardian.com/technology/2020/feb/03/berlin-artist-uses-99-phones-trick-google-maps-traffic-jam-alert)

### <a name="lez8"></a>Lezione 8

Iscriversi e fare (almeno) tutto il corso Basic Javascript di Freecodecamp.org (primo pezzo di “Javascript Algorithms and data Structures”)

https://www.freecodecamp.org/learn

### <a name="lez9"></a>Lezione 9

[Lampada Philips Hackerata](### <a name="lez8"></a>Lezione 8
)
[Slide: REST vs MQTT](https://docs.google.com/presentation/d/1JJfIOieeW-i4tcFvv8gb9dkrZZMkwvsttVugREIzl84/edit)
https://it.wikipedia.org/wiki/Insegnamento_capovolto

* [Installazione SQLite](https://www.youtube.com/watch?v=wXEZZ2JT3-k)
* [Node-Red Storing IOT data In a SQL Database
](https://www.youtube.com/watch?v=d8eeNROMTv0) flow → [qui](http://www.steves-internet-guide.com/download/store-iot-data-in-sqlite-database/)
* [nodi avanzati](https://www.youtube.com/watch?v=bovIZtgL68E&list=PLKYvTRORAnx6a9tETvF95o35mykuysuOw&index=3) flow → [qui](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/advanced-nodes.json)

### <a name="lez10"></a>Lezione 10

link vari:
* https://builders.mozilla.community/springlab/index.html
* https://docs.google.com/d🧧#CovidCreativesToolkit 🧧ocument/u/1/d/1iNPPgHO1bQFTey3U4G6LZ4pjb05iM0AyLGYA1We6W5c/mobilebasic?pli=1
* https://the-politics-of-covid-19.com/search/?size=n_30_n
* https://twitter.com/evgenymorozov
* https://en.wikipedia.org/wiki/Teledildonics

[slide lezione di oggi](https://docs.google.com/presentation/d/1GUsTC3KX0XQWJwTXbGSkv77btxqk9KHbiMvU6rcu8VE/edit#slide=id.g7283c3c763_0_127)

https://www.sqlitetutorial.net/sqlite-sample-database/

link al flow → [qui](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/ui_db.json)
![](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/img/ui_db.PNG)

### Esercitazione
Dovete andare [qua](https://github.com/OfficineArduinoTorino/ITS-IoT-2019-2021/wiki/Esercitazioni
) e completare la parte che vi é stata assegnata

### <a name="lez11"></a>Lezione 11

http://red-bot.io/

### Lecture di Guido Bellomo

* http://red-bot.io/
* https://chatfuel.com/
* https://dialogflow.com/

* Intent &  training
* NLP → Natural Language Processing
* https://github.com/axa-group/nlp.js?utm_source=gold_browser_extension

* Utterance = Espressioni della stessa frase

* Il training genera un modello

#### Concetti di usabilità  
L’utente potrebbe essere un po’ spaesato. Non lasciare l’utente mai una risposta o senza una direzione su cui deve fare. Ad ogni risposta dai sempre un informazione sul passaggio successivo

Alcuni chatbot chiedono dati. UX non lineare

Non usare mai un tono robotico

#### Pagamenti
* Telegram
* Facebook to be arriving
* Facebook Messenger
* Whatsapp [Storia Brasiliana](https://medium.com/@AlfredBaudisch/how-a-whatsapp-bot-got-famous-and-evolved-as-the-brazilian-wechat-and-conversational-commerce-e2213262183d
)

→ il [flow](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/guidone.json) di Guidone

### <a name="lez12"></a>Lezione 12

Link alle [slide](https://docs.google.com/presentation/d/1vOs3JQey6fQjYjwepzydUlLBuPa5Yh0T-FClut7s9gk/edit#slide=id.g747d9f4b5f_0_55)

### <a name="lez13"></a>Lezione 13

[“Projects”, Databases, Sensors, Bots, 🤯 ](https://docs.google.com/presentation/d/1LAmQOUgF34HA49EyXyRgnJauH0NL9NKQle5SpYKd_Ak/edit#slide=id.p)
