#include<Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into D1 on the ESP8266
#define ONE_WIRE_BUS D3

// A OneWire instance is created to communicate with the sensor
OneWire oneWire(ONE_WIRE_BUS);

// We connect the OneWire bus with the temperature sensor.
DallasTemperature sensors(&oneWire);

const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
float Acx, Acy, Acz, tmp, dispx, dispy, dispz;


void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  Serial.println("Starting to measure temperature...");
  sensors.begin();
}
void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 16 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  Acx = AcX / 16384.00 * 9.81;
  Acy = AcY / 16384.00 * 9.81;
  Acz = AcZ / 16384.00 * 9.81;
  tmp = Tmp / 340.00 + 4;

  Serial.print("Acx="); Serial.println(Acx);
  Serial.print("Acy="); Serial.println(Acy);
  Serial.print("Acz="); Serial.println(Acz);
  dispx = Acx * 0.04;
  dispy = Acy * 0.04;
  dispz = Acz * 0.04;
  Serial.print("displacement x="); Serial.println(dispx);
  Serial.print("displacement y="); Serial.println(dispy);
  Serial.print("displacement z="); Serial.println(dispz);
  Serial.print("Requesting temperature...");
  sensors.requestTemperatures(); // Send the command to get the temperature Serial.println("DONE");
  Serial.print("Temperaturel is: ");
  Serial.println(sensors.getTempCByIndex(0));
  delay(200);

}
