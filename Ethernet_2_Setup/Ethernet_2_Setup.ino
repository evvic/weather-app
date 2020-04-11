
//
//    Alyk  jatko course 2020       24.3.2020 KN
//    Voltage and freq mode 
//    Ethernet (1) module with W5100   / RED module


//MUST CONNECT THROUGH LAN PORT
//NOT WA

//REMOVED POTENTIOMETER


#include <LiquidCrystal.h>                            // include LCD library

#include <Ethernet2.h>             // include Ethernet libarty W5500 library
//Ethernet2.h is for our BLUE module with the W5500 chip

//#include <Ethernet.h>    // incluide Ethernet library W5100

//timer may not be needded till MQTT client is added
#include <TimerOne.h>      // include timer library


//                   RS  E   D4  D5  D6  D7
     LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
            // LCD pin wiring settings for MEGA

                                                      
EthernetClient ethClient;             // Ethernet object var  

void fetch_IP(void);
 
/////////////////////////////////////////////////////////////////////////////////////////////  
///           MAC nro                                                                      //
/// 
#define  mac_6    0x73 //73    ///     Last mac number  MSB mac numbers at ethernet_mega.c    ///
                           //      Not relevat with Ethershield  

//Our modified mac addy                           
static uint8_t mymac[6] =  { 0x44,0x76,0x58,0x10,0x00,0x73 }; //this works!

//mac address on forum
//static uint8_t mymac[6] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //basic MAC address random

//Original ref code mac address:
//static uint8_t mymac[6] = { 0x44,0x76,0x58,0x10,0x00,mac_6 };
                                                                                       ///

 
                           
////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///                               SETUP section
/// 
///////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);                                 // Serial monitor baudrate  = 9600

  
    lcd.begin(20,4);                                    // Display size defination 20 char  4 row
   
    lcd.setCursor(0,0);                                 // set curosor to left upper corner
    //         01234567890123456789
    lcd.print("24.3.2020 Alyk jatk ");                  // print to lCD 

    Serial.println("Start 24.3.2020");                   // print to serial monitor

 
    
      fetch_IP();                                         // initialize Ethernet connection
                                                          // get IP number from DHCP
  
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///
///                           LOOP section
///
///////////////////////////////////////////////////////////////////////////////////////////////////

void loop() 
{ }
  

//////////////////////////////////////////////////////////////////////////////////////////////
///
///    LOOP END
///
/////////////////////////////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////
//////
//////    Ethernet
//////
/////////////////////////////////////////////////
////////////////////////////////////////////////////////
///////////
///////////    Ethernet routines
///////////
///////////////////////////////////////////////////////

///////////////////////////////////////////
//////// GET IP number from DHCP server
//////////////////////////////////////////



void fetch_IP(void)
{
byte rev=1;



  lcd.setCursor(0,1);

  //         01234567890123456789  
  lcd.print("     Waiting IP     ");

  rev=Ethernet.begin( mymac);                  // get IP number


  //checking rev boolean status
  Serial.print("\nrev: ");
  Serial.print(rev);
     
  Serial.print( F("\nW5100 Revision ") );
    
  if ( rev == 0)
  {
                   
     Serial.println( F( "Failed to access Ethernet controller" ) );
                   
                                 // 0123456789012345689 
     lcd.setCursor(0,0); lcd.print(" Ethernet failed   ");
  }    
                 
              
     Serial.println( F( "Setting up DHCP" ));
     Serial.print("Connected with IP: "); 
     Serial.println(Ethernet.localIP()); 


  lcd.setCursor(0,1);
  //         012345678901234567890
  lcd.print("                     ");
  
  lcd.setCursor(0,1);
  lcd.print("myIP=");
  lcd.print(Ethernet.localIP());
  delay(1500);

  
}
