#include <buffer.c>

/*****************************************************************************************
 *****************************************************************************************
 ******************************************************************************************/
float getinput(void)
{
	int i=0 ,j=0;
	float result;
	byte buffer[10]={0};
	byte key,op_temp;
	
	float number[10];
	float num_1=0,num_2=0;
	struct container* numbers = createcontainer(50);
	//struct container* res = createcontainer(50);
	struct ncontainer* op = createcontainer1(50);
	
	byte precedence [50]={0};
	precedence[42]=2;				// precedence of (*)
	precedence[47]=2;				// precedence of (/)
	precedence[43]=1;				// precedence of (+)
	precedence[45]=1;				// precedence of (-)
	adddata1(op,0);
	LCD_Cmd(0xF);
while(1)
{
	
	
	key = keyscan();
	if((key!= 'c') & (key!= 0)){
	if((key!= '=') & (key!= 'b') & (key!= 's') & (key!='p')){dispress(key);}//new
	if(key != 0)
		{
			  if(key== '='){
					LCD_Cmd(0xC);
					buffer[i] = '\0';
					number[j] = string_to_number(buffer);
					adddata(numbers,number[j++]);i=0;
					while(/*readdata1(op)!=0*/numbers->filled>1)//new
					{
						
						
						num_2=removetop(numbers);
						numbers->filled++;
						num_1=removetop(numbers);
						//op->filled++; //NEW
						
						op_temp=removetop1(op);
						op->filled++; //NEW
						//displayresult(num_1);displayresult(num_2);dispress(op_temp); //FOR DEBUGGING
						result = do_math(num_1,num_2,op_temp);
						numbers->filled++;//new
						adddata(numbers,result);
						
					}
						
					
					//numbers->filled++
					return readdata(numbers);
				}
			
			
		  else if(key== '+' ||key== '-' || key== '*' || key== '/')
				{
					buffer[i] = '\0';
					 number[j] = string_to_number(buffer);
					adddata(numbers,number[j++]);i=0;
					
					  if(precedence[key] < precedence[readdata1(op)])
					  {
						num_2=removetop(numbers);
						num_1=removetop(numbers);
						op_temp=removetop1(op);
						result=do_math(num_1,num_2,op_temp);
						adddata(numbers,result);
						adddata1(op,key);
					}
						else{ adddata1(op,key);}
				
										
			    }
			    
			    else if(key== 's' ){LCD_Message("sqrt(");while(1){key=keyscan();if(key!=0){if((key!='+') & (key!='-') & (key!='*') & (key!='p')& (key!='/') & (key!='=') &(key!='b')){dispress(key);buffer[i++] = key;}
								else if(key=='='){LCD_Message(")");LCD_Cmd(0xC);buffer[i] = '\0';number[j]=string_to_number(buffer);result=sqrt(number[j]);return result;} } } }
		   
			    else if(key== 'p')
				{
					LCD_Message("a=");
					float a,b;
					
						while(1)
							{	
							 key=keyscan();
							 if(key!=0)
							 {
								if((key!='+') & (key!='-') & (key!='*') & (key!='/') & (key!='=') &(key!='b') & (key!='s'))
								{
									
															
											buffer[i]=key;
											dispress(key);
										
								}
								else if(key=='='){a=string_to_number(buffer);i=0;break;}
							 }
							}
							LCD_Message("  b=");
						while(1)
							{	
							 key=keyscan();
							 if(key!=0)
							 {
								if((key!='+') & (key!='-') & (key!='*') & (key!='/') & (key!='=') &(key!='b') & (key!='s'))
								{
									
															
											buffer[i]=key;
											dispress(key);
										
								}
								else if(key=='='){LCD_Cmd(0xC);b=string_to_number(buffer);result=pow(a,b);return result;}
							 }
							}	
					
				
				}		
			
				
		    else{
					if(key!='b'){buffer[i++] = key;}
					if(key== 'b'){buffer[--i]='\0';LCD_Cmd(0X10);LCD_Message(" ");LCD_Cmd(0X10);}
				}
		}
	}
}
}
