#include <stdint.h>

#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
#define _SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + __SFR_OFFSET)
#define __SFR_OFFSET 0x20
// macros for setting register values and offsets
#define DDRB _SFR_IO8(0x04)
// define DDRB register
#define PORTB _SFR_IO8(0x05)
// define PORTB
#define DELAY_MS 1000

void delay_func(uint16_t ms) 
{
	//function to implement delay
	uint16_t delay_count = F_CPU / 16000;
	//set delay count to 1000ms
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
  		// toggle Pin 5 of PORTB high/low
    	delay_func(DELAY_MS); 
  		// delay
  	}
  	return 0;
}