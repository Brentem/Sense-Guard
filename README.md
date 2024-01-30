# Sense-Guard
De Sense-Guard is een product dat we gemaakt hebben om aan te tonen dat een kamer bezet of beschikbaar is.
We laten dit zien via een led matrix en led strips die rood kleuren als de kamer bezet is en groen als die beschikbaar is.
Je kan een kamer op bezet of beschikbaar zetten via de afstandbediening.

## Uitleg Folderstructuur
* Indication: Bevat code voor kastje dat beschikbaarheid van een kamer aangeeft.
* Remote: Bevat code voor de afstandbediening voor de Indication.
* DebugBluetooth: WinForms applicatie om bluetooth communicatie te testen voor Indication.

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
* Voor de Indication waarschijnlijk een snellere microcontroller gebruiken dan de Arduino Uno.