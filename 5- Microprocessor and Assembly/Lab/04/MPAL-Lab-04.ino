#include <LiquidCrystal.h>
#include <Wire.h>

#define ADDR_Ax 0b000 //A2, A1, A0
#define ADDR (0b1010 << 3) + ADDR_Ax

// each line is defined as 10 bytes
int curr_line = 0;
char buffer[17] = {0};
char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

void eeprom_write(uint16_t memory_address, uint8_t* data, int _size);
void eeprom_read(uint16_t memory_address, uint8_t* data, int _size);

void readLineE2P()
{
  eeprom_read(curr_line * 16, buffer, 16);
  Serial.println(buffer);
}

void setup() {
  Wire.begin();        // join I2C bus (address optional for master)
  delay(50);
  //for(int i = i; i < 44; i++)
  //  eeprom_write(10*i, &text[10*i], 10);
  Serial.begin(9600);  // start serial for output
  //Serial.println(strlen(text));
  readLineE2P();
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}

void loop() {
  if(digitalRead(2)) //up button
  {
    curr_line++;
    readLineE2P();
    delay(1000);
  }
  if(digitalRead(3)) //down button
  {
    if(curr_line > 0)
      curr_line--;
    readLineE2P();
    delay(1000);
  }
}

void eeprom_write(uint16_t memory_address, uint8_t* data, int _size) {
  Wire.beginTransmission(ADDR);
  //Wire.write((uint8_t)((memory_address & 0xFF00) >> 8));
  Wire.write((uint8_t)((memory_address & 0x00FF) >> 0));
  for (int i = 0; i < _size; i++) {
    Wire.write(data[i]);
    //Serial.print("write: ");
    //Serial.println(data[i]);
  }
  Wire.endTransmission();
  delay(100);
}

void eeprom_read(uint16_t memory_address, uint8_t* data, int _size) {
  Wire.beginTransmission(ADDR);
  //Wire.write((uint8_t)((memory_address & 0xFF00) >> 8));
  Wire.write((uint8_t)((memory_address & 0x00FF) >> 0));
  Wire.endTransmission();

  Wire.requestFrom(ADDR, _size);
  for (int i = 0; i < _size; i++) {
    data[i] = Wire.read();
    //Serial.print("read: ");
    //Serial.println((byte)data[i]);
  }
}
