#include <avr/io.h> 
#include <util/delay.h> 

#include <funclcd.h>
#include <arthmetics.h>
#include <keypad.c>


void dispress(void);
void calc_init(void);

int main(void)
{	
		calc_init();
		
		
	while(1){
		dispress();
		}
		
return 0;

}


void dispress(void){
	byte key;
		key = keyscan();
		SetBit(PORTB,LCD_RS); 
		if(key != 0){SendByte(key);}
	
	}
void calc_init(void){
	DDRB = 0xFF;	// PINS CONFIG FOR LCD
	LCD_Init(); 
	LCD_Clear();
	keypad_init();
	LCD_Message("Calc ");
	animatetext("V2");
	LCD_Clear();
	}
