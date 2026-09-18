#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

unsigned long lastPrint = 0;

void setup() {
  Serial.begin(9600);

  SPI.begin();
  rfid.PCD_Init();

  delay(200);

  rfid.PCD_AntennaOn();

  Serial.println("===== RC522 START =====");
  rfid.PCD_DumpVersionToSerial();
  Serial.println("Start scanning...");
}

void loop() {
  if (millis() - lastPrint >= 1000) {
    Serial.println("Scanning...");
    lastPrint = millis();
  }

  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  Serial.println(">>> CARD SIGNAL DETECTED <<<");

  // Select the card and print the detailed status if selection fails.
  MFRC522::StatusCode status = rfid.PICC_Select(&rfid.uid);

  if (status != MFRC522::STATUS_OK) {
    Serial.print("UID select failed: ");
    Serial.println(rfid.GetStatusCodeName(status));
    delay(500);
    return;
  }

  Serial.print("UID:");

  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }

  Serial.println();

  Serial.print("Card Type: ");
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  rfid.PICC_HaltA();

  delay(500);
}
