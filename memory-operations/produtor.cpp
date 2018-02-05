/* 
 Descrição:
 - Programa que escreve uma informação na memória compartilhada

 Executar:
 ./nomeExecutaval

 Compilar:
 g++ -o nomeExecutaval Semaforo.cpp nomeDesseArquivo.cpp
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>    //strcpy
#include <sys/ipc.h>   //shmget
#include <sys/shm.h>   //shmget,shmat
#include <sys/types.h> //shmat
#include <unistd.h>  // sleep()
#include "semaforo.h"


int main(int argc, char *argv[]){

	 // Semaforo usado para sincronizar a região crítica
	Semaforo * semaforo;
	semaforo = new Semaforo(1234,1,IPC_CREAT|0600);

	// Identificador da memória compartilhada
	int shmid = 0;

	// Tamanho da memória compartilhada (bytes)
	int shmSize = 8;

	// Ponteiro para memória compartilhada
	int *memoriaCompartilhada;
	
	// Criando a memória compartilhada
	shmid = shmget( ftok("/home/ivanovitchm", 1), shmSize, 0666| IPC_CREAT);

	// Associando-se a memória compartilhada
	memoriaCompartilhada = (int*) shmat(shmid, 0, 0);
	*memoriaCompartilhada = 0;
	
	// A memória foi criada corretamente
	if(shmid == -1) {
		fprintf(stderr, "Processo de criar a memória compartilhada falhou\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Produtor: id da memória compartilhada é %d.\n Digite \"ipcs -m\" para verificar\n",shmid);

	while (true){
	    printf("Produtor: vou entrar na região crítica\n");
	    semaforo->P();
	    *memoriaCompartilhada += 1;
	    semaforo->V();
	    printf("Produtor: vou sair da região crítica\n");
	    sleep(2);
	}
	delete semaforo;
return 0;
}