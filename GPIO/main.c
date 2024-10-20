#include<stdio.h>
#include<stdlib.h>
#include"GPIO.h"

int main(){

int b = 0b1001;

b= (b|(1<<2)) &~(1<<0);
	

	

printf("%d" ,b);


return 0 ;

}