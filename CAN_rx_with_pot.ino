#include <SPI.h>
#include <mcp2515.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);     //Set the LCD address to 0x27 for a 16 chars and 2 line display
                                    //i2c addr and display size used to initiate object
struct can_frame canMsg;
MCP2515 mcp2515(53);      // CS pin as D53---object MCP2515

void setup() 
{
  lcd.begin();     //initialize i2c lcd
  lcd.backlight();      // Turn on the blacklight and print a message.
  // lcd.setCursor(1,0);
  //lcd.print("CAN Receiver...");
 // delay(1000);

  SPI.begin();              //begins SPI communication
  Serial.begin(115200);     //begins serial communication at 11520 baud rate
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_250KBPS,MCP_8MHZ);       //sets CAN at speed 125Kbps and clock 8MHz
  mcp2515.setNormalMode();
}

void loop() 
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)    //to receive data
  {
   if(canMsg.can_id==0x036)
    {
      int x = canMsg.data[0];
    Serial.println(x);
    lcd.setCursor(1,0);
    lcd.print("CAN Receiver...");
    lcd.setCursor(2,1);
    lcd.print("pot value");
    lcd.print(x);
    delay(10);
    }
  }
}
