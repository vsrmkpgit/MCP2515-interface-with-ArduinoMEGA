#include <SPI.h>          // For SPI communication
#include <mcp2515.h>      // for CAN communicatixon

#define potPin A0       // input pin for potientiometer
int potValue=0;         // SET pot initial value =0

struct can_frame canMsg;      // uses structure to store CAN frame-- variable is canMsg
// struct as 3 members---- can_id, can_dlc, data[8]
MCP2515 mcp2515(10);          // CS pin as D53

void setup() 
{
  Serial.begin(115200);     //begins serial communication at 11520 baud rate
  SPI.begin();              //begin SPI communication
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_250KBPS,MCP_8MHZ);       //sets CAN at speed 125Kbps and clock 8MHz
  mcp2515.setNormalMode();
  
 canMsg.can_id = 0x036;           // CAN id as 0x036 ---- members of struct
 canMsg.can_dlc = 1;              // CAN data length as 1 byte---- member of struct
}

void loop() 
{
  potValue = analogRead(potPin);                // read the pot values from analog pin A0
  potValue = map(potValue, 0, 1023, 0, 255);    // values read 0 to 1023 will be converted to 0 to 255      
  Serial.println(potValue);         //print the received pot values on serial monitor
  canMsg.data[0] = potValue;        //update potValue in [0]

  mcp2515.sendMessage(&canMsg);      //sends the CAN message
  delay(10);
}
