#include <stdio.h>


typedef struct{
	char * ProcessName;
	int Time;
}process;

#define BUFFERSIZE 10

process buffer[BUFFERSIZE];

int start = 0;
int end = 0;

void add(char * nProcessName, int nTime){ //add no buffer circular
	//tem espaço?
	if(((end+1)%BUFFERSIZE) != start){
		buffer[end].ProcessName = nProcessName;
		buffer[end].Time = nTime;
		end = (end+1)%BUFFERSIZE;
	}
}

void remove(void){
	//tem alguma coisa no buffer?
	if(start != end){
		start = (start+1)%BUFFERSIZE;
	}
}

int main(){
	
	return 0;
}
