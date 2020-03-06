// D10(RX)  <-  TX
// D11(TX)  ->  RX

#include <SoftwareSerial.h>

// SoftwareSerial mySerial(2, 3); // RX, TX = D2, D3
SoftwareSerial mySerial(10, 11); // RX, TX = D10, D11

#define RW_DATA_MAX_SIZE 50
int readCnt;
char readData[RW_DATA_MAX_SIZE];
int sendCnt;
char sendData[RW_DATA_MAX_SIZE];


#define I2C_SLAVE_ADDR 0x40
#define CMD_READ_TEMP_HOLD 0xe3
#define CMD_SOFT_RESET 0xfe

// Write I2C: CMD_SOFT_RESET
#define LED_CMD_I2C_WRITE_SAMPLE_SIZE 4
const uint8_t i2CWriteDataSample[LED_CMD_I2C_WRITE_SAMPLE_SIZE] = {
  ((0x1D << 1) + 0),  // ADR1+W
  0x12,               // DATA0(Register Address:I2C1)
  I2C_SLAVE_ADDR,     // DATA1(I2C Slave Address)
  CMD_SOFT_RESET,     // DATA2(I2C Write Data0)
};

void setSendData(char *pSendData, uint8_t *src, uint8_t sendSize) {
    for(int i=0; i<sendSize; ++i) {
      pSendData[i] = src[i];
    }  
}

void setup() {

  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  Serial.println("Start Uart Command Sample");

  mySerial.begin(115200);

  readCnt = 0;
  sendCnt = 0;
}

/**
 * Serial Message(for debug)
 */
void SerialHexPrint(char n) {
  Serial.print("0x");
  if ( n >= 0 )Serial.print(n < 16 ? "0" : "");
  Serial.print((n & 0x000000FF), HEX);
}

void loop() {

  while (mySerial.available()) {
    // Serial.write(mySerial.read());
    int n = mySerial.read();
    readData[readCnt] = n;
    readCnt++;
  }
  if(readCnt > 0) {
    // print received data
    for(int i=0; i<readCnt; ++i) {
      int n = readData[i];
      SerialHexPrint(n);
      Serial.print(" ");
    }
    Serial.println(" :receive");
    readCnt = 0;
  }

  delay(3000);
  // set send data
  setSendData(&sendData[0], i2CWriteDataSample, LED_CMD_I2C_WRITE_SAMPLE_SIZE);
  sendCnt = LED_CMD_I2C_WRITE_SAMPLE_SIZE;

  // send
  if(sendCnt > 0) {
    for(int i=0; i<sendCnt; ++i) {
      mySerial.write(sendData[i]);
    }
    // print sent data
    for(int i=0; i<sendCnt; ++i) {
      int n = sendData[i];
      SerialHexPrint(n);
      Serial.print(" ");
    }
    Serial.println(" :send");
    sendCnt = 0;
  }

}

