/* 
 * Traffic_lights_project.c
 *
 * Created: 18-02-2023 23:59:42
 * Author : Abhishek Vishwakarma
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>





int main(void)
{
	DDRC = 0b00000011; // pin 0 are using for green light and 1 using for red light 
	DDRA = 0b01111111;
	DDRB = 0b00000011; // pin 0 is connected from segment2 common pin & 1 connected from segment1 common pin.
	
	uint8_t count[10] = {
		0b00111111,// 0
		0b00000110,// 1
		0b01011011,// 2
		0b01001111,// 3
		0b01100110,// 4
		0b01101101,// 5
		0b01111101,// 6
		0b00000111,// 7 
		0b01111111,// 8
		0b01101111// 9
	};
    while (1) 
    {
				//Red Light

					PORTC = 0b00000010;
		
		for (int segment1 = 5; segment1 >=0; segment1 = segment1 - 1)
		{
			for (int segment2 = 9; segment2 >=0; segment2 = segment2 - 1)
			{
				for (int repeat = 0; repeat<=10; repeat = repeat + 1)
				{
					PORTA = count[segment1];
					PORTB = 0b00000001;
					_delay_ms(50);
					PORTA = count[segment2];
					PORTB = 0b00000010;
					_delay_ms(50);
				}
				
				
			}
		}
		
		//Green Light
		
		PORTC = 0b00000001;
		
		for (int segment1 = 5; segment1 >=0; segment1 = segment1 - 1)
		{
			for (int segment2 = 9; segment2 >=0; segment2 = segment2 - 1)
			{
				for (int repeat = 0; repeat<=10; repeat = repeat + 1)
				{
					PORTA = count[segment1];
					PORTB = 0b00000001;
					_delay_ms(50);
					PORTA = count[segment2];
					PORTB = 0b00000010;
					_delay_ms(50);
				}
				
				
			}
		}
    }
}

