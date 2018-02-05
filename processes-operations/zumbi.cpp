// Programa zumbi.cpp

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main ()
{

// declaracao de variaveis
  pid_t pid;          // definindo um identificador de processo - inteiro longo
   
  printf("Comecando o programa zumnbi ... \n");
  printf( "Eu sou o Pai %d e vou criar um Filho\n", getpid() );
  pid = fork();   // dividindo o processo em dois

  switch(pid)
    {
    case -1:       // erro na abertura do processo filho
      exit(1);  
    case 0:        // acoes do Filho
      printf( "\t Eu sou o processo %d, filho de %d \n", getpid(), getppid()); 
      printf( "\t Vou entrar num LOOP infinito\n");
      while(1);  // loop infinito   
    break;
    default:      // acoes do Pai    
      sleep(3);
      printf(" Eu sou o processo Pai numero %d\n", getpid());
      printf(" Fim do Processo Pai\n");
    break;
    }
 
    system("ps ");
    printf("Terminando o programa fork1 ... \n");
    return 0;

}
