#include <stdint.h>

#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))

#define _SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + __SFR_OFFSET)
#define __SFR_OFFSET 0x20

#define DDRB _SFR_IO8(0x04)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

#define PORTB _SFR_IO8(0x05)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

#define DELAY_MS 1000

void delay_func(uint16_t ms) 
{
	uint16_t delay_count = F_CPU / 16000;
	volatile uint16_t i;
	while (ms != 0) 
	{
		for (i=0; i != delay_count; i++);
		ms--;
	}
}

int main ()
{
	DDRB |= 0x20;
 	// set data direction register for output on PORTB
 	while(1) 
 	{
 		PORTB ^= 0x20;
  		// set Pin 5 of PORTB at high
    	delay_func(DELAY_MS); 
  		// delay
  	}
  	return 0;
}