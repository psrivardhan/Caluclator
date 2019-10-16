
#define		ROW0			   0
#define		ROW0_DDR		 DDRD
#define		ROW0_PORT		 PORTD

#define		ROW1			    1
#define		ROW1_DDR		  DDRD
#define		ROW1_PORT		  PORTD

#define		ROW2		     	 2
#define		ROW2_DDR		  DDRD
#define		ROW2_PORT		  PORTD

#define		ROW3			     3
#define		ROW3_DDR	  	  DDRD
#define		ROW3_PORT		  PORTD

#define		LINE0			     4
#define		LINE0_DDR		  DDRD
#define		LINE0_PIN		  PIND
#define		LINE0_PULLUP	  PORTD


#define		LINE1		    	 5
#define		LINE1_DDR		  DDRD
#define		LINE1_PIN		  PIND
#define		LINE1_PULLUP	  PORTD

#define		LINE2			     6
#define		LINE2_DDR		  DDRD
#define		LINE2_PIN		  PIND
#define		LINE2_PULLUP	  PORTD

#define		LINE3			     7
#define		LINE3_DDR		  DDRD
#define		LINE3_PIN		  PIND
#define		LINE3_PULLUP	  PORTD


//Extra
#define		LINE4			     0
#define		LINE4_DDR		  DDRC
#define		LINE4_PIN		  PINC
#define		LINE4_PULLUP	  PORTC

#define ALL_LINES	 (((LINE0_PIN&(1U<<LINE0))>>LINE0) & ((LINE1_PIN&(1U<<LINE1))>>LINE1) & ((LINE2_PIN&(1U<<LINE2))>>LINE2) & ((LINE3_PIN&(1U<<LINE3))>>LINE3)  & ((LINE4_PIN&(1U<<LINE4))>>LINE4))




/*
 * 
 * 
 * 
 * 
 * 
 * 
 * */
 byte keyscan(void);
void keypad_init(void)
{
//set the rows direction as output
ROW0_DDR |=(1U<<ROW0);
ROW1_DDR |=(1U<<ROW1);
ROW2_DDR |=(1U<<ROW2);
ROW3_DDR |=(1U<<ROW3);
//set the line direction as input
LINE0_DDR &=~(1U<<LINE0);
LINE1_DDR &=~(1U<<LINE1);
LINE2_DDR &=~(1U<<LINE2);
LINE3_DDR &=~(1U<<LINE3);
//enable line pullup
LINE0_PULLUP |=(1U<<LINE0);
LINE1_PULLUP |=(1U<<LINE1);
LINE2_PULLUP |=(1U<<LINE2);
LINE3_PULLUP |=(1U<<LINE3);
//set the rows high
ROW0_PORT |=(1U<<ROW0);
ROW1_PORT |=(1U<<ROW1);
ROW2_PORT |=(1U<<ROW2);
ROW3_PORT |=(1U<<ROW3);


//Extra 
LINE4_DDR &=~(1U<<LINE4);
LINE4_PULLUP |=(1U<<LINE4);


}


/*
*Function name : keypad_scan
*Parameters	   : void
*return		   : unsigned char
*purpose       : scan the keypad and return the pressed key 
*				and returns null if no key pressed
*/
byte keyscan(void)
{
byte input;
int row=0;
//loop on row 
	for(row=0;row<4;row++)
	{
	//set all row high
	ROW0_PORT |=(1<<ROW0);
	ROW1_PORT |=(1<<ROW1);
	ROW2_PORT |=(1<<ROW2);
	ROW3_PORT |=(1<<ROW3);
	//clear row number from iteration
	switch(row)
		{
		case 0:ROW0_PORT &=~(1<<ROW0);
				break;
		case 1:ROW1_PORT &=~(1<<ROW1);
				break;
		case 2:ROW2_PORT &=~(1<<ROW2);
				break;
		case 3:ROW3_PORT &=~(1<<ROW3);
				break;
		}
		//read the input
		input  = ((LINE0_PIN&(1<<LINE0)) | (LINE1_PIN&(1<<LINE1)) | (LINE2_PIN&(1<<LINE2)) | (LINE3_PIN&(1<<LINE3)) | ((LINE4_PIN&(1<<LINE4))) );
			
			
		//if it was input
		if(ALL_LINES != 1)
		{
			//wait till the input is gone
			while(ALL_LINES != 1);
			//to check input in binary on input
			/*char st[8]; 
			itoa(input,st,2);
			LCD_Message(st);*/
		
			break;
		}
	}
	if(row == 4) 
	{
		return 0;
	}
	
	
	switch(row)
	{
		case 0://switch the input
				switch(input)
					{
					case 0x71: return '/';
					case 0xB1: return '9';
					case 0xD1: return '8';
					case 0xF1: return '7';
					case 0xF0: return 'S';
					}
		case 1://switch the input
					switch(input)
					{
						case 0x71: return '*';
						case 0xB1: return '6';
						case 0xD1: return '5';
						case 0xE1: return '4';
						case 0xF0: return 'C';
					}
		case 2://switch the input
					switch(input)
					{
						case 0x71: return '-';
						case 0xB1: return '3';
						case 0xD1: return '2';
						case 0xE1: return '1';
						case 0xF0: return 'T';
					}
		case 3://switch the input
					switch(input)
					{
						case 0x71: return '+';
						case 0xB1: return '=';
						case 0xD1: return '0';
						case 0xE1: return '.';
						case 0xF0: return 'c';
					}
	}
	return  0;
	
}
