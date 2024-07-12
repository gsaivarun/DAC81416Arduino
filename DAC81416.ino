/*<Authur: Gopala Krishnan B>
 * <Date: 25/05/2024>
 * <Version: 0.1>
 * 
 * The goal is to set voltage for DAC board 64 channel
 * 
 */
#include <SPI.h>
//DEFINE THE CHIP SELECT PIN
int CS_DAC0 =10;
int CS_DAC1 =9;
int CS_DAC2 =6;
int CS_DAC3 =5;



void setup() {
 SPI.beginTransaction(SPISettings(10, MSBFIRST, SPI_MODE1));
SPI.begin();                  // SPI Config 
Serial.begin(115200);        // Serial momitor congig with boardrate 

                             //PINMODE 
pinMode(CS_DAC0, OUTPUT);
pinMode(CS_DAC1, OUTPUT);
pinMode(CS_DAC2, OUTPUT);
pinMode(CS_DAC3, OUTPUT);
digitalWrite(CS_DAC0, HIGH);
digitalWrite(CS_DAC1, HIGH);
digitalWrite(CS_DAC2, HIGH);
digitalWrite(CS_DAC3, HIGH);

}

void loop() {

                             // DAC CHIP SELECT COLLECT USER INPUT 
                             
Serial.println("Select DAC CS(0/1/2/3)");
while(!Serial.available());
int DAC_CS_SEL=Serial.readString().toInt();
Serial.print("DAC Chip Select:");
Serial.println(DAC_CS_SEL);
Serial.println("        "); 

                           //SWITCH STATEMENT FOR CHIP SELEC

switch (DAC_CS_SEL){
  
  case 0:

    chip_cs(  CS_DAC0);
   
    break;
  case 1:
    chip_cs(CS_DAC1);
    
    break;
  case 2:
    chip_cs( CS_DAC2);
    break;
  case 3:
    chip_cs( CS_DAC3);
    break;
  default:
    Serial.println("Incorrect  CHIP SELECT Input");
}
}

                            //FUNCTION FOR CHIP SELECT AND DAC SET VOLTAGE
void chip_cs(int CSdac)
{
                            //FOR LOOP TO SELECT DAC 0 TO 16 
  for (int i=0; i<=15; i++)
  {
    
                            //DAC CHANNEL COLLECT USER INPUT  0 TO 16
    Serial.println("Select DAC 0 to 16" );
    while(!Serial.available());
    i=Serial.readString().toInt();
    Serial.print(" DAC:" );
    Serial.println(i);
    Serial.println("        ");

                              //DAC SET VOLTAGE COLLECT USER INPUT 0 TO 5V
    Serial.println("Set voltage for dac 0V to 5V" );
    while(!Serial.available());
    float Voltage=Serial.readString().toFloat();
    Serial.print("DAC Volltage is :" );
    Serial.println(Voltage);
    Serial.println("        ");

                             //DAC VOLTAGE CONVERSTION AND MSB AND LSB SHIFTING
    float DAC_SEL = i;                              
    unsigned int decimal =(Voltage*65535)/5;
    unsigned int MSB =(decimal >> 8) & 0xFF;      //MSB  SHIFTING
    unsigned int LSB =decimal & 0xFF;             //LSB SHIFTING
    const int gg[2][1] = {{MSB},{LSB}}; 

                             //DAC SPI TRANFER FUNCTION FOR EACH CHANNEL
            // DAC select 0
    if (DAC_SEL==0)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x10);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }
            // DAC select 1
    else if (DAC_SEL==1)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x11);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

            // DAC select 2
    else if (DAC_SEL==2)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x12);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

             // DAC select 3
     else if (DAC_SEL==3)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x13);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

             // DAC select 4
     else if (DAC_SEL==4)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x14);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

            // DAC select 5
    else if (DAC_SEL==5)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x15);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

            // DAC select 6
     else if (DAC_SEL==6)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x16);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        } 
            // DAC select 7
    else if (DAC_SEL==7)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x17);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

            // DAC select 8
    else if (DAC_SEL==8)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x18);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

             // DAC select 9
     else if (DAC_SEL==9)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x19);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

             // DAC select 10
     else if (DAC_SEL==10)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x1A);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

            // DAC select 11
    else if (DAC_SEL==11)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x1B);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

            // DAC select 12
     else if (DAC_SEL==12)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x1C);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH); 
        }

             // DAC select 13
     else if (DAC_SEL==13)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x1D);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

            // DAC select 14
    else if (DAC_SEL==14)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x1E);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH);
        }

            // DAC select 15
     else if (DAC_SEL==15)
        {
          digitalWrite(CSdac, LOW);
          SPI.transfer(0x1F);
          SPI.transfer(gg[0][0]);
          SPI.transfer(gg[0][0]);
          digitalWrite(CSdac, HIGH); 
        }     
     else 
        {
          Serial.println("Incorrect  DAC SELECT Input");
        }

                              //POWER UP DAC , SPI CONFIG, AND BROADCAST CONFIG SETUP

             //  SPI config
digitalWrite(CSdac, LOW );
SPI.transfer(0x03);
SPI.transfer(0x00);
SPI.transfer(0x84);
digitalWrite(CSdac, HIGH);

            // Power up all channels
digitalWrite(CSdac, LOW);
SPI.transfer(0x09);
SPI.transfer(0x00);
SPI.transfer(0x00);
digitalWrite(CSdac, HIGH);

            // Enable broadcast config all channels
digitalWrite(CSdac, LOW);
SPI.transfer(0x05);
SPI.transfer(0xFF);
SPI.transfer(0xFF);
digitalWrite(CSdac, HIGH);
}
}
