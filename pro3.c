// CONFIG
#pragma config FOSC = HS       // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF        // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
//End of CONFIG registers

#define _XTAL_FREQ 20000000
#include<xc.h>

static int pin0=0;
static int pin1=0;
static int pin2=0;
static int pin3=0;
static int pin4=0;
static int pin5=0;
static int pin6=0;
static int pin7=0;
static int pin8=0;
static int pin9=0;



void Initialize_Bluetooth()
{
   //Set the pins of RX and TX//
    TRISC6=1;
    TRISC7=1;
    
  //Set the baud rate using the look up table in datasheet(pg114)//
    BRGH=1;      //Always use high speed baud rate with Bluetooth else it wont work
    SPBRG  =129;
    
    //Turn on Asyc. Serial Port//
    SYNC=0;
    SPEN=1;
    
    //Set 8-bit reception and transmission
    RX9=0;
    TX9=0;

   //Enable transmission and reception//
    TXEN=1; 
    CREN=1; 
    
    //Enable global and ph. interrupts//
    GIE = 1;
    PEIE= 1;
  
    //Enable interrupts for Tx. and Rx.//
    RCIE=1;
    TXIE=1;
}
//___________BT initialized_____________//

//Function to load the Bluetooth Rx. buffer with one char.//
void BT_load_char(char byte)  
{
    TXREG = byte;
    while(!TXIF);  
    while(!TRMT);
}
//End of function//

//Function to Load Bluetooth Rx. buffer with string//
void BT_load_string(char* string)
{
    while(*string)
    BT_load_char(*string++);
}
//End of function//

//Function to broadcast data from RX. buffer//
void broadcast_BT()
{
  TXREG = 13;  
  __delay_ms(500);
}
//End of function//

//Function to get a char from Rx.buffer of BT//
char BT_get_char(void)   
{
    if(OERR) // check for over run error 
    {
        CREN = 0;
        CREN = 1; //Reset CREN
    }
    
    if(RCIF==1) //if the user has sent a char return the char (ASCII value)
    {
    while(!RCIF);  
    return RCREG;
    }
    else //if user has sent no message return 0
        return 0;
}
//End of function/
void main(void)
{
    //Scope variable declarations//
    int get_value;
    //End of variable declaration//
   
    //I/O Declarations//
    TRISB0=0;
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    TRISB6=0;
    TRISB7=0;
    
    //I/O Declarations//
   
   Initialize_Bluetooth(); //lets get our bluetooth ready for action
    
   //Show some introductory message once on power up//
   BT_load_string("Bluetooth Initialized and Ready");
   broadcast_BT();
 
   //End of message//
    
    while(1) //The infinite lop
    {   
      get_value = BT_get_char();
      lighting(get_value);
        
  }
}







void lighting(char ch){
if (ch=='0')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=1; 
            RB4=1 ;
            RB5=1;
            RB6=1;
             
            
            if(pin0==0){
             BT_load_string("LED 0 turned OFF");
             broadcast_BT();
            RB7=1;
            pin0++;
            
            }else{
            
            BT_load_string("LED 0 turned ON");
            broadcast_BT();
            RB7=0;
            pin0=0;
            }
          }

          if (ch=='1')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=1; 
            RB4=1 ;
            RB5=1;
            RB6=0;
             
            
            if(pin1==0){
             BT_load_string("LED 1 turned OFF");
             broadcast_BT();
            RB7=1;
            pin1++;
            
            }else{
            
            BT_load_string("LED 1 turned ON");
            broadcast_BT();
            RB7=0;
            pin1=0;
            }
          }

          if (ch=='2')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=1; 
            RB4=1 ;
            RB5=0;
            RB6=1;
             
            
            if(pin2==0){
             BT_load_string("LED 2 turned OFF");
             broadcast_BT();
            RB7=1;
            pin2++;
            
            }else{
            
            BT_load_string("LED 2 turned ON");
            broadcast_BT();
            RB7=0;
            pin2=0;
            }
          }

          if (ch=='3')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=1; 
            RB4=1 ;
            RB5=0;
            RB6=0;
             
            
            if(pin3==0){
             BT_load_string("LED 3 turned OFF");
             broadcast_BT();
            RB7=1;
            pin3++;
            
            }else{
            
            BT_load_string("LED 3 turned ON");
            broadcast_BT();
            RB7=0;
            pin3=0;
            }
          }

          if (ch=='4')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=1; 
            RB4=0 ;
            RB5=1;
            RB6=1;
             
            
            if(pin4==0){
             BT_load_string("LED 4 turned OFF");
             broadcast_BT();
            RB7=1;
            pin4++;
            
            }else{
            
            BT_load_string("LED 4 turned ON");
            broadcast_BT();
            RB7=0;
            pin4=0;
            }
          }

          if (ch=='5')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=1; 
            RB4=0;
            RB5=1;
            RB6=0;
             
            
            if(pin5==0){
             BT_load_string("LED 5 turned OFF");
             broadcast_BT();
            RB7=1;
            pin5++;
            
            }else{
            
            BT_load_string("LED 5 turned ON");
            broadcast_BT();
            RB7=0;
            pin5=0;
            }
          }

          if (ch=='6')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=1; 
            RB4=0;
            RB5=0;
            RB6=1;
             
            
            if(pin6==0){
             BT_load_string("LED 6 turned OFF");
             broadcast_BT();
            RB7=1;
            pin6++;
            
            }else{
            
            BT_load_string("LED 6 turned ON");
            broadcast_BT();
            RB7=0;
            pin6=0;
            }
          }

          if (ch=='7')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=1; 
            RB4=0;
            RB5=0;
            RB6=0;
             
            
            if(pin7==0){
             BT_load_string("LED 7 turned OFF");
             broadcast_BT();
            RB7=1;
            pin7++;
            
            }else{
            
            BT_load_string("LED 7 turned ON");
            broadcast_BT();
            RB7=0;
            pin7=0;
            }
          }

          if (ch=='8')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=0; 
            RB4=1;
            RB5=1;
            RB6=1;
             
            
            if(pin8==0){
             BT_load_string("LED 8 turned OFF");
             broadcast_BT();
            RB7=1;
            pin8++;
            
            }else{
            
            BT_load_string("LED 8 turned ON");
            broadcast_BT();
            RB7=0;
            pin8=0;
            }
          }

          if (ch=='9')
          {
            RB0=1;
            RB1=1;
            RB2=1;
            RB3=0; 
            RB4=1;
            RB5=1;
            RB6=0;
             
            
            if(pin9==0){
             BT_load_string("LED 9 turned OFF");
             broadcast_BT();
            RB7=1;
            pin9++;
            
            }else{
            
            BT_load_string("LED 9 turned ON");
            broadcast_BT();
            RB7=0;
            pin9=0;
            }
          }
}