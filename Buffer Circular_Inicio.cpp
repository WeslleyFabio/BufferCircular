///////CODIGO PARRA BUFFER CIRCULAR///////
///////POR: Dev. WESLLEY F�BIO///////////


#include "stdio.h"
//#include "string.h"
//#include "stdlib.h"

#define cb_size 10 //TAMANHO DO BUFFER
#define SUCESS 1
#define FAIL 0

int  circular_buffer[cb_size];
int start = 0, end = 0;

char addbuff(int newdata){
	if ( ((end+1)%cb_size) != start){ //A PROXIMA POSI��O � DIFERENTE DO COME�O? SE TIVER, ENTRA, ADDICIONA A INFORMA��O, MOVE O END E ESPERA UMA NOVA INFORMA��O
		circular_buffer[end] = newdata;
		end = (end+1)%cb_size;
		return SUCESS;
	}
	return FAIL; //CASO DE FAIL, � PQ O BUFFER EST� CHEIO
}

main(){
	

	
	return 0;
}

