#include <Arduino.h>
#include <QTRSensors.h>

#include "BluetoothSerial.h"
#include "constantes.h"

QTRSensors qtr;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const uint8_t SensorCount = QTR_NumeroDeSensores;
uint16_t sensorValues[SensorCount];

void setup() {

  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){ 
    RS_1_PIN, RS_2_PIN, RS_3_PIN, RS_4_PIN, RS_5_PIN, RS_6_PIN, RS_7_PIN, RS_8_PIN
  }, SensorCount);
  qtr.setEmitterPin(QTR_EmitterPin);
  qtr.setTimeout(clock);

  Serial.begin(115200);

  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

}

void loop() {
  qtr.read(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    // Serial.print(sensorValues[i]);
    // Serial.print('\t');
  }
  // Serial.println();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }

  delay(20);
}