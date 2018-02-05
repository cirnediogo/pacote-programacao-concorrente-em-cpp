/* 
 Descrição:
 - Programa que faz associação com uma memória compartilhada.

 Executar:
 ./nomeExecutaval shmidGeradoNoExemplo01
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>    //strcpy
#include <sys/ipc.h>   //shmget
#include <sys/shm.h>   //shmget,shmat
#include <sys/types.h> //shmat

int main(int argc, char *argv[]){

	// Identificador da memória compartilhada
	int shmid = atoi(argv[1]);
	
	// Ponteiro para memória compartilhada
	char *memoriaCompartilhada;
	
	// Associando a memória compartilhada
	memoriaCompartilhada = (char*) shmat(shmid, 0, 0);
	
	// A memória foi associada corretamente?
	if (memoriaCompartilhada == (char*)-1){
        	printf("Não foi possível associar a memória com o id %d\n", shmid);
        	exit(1);
	}
	
	// Escrever na memória compartilhada
	strcpy(memoriaCompartilhada,"Estou escrevendo na memória compartilhada");

    return 0;
}
