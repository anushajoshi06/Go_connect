/* RST  D3  [1*]        D3 [1*]
  SPI SS  SDA[3]        D8  [2*]
  SPI MOSI MOSI         D7
  SPI MISO MISO         D6
  SPI SCK SCK           D5
*/

#include <SPI.h>
#include <MFRC522.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define RST_PIN    D3
#define SS_PIN     D8
#define FIREBASE_HOST "first-c8a41.firebaseio.com"
#define FIREBASE_AUTH "1z44TRnf01X2nP4p9NAUD64COSZ8eIGnNXLKxpld"
#define WIFI_SSID "ujjwal"
#define WIFI_PASSWORD "ujjwal@123"

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  Serial.begin(9600);
  Serial.print("Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Put your card to the reader...");
  Serial.println();
}

String rfidTag_5;

void loop()
{
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message: ");
  Serial.println();
  content.toUpperCase();
  Serial.print(content);
  rfidTag_5 = content;
  Firebase.setString("Pune", rfidTag_5);
  delay(1000);
}
