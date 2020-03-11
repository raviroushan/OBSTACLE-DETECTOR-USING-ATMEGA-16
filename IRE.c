#include<mega16.h>
#include<delay.h>
void adc_init()
{
ADMUX=0x00;
ADCSRA=0b10100111;
SFIOR=0x00;
}
int adc_read()
{
ADCSRA|=0b01000000;
while((ADCSRA&0b0100000)==0);
return ADCW;
}
int c=0;
void main()
{
adc_init();
PORTA=0x00;
DDRA=0x01;
PORTC=0x00;
DDRC=0x33;
while(1)
{
PORTC.0=1;
PORTC.1=0;
PORTC.5=0;
PORTC.4=1;
c=adc_read();
delay_ms(100);
while(c<=800)
{
PORTC.0=0;
PORTC.1=0;
PORTC.5=0;
PORTC.4=0;
delay_ms(2500);
PORTC.0=0;
PORTC.1=1;
PORTC.5=1;
PORTC.4=0;
delay_ms(2500);
PORTC.0=1;
PORTC.1=0;
PORTC.5=0;
PORTC.4=0;
delay_ms(2500);
PORTC.0=1;
PORTC.1=0;
PORTC.5=0;
PORTC.4=1;
}
}
}
