#include <SPI.h>

// Include these libraries for using the RS-Software and Modbus functions
#include <SoftwareSerial.h>
#include <ModbusMasterSoftware.h>
#include <SPI.h>

// Instantiate ModbusMaster object as slave ID 1
ModbusMasterSoftware modbusMaster(1);

// Define one addres for reading
#define address 1

// Define the number of bytes to read
#define bytesQty 1

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  
  // Power on the USB for viewing data in the serial monitor
  Serial.begin(115200);
  delay(100);
  // Initialize Modbus communication baud rate
  modbusMaster.begin(9600);

  // Print hello message
  Serial.println("Modbus communication over RS-Software");
  delay(100);
}


void loop()
{
  // This variable will store the result of the communication
  // result = 0 : no errors
  // result = 1 : error occurred
  int result =  modbusMaster.readHoldingRegisters(address, bytesQty);

  if (result != 0) {
    // If no response from the slave, print an error message
    Serial.println("Communication error");
    delay(1000);
  }
  else {

    // If all OK
    Serial.print("Read value : ");

    // Print the read data from the slave
    Serial.print(modbusMaster.getResponseBuffer(0));
    delay(1000);
  }

  Serial.print("\n");
  delay(2000);

  // Clear the response buffer
  modbusMaster.clearResponseBuffer();

}





