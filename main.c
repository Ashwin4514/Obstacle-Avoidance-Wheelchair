#pragma config FNOSC = PRI // Oscillator Source Selection
(Internal Fast RC (FRC) Oscillator with postscaler)
#pragma config IESO = ON // Two-speed Oscillator Startup Enable bit (Start up device with FRC, then switch to user-selected
oscillator source)
#pragma config ICS=2
// FOSC
#pragma config POSCMD = HS // Primary Oscillator Mode
Select bits (HS Crystal Oscillator Mode)
#pragma config OSCIOFNC = ON // OSC2 Pin Function bit (OSC2
is general purpose digital I/O pin)
#pragma config FCKSM = CSDCMD // Clock Switching Mode bits
(Both Clock switching and Fail-safe Clock Monitor are disabled)
#pragma config PLLKEN = ON // PLL Lock Status Control (PLL
lock signal will be used to disable PLL clock output if lock is lost)
#pragma config XTCFG = G3 // XT Config (24-32 MHz
crystals)
#pragma config XTBST = ENABLE // XT Boost (Boost the kickstart)
#define FCY 16000000UL
#include <libpic30.h>
#include <p33CK256MP506.h>
#include "xc.h"
volatile unsigned short dataAN17;
volatile unsigned short dataAN18;
void init_uart(){
 U1MODEbits.UARTEN = 1;
 U1MODEbits.UTXEN = 1;
 U1MODEbits.USIDL = 1;
 U1MODEbits.BRGH = 0;
 U1BRG = 0x67;
 U1STAHbits.UTXISEL = 7;
 U1MODEHbits.BCLKSEL = 0;
 U1MODEHbits.HALFDPLX = 1;
}
void init_timer(){
 TMR1 = 0;

}
int main(void) {

 //US Sensor Setting Up
 T1CON = 0x0;
 T1CONbits.TECS = 3;
 T1CONbits.TCS = 1;
 PR1 = 0xFFFF;
 double count = 0;
 double time = 0;
 double frontDistance = 0;
 double count2 = 0;
 double time2 = 0;
 double backDistance = 0;
 double rightDistance =0 ;
 double count3 =0;
 double time3 =0;
 double leftDistance = 0;
 double count4 = 0;
 double time4 = 0;
 int keyValue0 = 0;
 int keyValue1 = 0;
 //taking key data
 //TRISDbits.TRISD3 = 1;
 //TRISDbits.TRISD4 = 1;

 //CLC
 ANSELBbits.ANSELB7=0;//CLC output pin
 ANSELDbits.ANSELD11=0;//CLCINDR input source4
 ANSELCbits.ANSELC0=0;//CLCINCR input source 3
 ANSELBbits.ANSELB9=0;//CLCINBR input source 2
 ANSELCbits.ANSELC1=0;//CLCINAR input source 1
 TRISBbits.TRISB7=0;
 TRISDbits.TRISD11=1;
 RPINR47bits.CLCINDR=75;
 TRISCbits.TRISC0=1;
 RPINR46bits.CLCINCR=48;
 TRISBbits.TRISB9=1;
 RPINR46bits.CLCINBR=41;
 TRISCbits.TRISC1=1;
 RPINR45bits.CLCINAR=49;
 CLC1CONLbits.LCEN=0;
 CLC1CONLbits.INTP=0;
 CLC1CONLbits.INTN=0;
 CLC1CONLbits.LCOE=1;
 CLC1CONLbits.LCOUT=1;
 CLC1CONLbits.LCPOL=1;
 CLC1CONLbits.MODE=2;
 CLC1CONHbits.G4POL=1;
 CLC1CONHbits.G3POL=1;
 CLC1CONHbits.G2POL=1;
 CLC1CONHbits.G1POL=1;
 CLC1SELbits.DS4=5;
 CLC1SELbits.DS3=0;
 CLC1SELbits.DS2=0;
 CLC1SELbits.DS1=0;
 CLC1GLSLbits.G2D4T=1;
 CLC1GLSLbits.G2D4N=0;
 CLC1GLSLbits.G2D3T=1;
 CLC1GLSLbits.G2D3N=0;
 CLC1GLSLbits.G2D2T=1;
 CLC1GLSLbits.G2D2N=0;
 CLC1GLSLbits.G2D1T=1;
 CLC1GLSLbits.G2D1N=0;
 CLC1GLSLbits.G1D4T=1;
 CLC1GLSLbits.G1D4N=0;
 CLC1GLSLbits.G1D3T=1;
 CLC1GLSLbits.G1D3N=0;
 CLC1GLSLbits.G1D2T=1;
 CLC1GLSLbits.G1D2N=0;
 CLC1GLSLbits.G1D1T=1;
 CLC1GLSLbits.G1D1N=0;
 CLC1GLSHbits.G4D4T=1;
 CLC1GLSHbits.G4D4N=0;
 CLC1GLSHbits.G4D3T=1;
 CLC1GLSHbits.G4D3N=0;
 CLC1GLSHbits.G4D2T=1;
 CLC1GLSHbits.G4D2N=0;
 CLC1GLSHbits.G4D1T=1;
 CLC1GLSHbits.G4D1N=0;
 CLC1GLSHbits.G3D4T=1;
 CLC1GLSHbits.G3D4N=0;
 CLC1GLSHbits.G3D3T=1;
 CLC1GLSHbits.G3D3N=0;
 CLC1GLSHbits.G3D2T=1;
 CLC1GLSHbits.G3D2N=0;
 CLC1GLSHbits.G3D1T=1;
 CLC1GLSHbits.G3D1N=0;

 //SENSOR 3//left
 TRISBbits.TRISB8 = 0;// MISO1
 ANSELBbits.ANSELB8 = 0;
 TRISCbits.TRISC12 = 1;//PWM2
 //SENSOR1//forward
 ANSELBbits.ANSELB2 = 0;
 TRISBbits.TRISB2 = 0;//CS1
 TRISCbits.TRISC14 = 1;//INT1
 //SENSOR2//back
 TRISCbits.TRISC3 = 0;//CS2
 ANSELCbits.ANSELC3 = 0;
 TRISCbits.TRISC15 = 1;//RX1
 //SENSOR4//right
 TRISCbits.TRISC7 = 0;//RST1
 ANSELCbits.ANSELC7 = 0;
 TRISCbits.TRISC13 = 1;//PWM1
 TRISBbits.TRISB15 = 0;


 //Motor Control Setup
 TRISDbits.TRISD1=0;
 TRISCbits.TRISC11=0;//MOT1
 TRISCbits.TRISC10=0;//MOT1
 TRISCbits.TRISC5=0;//MOT2
 TRISCbits.TRISC4=0;//MOT2
 LATCbits.LATC4=1;
 LATCbits.LATC5=1;
 LATCbits.LATC10=1;
 LATCbits.LATC11=1;
 LATDbits.LATD1=1;

 //ADC Configuration
 ANSELCbits.ANSELC1=0;
 //ANSELBbits.ANSELB2=0;//

 ANSELCbits.ANSELC6=1;
 ANSELDbits.ANSELD10=1;
 TRISCbits.TRISC6=1; //Vrx(AN_17/SCK-2)
 TRISDbits.TRISD10=1;//Vry(AN_18/AN2)
 TRISDbits.TRISD4=0; //buzzer-0
 TRISCbits.TRISC9=0; //buzzer-1
 TRISCbits.TRISC8=1;//sw //Switch in Joystick

 ADCON3Hbits.CLKSEL= 1;
 ADCON3Hbits.CLKDIV = 0;
 ADCON1Hbits.FORM=0;
 ADCORE0Hbits.ADCS= 0;//4 Source Clock periods
 ADCORE1Hbits.ADCS= 0;
 ADCON1Hbits.SHRRES = 3;
 ADCON3Lbits.REFSEL=0;
 ADMOD1Lbits.DIFF17 = 0; // AN17/RC6
 ADMOD1Lbits.DIFF18 = 0; // AN18/RD10
 ADMOD1Lbits.SIGN17 = 0; // AN17/RC6
 ADMOD1Lbits.SIGN18 = 0; // AN18/RD10


 ADCON5Hbits.WARMTIME= 5;
 // Turn on analog power for dedicated core 0

 ADCON5Lbits.SHRPWR = 1;
// Wait when the shared core is ready for operation
// Turn on digital power to enable triggers to the shared core
 PORTCbits.RC1=1;
 ADCON3Hbits.SHREN = 1;
 while(ADCON5Lbits.SHRRDY == 0);
 ADCON2Lbits.SHRADCS=0;
 ADCON2Hbits.SHRSAMC= 00001000000;
 ADIEHbits.IE17=1;
 ADIEHbits.IE18=1;



 _ADCAN17IF = 0;
 _ADCAN17IE = 1;
 _ADCAN18IF = 0;
 _ADCAN18IE = 1;

 ADCON1Lbits.ADON=1;
 double joy_x=0;
 double joy_y=0;
 double sw=0;





 //UART SETUP
 int i;
 char msg[7] = "FORWARD";
 char msg1[7] = "REVERSE";
 char msg2[5] = "RIGHT";
 char msg3[4] = "LEFT";
 char msg4[5] = "BRAKE";
 RPOR6bits.RP45R =1;
 INTCON2bits.GIE = 1;
 IEC0bits.U1TXIE = 1;

 int w=0;
 int x=0;
 int y=0;
 int z=0;
 while(1)
 {
 sw = PORTCbits.RC8;

 //CLC
 CLC1CONLbits.LCEN=1;
 w=PORTDbits.RD11;
 x=PORTCbits.RC0;
 y=PORTBbits.RB9;
 z=PORTCbits.RC1;
 RPOR3bits.RP39R=40;

 ADCON3Lbits.SWCTRG=1;

 _TRGSRC17 = 1;
 joy_x= ADCBUF17;

 Nop();
 Nop();
 Nop();
 _TRGSRC18 = 1;
 joy_y= ADCBUF18;

 Nop();
 Nop();
 Nop();
 Nop();

 if((joy_y >= 4080)&&(joy_y <= 4096))
 { //SENSOR1//FORWARD
 init_uart();
 for(i = 0; i<16640; i++){
 Nop();
 }
 for(i = 0;i<7;i++){
 if(U1STAHbits.UTXBF == 0){
 U1TXREG = msg[i];//loading
 }
 }
 while(1);
 init_timer();
 LATBbits.LATB2 = 1;
 __delay_us(10);
 LATBbits.LATB2 = 0;
 while(!PORTCbits.RC14);
 T1CONbits.TON = 1;
 while(PORTCbits.RC14);
 T1CONbits.TON = 0;
 count = TMR1;
 time = count/8000000;
 frontDistance = (time * 34000) / 2;
 //keyValue0 = PORTDbits.RD3;
 //keyValue1 = PORTDbits.RD4;
 //Buzzer
 if((60<=frontDistance)&&(frontDistance<=80)){
 LATDbits.LATD4= 0;
 LATCbits.LATC9=1;
 }
 else if((frontDistance>=10)&&(frontDistance<=60)){
 LATDbits.LATD4=1;
 LATCbits.LATC9=0;
 }
 else if(frontDistance <10 ){
 LATDbits.LATD4=1;
 LATCbits.LATC9=1;
 } else
 {
 LATDbits.LATD4=0;
 LATCbits.LATC9=0;
 }
 init_timer();

 //FORWARD
 LATCbits.LATC11=1;
 LATCbits.LATC10=0;
 LATCbits.LATC5=1;
 LATCbits.LATC4=0;
 __delay_ms (3000);
 Nop();
 Nop();
 }

 else if((joy_x >= 0)&&(joy_x <= 25))
 {
 //Sensor3 //LEFT
 init_uart();
 for(i = 0; i<16640; i++){
 Nop();
 }
 for(i = 0;i<4;i++){
 if(U1STAHbits.UTXBF == 0){
 U1TXREG = msg3[i];//loading
 }
 }
 while(1);
 init_timer();
 LATBbits.LATB8 = 1;
 __delay_us(10);
 LATBbits.LATB8 = 0;
 while(!PORTCbits.RC12);
 T1CONbits.TON = 1;
 while(PORTCbits.RC12);
 T1CONbits.TON = 0;
 count3 = TMR1;
 time3 = count3/8000000;
 leftDistance = (time3 * 34000) / 2;

 //keyValue0 = PORTDbits.RD3;
 //keyValue1 = PORTDbits.RD4;
 if((60<=leftDistance)&&(leftDistance<=80)){
 LATDbits.LATD4= 0;
 LATCbits.LATC9=1;
 }
 else if((10<=leftDistance)&&(leftDistance<=60)){
 LATDbits.LATD4=1;
 LATCbits.LATC9=0;
 }
 else if(leftDistance <10 ){
 LATDbits.LATD4=1;
 LATCbits.LATC9=1;
 } else
 {
 LATDbits.LATD4=0;
LATCbits.LATC9=0;
 }
 init_timer();

 //LEFT TURN (CCW)
 LATCbits.LATC11=1;
 LATCbits.LATC10=0;
 LATCbits.LATC5=0;
 LATCbits.LATC4=1;
 __delay_ms (3000);
 Nop();
 Nop();
 }

 else if((joy_x >= 4080)&&(joy_x <= 4096))
 {
 //SENSOR4
 init_uart();
 for(i = 0; i<16640; i++){
 Nop();
 }
 for(i = 0;i<7;i++){
 if(U1STAHbits.UTXBF == 0){
 U1TXREG = msg2[i];//loading
 }
 }
 while(1);

 init_timer();
 LATCbits.LATC7 = 1;
 __delay_us(10);
 LATCbits.LATC7 = 0;
 while(!PORTCbits.RC13);
 T1CONbits.TON = 1;
 while(PORTCbits.RC13);
 T1CONbits.TON = 0;
 count4 = TMR1;
 time4 = count4/8000000;
 rightDistance = (time4 * 34000) / 2;
 Nop();
 Nop();
 Nop();
 if((60<=rightDistance)&&(rightDistance<=80)){
 LATDbits.LATD4= 0;
 LATCbits.LATC9=1;
 }
 else if((10<=rightDistance)&&(rightDistance<=60)){
 LATDbits.LATD4=1;
 LATCbits.LATC9=0;
 }
 else if(rightDistance <10 ){
 LATDbits.LATD4=1;
 LATCbits.LATC9=1;
 } else
 {
 LATDbits.LATD4=0;
LATCbits.LATC9=0;
 }

 init_timer();


 //RIGHT TURN (CW)
 LATCbits.LATC11=0;
 LATCbits.LATC10=1;
 LATCbits.LATC5=1;
 LATCbits.LATC4=0;
 __delay_ms (3000);
 Nop();
 Nop();
 }
 else if((joy_y >= 0)&&(joy_y <= 25))
 {
 //SENSOR2
 init_uart();
 for(i = 0; i<16640; i++){
 Nop();
 }
 for(i = 0;i<7;i++){
 if(U1STAHbits.UTXBF == 0){
 U1TXREG = msg1[i];
 }
 }
 while(1);
 LATCbits.LATC3 = 1;
 __delay_us(10);
 LATCbits.LATC3 = 0;
 while(!PORTCbits.RC15);
 T1CONbits.TON = 1;
 while(PORTCbits.RC15);
 T1CONbits.TON = 0;
 count2 = TMR1;
 time2 = count2/8000000;
 backDistance = (time2 * 34000) / 2;

 init_timer();

 //REVERSE
 LATCbits.LATC11=0;
 LATCbits.LATC10=1;
 LATCbits.LATC5=0;
 LATCbits.LATC4=1;
 __delay_ms (3000);
 if((60<=backDistance)&&(backDistance<=80)){
 LATDbits.LATD4= 0;
 LATCbits.LATC0=1;
 }
 else if((10<=backDistance)&&(backDistance<=60)){
 LATDbits.LATD4=1;
 LATCbits.LATC9=0;
 }
 else if(backDistance <10 ){
 LATDbits.LATD4=1;
 LATCbits.LATC9=1;
 } else
 {
 LATDbits.LATD4=0;
 LATCbits.LATC9=0;
 }
 Nop();
 Nop();
 }

 else if((sw==1)||(PORTBbits.RB7=1))// Add CLC here.
 {
 //BRAKE
 init_uart();
 for(i = 0; i<16640; i++){
 Nop();
 }
 for(i = 0;i<5;i++){
 if(U1STAHbits.UTXBF == 0){
 U1TXREG = msg4[i];//loading
 }
 }
 while(1);
 LATCbits.LATC11=1;
 LATCbits.LATC10=1;
 LATCbits.LATC5=1;
 LATCbits.LATC4=1;
 __delay_ms (3000);
 }
 //reset conditions

 }

 return 0;
}

 // ADC AN12 ISR
void __attribute__((interrupt, no_auto_psv)) _ADCAN17Interrupt(void)
{
dataAN17 = ADCBUF17; // read conversion result
_ADCAN17IF = 0; // clear interrupt flag
}
 // ADC AN18 ISR
void __attribute__((interrupt, no_auto_psv)) _ADCAN18Interrupt(void)
{
dataAN18 = ADCBUF18; // read conversion result
_ADCAN18IF = 0; // clear interrupt flag
}
void __attribute__((__interrupt__, no_auto_psv )) _U1TXInterrupt(void)
{
 IFS0bits.U1TXIF = 0; // clear TX interrupt flag