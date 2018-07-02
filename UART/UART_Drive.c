////////// MCAL  ////////////////
//Microcontroller Abistraction layer
//////////////////////////////////////
#include <avr\io.h>
#include "common.h"
#include "UART_Drive.h"
//////////// Global Functions /////////////////////

void USART_Init( unsigned int baud )
{

/* Set baud rate */
UBRRH = (unsigned char)(baud>>8)&(0x7F);
UBRRL = (unsigned char)baud;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<URSEL)|(3<<UCSZ0)|(1<<USBS);
//UCSRA |= (1<<U2X);
}

////////////////////////////////////////////////////
uint8_t USART_CheckTransmitAvailable(void)
{
	return( UCSRA & (1<<UDRE));
}
void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) );
/* Put data into buffer, sends the data */
UDR = data;
}
//////////////////////////////////////////////////////
unsigned char USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );
/* Get and return received data from buffer */
return UDR;

}
void HexToAscii(uint32_t num,char * ascii)
{
	uint8_t tmp[6];
	uint8_t i;
	tmp[0] = (num%16);
	tmp[1] = ((num>>4)%16);
	tmp[2] = ((num>>8)%16);
	tmp[3] = ((num>>12)%16);
	tmp[4] = ((num>>16)%16);
	tmp[5] = ((num>>20)%16);
	for (i=0;i<6;i++)
	{
		if(tmp[i] < 10)
			ascii[i]=tmp[5-i]+48;
		else
			ascii[i]=tmp[5-i]+55;
	}
}
void DecToAscii(uint32_t num,char * ascii)
{
	uint8_t tmp[6];
	uint8_t i;
	tmp[0] = (num%10);
	tmp[1] = ((num/10)%10);
	tmp[2] = ((num/100)%10);
	tmp[3] = ((num/1000)%10);
	tmp[4] = ((num/10000)%10);
	tmp[5] = ((num/100000)%10);
	for (i=0;i<6;i++)
	{
		ascii[i]=tmp[5-i]+48;
	}
}
void FloatToString(float num,char * myString)
{
	dtostrf(num, 3, 5, myString);
}
/////////// USART ISR  //////////////////////////
ISR(USART_RXC_vect)
{
	char ReceivedByte;
	ReceivedByte = UDR; // Fetch the received byte value into the variable "ByteReceived"

	UDR = ReceivedByte; // Echo back the received byte back to the computer
}
