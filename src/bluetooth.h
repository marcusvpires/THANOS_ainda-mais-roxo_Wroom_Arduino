#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void iniciaBluetooth () {
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("O modulo bluetooth esta pronto para conectar");
}