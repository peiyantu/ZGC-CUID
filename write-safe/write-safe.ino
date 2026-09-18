#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define DATA_BLOCK 4

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

// A 16-byte test payload for a user data block.
byte testData[16] = {
  'Z', 'G', 'C', '-', 'C', 'U', 'I', 'D',
  ' ', 'T', 'E', 'S', 'T', ' ', ' ', ' '
};

void printHex(byte *buffer, byte length) {
  for (byte i = 0; i < length; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

bool isMifareClassic(MFRC522::PICC_Type type) {
  return type == MFRC522::PICC_TYPE_MIFARE_MINI ||
         type == MFRC522::PICC_TYPE_MIFARE_1K ||
         type == MFRC522::PICC_TYPE_MIFARE_4K;
}

void finishCardSession() {
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  Serial.println(F("===== SAFE DATA WRITER START ====="));
  Serial.println(F("Writes test data to MIFARE Classic data block 4."));
  Serial.println(F("This sketch does not modify the UID or Block 0."));
  Serial.println(F("Place an authorized test card near the RC522."));
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print(F("Card UID:"));
  printHex(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();

  MFRC522::PICC_Type piccType =
      mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.print(F("Card Type: "));
  Serial.println(mfrc522.PICC_GetTypeName(piccType));

  if (!isMifareClassic(piccType)) {
    Serial.println(F("This example requires a MIFARE Classic test card."));
    finishCardSession();
    delay(2000);
    return;
  }

  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
      MFRC522::PICC_CMD_MF_AUTH_KEY_A,
      DATA_BLOCK,
      &key,
      &(mfrc522.uid)
  );

  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    finishCardSession();
    delay(2000);
    return;
  }

  status = mfrc522.MIFARE_Write(DATA_BLOCK, testData, 16);

  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Write failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    finishCardSession();
    delay(2000);
    return;
  }

  Serial.println(F("Write successful."));

  byte readBack[18];
  byte readBackSize = sizeof(readBack);
  status = mfrc522.MIFARE_Read(DATA_BLOCK, readBack, &readBackSize);

  if (status == MFRC522::STATUS_OK) {
    Serial.print(F("Block 4 data:"));
    printHex(readBack, 16);
    Serial.println();
  } else {
    Serial.print(F("Read-back failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
  }

  finishCardSession();
  Serial.println(F("Remove the card before testing again."));
  Serial.println();
  delay(2000);
}
