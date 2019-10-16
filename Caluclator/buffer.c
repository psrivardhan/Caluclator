struct container{
	
	float* data;
	uint8_t capacity;
	uint8_t filled;
	};
struct ncontainer{
	
	uint8_t* data;
	uint8_t capacity;
	uint8_t filled;
	};

	
	
struct container* createcontainer(uint8_t capacityc){
	struct container* newcontainer; 
	
	newcontainer = (struct container *)malloc(sizeof(struct container)); 
	
	newcontainer -> capacity = capacityc;
	newcontainer -> filled = 0;
	newcontainer -> data =  (float *)malloc(capacityc * sizeof(float));
	 return newcontainer;
	}

struct ncontainer* createcontainer1(uint8_t capacityc){
	struct ncontainer* newcontainer; 
	
	newcontainer = (struct ncontainer *)malloc(sizeof(struct ncontainer)); 
	
	newcontainer -> capacity = capacityc;
	newcontainer -> filled = 0;
	newcontainer -> data =  (uint8_t *)malloc(capacityc * sizeof(uint8_t));
	 return newcontainer;
	}
//////////



//////////
void adddata(struct container* cont , float data ){
		cont->data[cont->filled++] = data;
	}

void adddata1(struct ncontainer* cont , uint8_t data ){
		cont->data[cont->filled++] = data;
	}
///////////


////////////
float readdata(struct container* cont){
		return cont-> data[--cont->filled];
	}

uint8_t readdata1(struct ncontainer* cont){
		return cont-> data[--cont->filled];
	}
////////////


///////////////	
float removetop(struct container* cont){
	cont->filled--;
	return cont-> data[cont->filled--];
	}
	
uint8_t removetop1(struct ncontainer* cont){
	cont->filled--;
	return cont-> data[cont->filled--];
	}
///////////////////
//////////////
float string_to_number(byte* str_num){
  float number=0;
  int i=0,j=1;
  while(str_num[i]!='\0'){
	if(str_num[i]!='.'){number = 10*number + (str_num[i++]-48);}
	if(str_num[i]=='.'){ i++;while(str_num[i]!='\0'){number+=((str_num[i++]-48)/pow(10,j++));}break;}
  }
  return number;
}


/**********************************************************/
float do_math(float num_1,float num_2,byte op){
  float result=0;
  switch (op){
    case '+':
      result=num_1+num_2;
      break;
    case '-':
      result=num_1-num_2;
      break;
    case '*':
      result=num_1*num_2;
      break;
    case '/':
        result=num_1/num_2;
        break;
  }

  return result;
}
