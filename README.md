# Sense-Guard
De Sense-Guard is een product dat we gemaakt hebben om aan te tonen dat een kamer bezet of beschikbaar is.
We laten dit zien via een led matrix en led strips die rood kleuren als de kamer bezet is en groen als die beschikbaar is.
Je kan een kamer op bezet of beschikbaar zetten via de afstandbediening.

## Uitleg Folderstructuur
* Indication: Bevat code voor kastje dat beschikbaarheid van een kamer aangeeft.
* Remote: Bevat code voor de afstandbediening voor de Indication.
* DebugBluetooth: WinForms applicatie om bluetooth communicatie te testen voor Indication.
* docs: Bevat documentatie voor code en hardware.
  * Drawio wordt gebruikt om de code te documenteren.
  * Fritzing wordt gebruikt om hardware diagrammen te maken.
  * KiCAD wordt gebruikt om elektrische schema's te maken.

## Benodigheden
* Visual Studio Code met PlatformIO extensie.
* Visual Studio --> DebugBluetooth
* Indication --> Arduino Uno
* Remote --> Arduino Nano

## Todo
* Bluetooth Communication Redundancy
  * Wat gebeurt er als de bluetooth verbinding wegvalt?
  * Wat gebeurt er als niet het hele bericht aankomt?
* [millis()](https://www.arduino.cc/reference/en/language/functions/time/millis/) rollover, na 50 dagen wordt de waarde gereset wat gebeurd er dan?
* Timer synchroniseren tussen Indication en Remote. Nu is er afwijking van ongeveer 2 seconden.
* Voor de Indication waarschijnlijk een snellere microcontroller gebruiken dan de Arduino Uno.

## Credits
* [Jop Wishaupt](https://www.linkedin.com/in/jop-wishaupt/)
* [Mats Horlings](https://www.linkedin.com/in/mats-horlings-70804125a/)
* [Lars Potters](https://www.linkedin.com/in/larspotters/)
* [Brent van de Pol](https://www.linkedin.com/in/brent-van-de-pol-4ab72826b/)