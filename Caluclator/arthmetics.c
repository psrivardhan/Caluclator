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

while(1)
{
	
	
	key = keyscan();
	if(key!= 'c'){
	if(key!= '='){dispress(key);}
	if(key != 0)
		{
			  if(key== '='){

					buffer[i] = '\0';
					number[j] = string_to_number(buffer);
					adddata(numbers,number[j++]);i=0;
					while(readdata1(op)!=0)
					{
						
						num_2=removetop(numbers);
						numbers->filled++;
						num_1=removetop(numbers);
						op->filled++;
						
						op_temp=removetop1(op);
						//displayresult(num_1);displayresult(num_2);dispress(op_temp); //FOR DEBUGGING
						result = do_math(num_1,num_2,op_temp);
						adddata(numbers,result);
						
					}
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
		   
					
			
				
		    else{
				 buffer[i++] = key;
				}
		}
	}
}
}
