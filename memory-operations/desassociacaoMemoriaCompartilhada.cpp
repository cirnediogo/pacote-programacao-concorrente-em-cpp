/* 
 Descrição:
 - Programa que faz desassociação com uma memória compartilhada.

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

	// Lendo na memória compartilhada
	printf("Valor lido: %s \n",memoriaCompartilhada);

	// Realizando a desassociação
	if (shmdt(memoriaCompartilhada) == -1){
		printf("Ocorreu falha na desassociação\n");
		exit(1);
	}
	
	printf("Programa desassociou da memória compartilhada cujo Id é: %d \n", shmid);
	printf("Executar o comando \"ipcs -m\" e verificar que a memória não foi deletada\n");

return 0;
}