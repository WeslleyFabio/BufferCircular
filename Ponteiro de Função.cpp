#include <stdio.h>

typedef void(*pf)(void);

typedef struct{
	char * ProcessName;
	int Time;
	pf Ponteiro;
}process;

#define BUFFERSIZE 10

process buffer[BUFFERSIZE];

int start = 0;
int end = 0;
char bol[] = "proc1";
char bol2[] = "proc2";
char bol3[] = "proc3";

void add(char * nProcessName, int nTime, pf nPonteiro){ //add no buffer circular
	//tem espaço?
	if(((end+1)%BUFFERSIZE) != start){
		buffer[end].ProcessName = nProcessName;
		buffer[end].Time = nTime;
		buffer[end].Ponteiro = nPonteiro;
		end = (end+1)%BUFFERSIZE;
	}
}

void exec(void){
	
	//tem alguma coisa no buffer?
	if(start != end){
		printf("Executando na posicao: %d\n", start);
		printf("Ultima posicao: %d\n", end);
		printf("<--------------\n", end);
		buffer[start].Ponteiro();
		printf("-------------->\n", end);
	}
}

void remove(void){
	//tem alguma coisa no buffer?
	if(start != end){
		
		//	buffer[start].Ponteiro();
		start = (start+1)%BUFFERSIZE;
	}
}

void f1(void){printf("f1\n");}
void f2(void){printf("f2\n");}
void f3(void){printf("f3\n");}

int main(){
	
	add(bol, 1, f1);
	add(bol2, 1, f2);
	add(bol3, 1, f3);
	exec();
	remove();
	exec();
	remove();
	exec();
	remove();
	exec();
	
	return 0;
}
