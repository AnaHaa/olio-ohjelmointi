# Tehtävänanto

Toteuta pieni, oliopohjainen datanhallintasovellus, jossa voit ylläpitää valitsemaasi dataa. Data voi olla esimerkiksi:

```bash
Kirjoja
Autoja
Veneitä
Kulkuvälineitä
tms..
```
Ajatuksena on, että itse dataa edustaa sille kirjoitettu sopiva luokka, jossa on ominaisuuksia. Luokasta voit myös periyttää uusia luokkia.<br />
Data voi olla säilöttynä esim. yksinkertaisessa vector -tietorakenteessa tai muussa C++:n standardikirjaston tarjoamassa tietorakenteessa.<br />

Itse ohjelma toimii yksinkertaisesti konsolisovelluksena. Konsolista käsin voit ainakin lisätä uusia, hakea, poistaa, muokata ja järjestää.<br />
Tiedostoon talletusta/hakua ei tarvitse toteuttaa, mutta testaamista varten voit toki luoda testitiedoston, jonka pohjalta voit luoda ohjelmaan sopivan datasisällön (yksinkertaisilla file-read -operaatioilla)<br />

## Vaatimuksia

Toteuta ohjelma hyödyntäen modernia C++:aa ja kurssilla läpi käytyjä asioita niin paljon kuin (tarkoituksenmukaisesti) mahdollista.<br />
Ohjelmassa tulisi käyttää sopivasti ja soveltaen mm. smart pointereita, sopivaa muistinhallintaa, lambda -lausekkeita (esim. haussa, järjestämisessä tai data-alkioiden muokkaamisessa),<br />
staattista dataa (esim. oliolaskurit). Lisäksi toteutuksessa on hyödynnettävä vähintään yhtä modernilla C++:lla toteutettua GoF design patternia, esimerkiksi tunneilla käytävä singleton tai observer.<br />
Muuten itse toteuttamistapa on vapaa.

## Ohjelma - Autokauppiaan apuri

Ohjelmalla voi luoda, hakea, poistaa, muokata ja järjestää erilaisia ajoneuvoja.<br />
Auto on olio, jossa on kaksi aliluokkaa - Moottori ja tiedot (Engine & Statistics).<br />

Auto luodaan ja annetaan tarvittava data:
Vehicle:
```bash
Merkki: string
Malli: string
Vuosimalli: int
```
Engine:
```bash
Litramäärä: float
Hevosvoimat: int
```
Statistics:
```bash
Ajetut kilometrit: int
Kulutus: float[kaupunki, maantie]
```

>Autoa voi muokata muuttamalla moottoria tai tietoja.
>Auton voi poistaa, joka poistaa koko olion.
>Autoa voi hakea merkin, mallin tai vuosiluvun mukaan.
>Vektoria voi lajitella vuosiluvun mukaan.
>Ohjelman päättyessä tieto poistetaan.

Esimerkkidataa testaukseen:
```bash
Merkki (string): Huyndai
Malli (string): I20
Vuosimalli (int): 2021
Litramaara (float): 1.6
Hevosvoimat (int): 120
Kaupunki kulutus (float): 5.8
Maantie kulutus (float): 4.6

Merkki (string): Volvo
Malli (string): 240
Vuosimalli (int): 1886
Litramaara (float): 2.1
Hevosvoimat (int): 90
Kaupunki kulutus (float): 8.4
Maantie kulutus (float): 6.2

Merkki (string): Toyota
Malli (string): Yaris
Vuosimalli (int): 2006
Litramaara (float): 1.6
Hevosvoimat (int): 100
Kaupunki kulutus (float): 7.8
Maantie kulutus (float): 5.4
```

>Sovellusta on testattu ja todettu toimivaksi kyseisillä esimerkeillä.