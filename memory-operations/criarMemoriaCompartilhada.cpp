/* 
 Descrição:
 - Programa que cria apenas uma memória compartilhada.
*/


#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>  //shmget
#include <sys/shm.h>  //shmget

int main(int argc, char *argv[]){

	// Identificador da memória compartilhada
	int shmid = 0;

	// Tamanho da memória compartilhada (bytes)
	int shmSize = 1024;
	
	// Criando a memória compartilhada
	  shmid = shmget( ftok("/home/ivanovitchm", 1), shmSize, 0666| IPC_CREAT);
	
	// A memória foi criada corretamente
	if(shmid == -1) {
		fprintf(stderr, "Processo de criar a memória compartilhada falhou\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Id da memória compartilhada é %d.\n Digite \"ipcs -m\" para verificar\n",shmid);
return 0;
}
