

////////////Global Functions Prototypings ////////

void USART_Init( unsigned int baud );
uint8_t USART_CheckTransmitAvailable(void);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
void HexToAscii(uint32_t num,char * ascii);
void DecToAscii(uint32_t num,char * ascii);

void FloatToString(float num,char * myString);
///////////////////////////////////////////////////

