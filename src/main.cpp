#include <Arduino.h>
#include <QTRSensors.h>

#include "constantes.h"
#include "bluetooth.h"

QTRSensors qtr;

const uint8_t SensorCount = QTR_NumeroDeSensores;
uint16_t sensorValues[SensorCount];

String message = "";
char incomingChar;

void setup() {

  // configura os sensores QTR
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){ 
    RS_1_PIN, RS_2_PIN, RS_3_PIN, RS_4_PIN, RS_5_PIN, RS_6_PIN, RS_7_PIN, RS_8_PIN
  }, SensorCount);
  qtr.setEmitterPin(QTR_EmitterPin);
  qtr.setTimeout(clock);

  Serial.begin(115200);

  iniciaBluetooth();
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }

  if (message =="on"){
    digitalWrite(LED_BUILTIN, HIGH);
    SerialBT.println("LED ligado"); 
  }
  else if (message =="off"){
    digitalWrite(LED_BUILTIN, LOW);
    SerialBT.println("LED desligado"); 
  }

  delay(20);
}