

#ifndef SRC_COMMON_COMMON_H_
#define SRC_COMMON_COMMON_H_

#include <avr/pgmspace.h>
typedef unsigned char uint8;
#define T200ms 40
#define T20ms 4
#define T1Sec 200
#define RESET 0
#define TRUE 1
#define FALSE 0
#define WAIT(TIME) (cyclic ##TIME == T ##TIME)
#define CYCLIC_INC(TIME)  ((cyclic ##TIME)++)
#define CYCLIC_RST(TIME)  ((cyclic ##TIME) = RESET)
#define EVENT_SET(ev)  (ev = TRUE)
#define EVENT_CLR(ev)  (ev = FALSE)
#define EVENT_IS_SET(ev)  (ev == TRUE)

#endif
