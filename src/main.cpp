#include <Arduino.h>
#include <QTRSensors.h>

#include "constantes.h"

QTRSensors qtr;

const uint8_t SensorCount = QTR_NumeroDeSensores;
uint16_t sensorValues[SensorCount];

void setup() {
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){ 
    RS_1_PIN, RS_2_PIN, RS_3_PIN, RS_4_PIN, RS_5_PIN, RS_6_PIN, RS_7_PIN, RS_8_PIN
  }, SensorCount);
  qtr.setEmitterPin(QTR_EmitterPin);
  qtr.setTimeout(clock);

  Serial.begin(9600);
}

void loop() {
  qtr.read(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();

  delay(250);
}