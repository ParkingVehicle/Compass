#include <avr/io.h>

//// LED Config /////////
#define RED PD5
#define YELLOW PD6
#define GREEN PD7
#define LED_PORT PORTD

#define N_YELLOW PD3
#define N_BLUE PD4
#define ON 1
#define OFF 0


//////////////////////////
/*
 * DDR address is PORT address - 1, SFR registers starts at address 32 in RAM
 * we've to subtract -1 to get the DDR address from port address and subtract (-32)
 * to get the SFR address, which is (-33) in total to get the DDR SFR address from
 * PORT general address
*/
#define LED_DDR _SFR_IO8((&LED_PORT)-33)
#define LED_PIN _SFR_IO8((&LED_PORT)-34)

#define LED_ON(COLOR) (LED_PORT |= (1<<COLOR))
#define LED_OFF(COLOR) (LED_PORT &= ~(1<<COLOR))
#define LED_INIT(COLOR) (LED_DDR |= (1<<COLOR))
#define LED_TOGGLE(COLOR) (LED_PORT ^= (1<<COLOR))
