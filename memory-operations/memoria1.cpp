// Programa memoria1.cpp - Programa consumidor via memoria compartilhada

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>


#define MEN_SZ 4096


struct shared_use_st {

  int written_by_you;
  char some_text[BUFSIZ];
};


int main()
{
  int running = 1;
  void *shared_memory = (void *) 0;
  struct shared_use_st *shared_stuff;
  int shmid;


  srand( (unsigned int) getpid() );

  shmid = shmget( (key_t) 123, MEN_SZ, 0666| IPC_CREAT);

  if(shmid == -1) {
    fprintf(stderr, "shmget failed\n");
    exit(EXIT_FAILURE);
  }

  shared_memory = shmat (shmid, (void *) 0, 0);
  if (shared_memory == (void *) -1) {
    fprintf(stderr, "shmat failed\n");
    exit (EXIT_FAILURE);
  }

  printf("Memoria ligada em %X\n", (int) shared_memory);

  shared_stuff = (struct shared_use_st *) shared_memory;
  shared_stuff->written_by_you = 0;

  while(running) {
    if (shared_stuff->written_by_you) {
      printf("Voc� escreveu:  %s", shared_stuff->some_text);
      sleep( rand() % 4);
      shared_stuff->written_by_you = 0; // confirma��o do cliente
      if (strncmp(shared_stuff->some_text,"fim", 3) == 0) {
	running = 0;
      }   
    }
  }

  if(shmdt(shared_memory) == -1) {
    fprintf( stderr, "shmdt  failed\n");
    exit(EXIT_FAILURE);
  }

  if(shmctl(shmid, IPC_RMID,0) == -1) {
    fprintf(stderr, "shmctl(IPC_RMID) failed\n");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}