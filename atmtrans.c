#include<avr/io.h>
#include<util/delay.h>

void main()
{
UBRRL=51;
UCSRB=(1<<TXEN)|(1<<RXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);

while(1)
{
char a;
while((UCSRA&(1<<RXC))==0);
a=UDR;
_delay_ms(100);
UDR=a;
while((UCSRA&(1<<TXC))==0);
UCSRA=1<<TXC;

}


}
