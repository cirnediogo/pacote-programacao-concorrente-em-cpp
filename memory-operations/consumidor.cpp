/* 
 Descrição:
 - Programa que lê a informação de uma memória compartilhada

 Executar:
 ./nomeExecutaval idCriadoPeloProdutor

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
	int shmid = atoi(argv[1]);

	// Ponteiro para memória compartilhada
	int *memoriaCompartilhada;
	
	// Associando a memória compartilhada
	memoriaCompartilhada = (int*) shmat(shmid, 0, 0);
	
	// A memória foi associada corretamente?
	if (memoriaCompartilhada == (int*)-1){
        	printf("Não foi possível associar a memória com o id %d\n", shmid);
        	exit(1);
	}

	while (true){
	  printf("Consumidor: vou entrar na região crítica\n");
	  semaforo->P();
	  printf("Consumidor: valor lido: %d \n",*memoriaCompartilhada);
	  semaforo->V();
	  printf("Consumidor: saiu da região crítica\n");
	  sleep(1);
	}
	delete semaforo;


return 0;
}