#include <stdio.h>

struct container{
	
	float* data;
	uint8_t capacity;
	uint8_t filled;
	};
	
	
struct container* createcontainer(uint8_t capacityc){
	struct container* newcontainer; 
	
	newcontainer = (struct container *)malloc(sizeof(struct container)); 
	
	newcontainer -> capacity = capacityc;
	newcontainer -> filled = -1;
	newcontainer -> data =  (float *)malloc(capacityc * sizeof(float));
	
	}
