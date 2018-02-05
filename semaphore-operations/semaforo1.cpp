// Programa semaforo1.cpp
// Programa para ilustrar a utiliza��o de semaforos.

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

#define CHAVE 123
#define NUM_SEM 4


int main()
{
  int semid;  // identificador dos sem�foros
 

  // cria��o de NUM_SEM4 sem�foros
  // Utiliza-se path para ser a chave do conjunto de sem�foros

   if( (semid = semget( CHAVE, NUM_SEM,IPC_CREAT|IPC_EXCL|0600)) == -1 )
   {
    // entra no if se houver falha na abertura do sem�foro

    perror("Erro na execu��o de semget()");
    exit(1);
   }
   printf("O semid do conjunto de sem�foros �: %d \n", semid);
   exit(0);

}
