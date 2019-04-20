# Go_connect


The public transport always plays a crucial role in raising the economy of a nation.
We’ve come up with a solution to improve the transportation management system and addressed some of the drawbacks of the current system.
We aim to provide maximum security and a scheduled transport system.

The solutions involved the use of an RFID reader, RFID card, Mobile Application, GPS module, ESP8266.
The basic principle of the project is to send information to the Azure Cloud when the RFID reader is activated by the RFID card.
During the trip, the customer swipes/taps the card on the reader installed on the bus twice, once during the start of the trip
and second during the end of the trip. The location of the bus is consistently available for the viewer which is provided
by the GPS module installed in the RFID reader. These location data are extracted or co-ordinated for display on the Mobile
Application in a friendly manner using the MapMyIndia APIs. There is also pointing system similar to those of credit cards, points
are earned by taking trips and using the RFIDs provided. These points can be redeemed for various gift choices and credits.

This part of the project deals with the interface of rfid reader, esp8266 and firebase which is used as a server.
*****************************************************
