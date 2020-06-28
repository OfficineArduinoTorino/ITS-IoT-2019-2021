# ITS-IoT-2019-2021
Corso di IoT tenuto presso l'ITS-ICT di Torino.

Take me to [pookie](#pookie)
### <a name="pookie"></a>Some heading

Lezioni:
* [Lezione 1](#lez1)  
* [Lezione 2](#lez2)  
* [Lezione 3](#lez3)  
* [Lezione 4](#lez4)  
* [Lezione 5](#lez5)  
* [Lezione 6](#lez6)  
* [Lezione 7](#lez7)  


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

[Slide](https://docs.google.com/presentation/d/1ddfUe1JQnyBodSQE_kUE52xVkypsvLtywHwXT7ai86g/edit#slide=id.p).
Varie ed eventuali by Davide Prima SC di Davide:
https://webkay.robinlinus.com/

### <a name="lez6"></a>Lezione 6 HTTP request

Slide Lezione precedente.

Link e varie:
* [Infografica Cororavirus](https://gisanddata.maps.arcgis.com/apps/opsdashboard/index.html#/bda7594740fd40299423467b48e9ecf6)
* [Javascript e Node-RED - Tutorials](https://notenoughtech.com/home-automation/nodered-home-automation/nodered-for-beginners-6/)
* [Tutorial Javascript](https://javascript.info/)
* [Altri tutorial Javascript](https://www.codecademy.com/catalog/language/javascript)

(fare riferimento alla lezione)
![](https://raw.githubusercontent.com/OfficineArduinoTorino/ITS-IoT-2019-2021/master/img/api_addizione.PNG

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
