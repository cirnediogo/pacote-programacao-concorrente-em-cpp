// Programa memoria2.cpp
// Programa que simula um produtor de dados


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define MEM_SZ 4096


struct shared_use_st {
  int written_by_you;
  char some_text[BUFSIZ];
};

int main()
{

  int running = 1;
  void *shared_memory = (void *) 0; // definindo um ponteiro para null
  struct shared_use_st *shared_stuff;
  char buffer[BUFSIZ];
  int shmid;   // variavel de armazenamento do identificador da memoria compartilhada

  shmid = shmget((key_t) 123, MEM_SZ, 0666|IPC_CREAT);  // criacao da memoria compartilhada

  // teste se a memoria foi criada corretamente
  if(shmid == -1) {
    fprintf(stderr,"shmget falhou\n");
    exit(EXIT_FAILURE);
  }

  shared_memory = shmat(shmid, (void*) 0, 0); // associa��o da mem�ria ao processo
  
  // teste se a memoria foi associada corretamente
  if(shared_memory == (void*) -1) {
    fprintf(stderr,"shmat falhou\n");
    exit(EXIT_FAILURE);
  }

  shared_stuff = (struct shared_use_st *) shared_memory;
  shared_stuff->written_by_you = 0;

  printf("Mem�ria ligada � posi��o %X\n", (int) shared_memory);

  while(running) {

     while(shared_stuff->written_by_you == 1) {
        sleep(1);
        printf("Esperando pelo Cliente ... \n");
     }   
    
     printf("Entre com algum texto: ");
     fgets(buffer, BUFSIZ, stdin);
       
     
     strcpy(shared_stuff->some_text, buffer);
     
     shared_stuff->written_by_you = 1;
     

     if ( strncmp(buffer, "fim", 3) == 0 ) {
         running = 0; // condi��o para parar o programa produtor
     }
   
  }

  // Desassociando o segmento de mem�ria do processo + teste de sucesso do procedimento

  if(shmdt(shared_memory) == -1) {
    fprintf(stderr,"shmdt falhou\n");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}