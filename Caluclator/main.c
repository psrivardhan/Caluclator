#include <avr/io.h> 
#include <util/delay.h> 

#include <funclcd.c>
#include <keypad.c>
#include <arthmetics.c>




void calc_init(void);

int main(void){	
		calc_init();
		float result;
		byte btn;
		
		do{
			result = getinput();
			displayresult(result);
			}
	while(1){
		btn=keyscan();
		if(btn!=0){
			if(btn=='c'){
		LCD_Clear();
		result = getinput();
		displayresult(result);};
		
		
		
	}
		
		 
		}
		
return 0;

}



void calc_init(void){
	DDRB = 0xFF;	// PINS CONFIG FOR LCD
	LCD_Init(); 
	LCD_Clear();
	keypad_init();
	LCD_Message("P.Srivardhan");
	
	LCD_Cmd(0XC0);
	LCD_Message("Calci v2");
	animatetext(" EE11 ");
	LCD_Clear();
	}
