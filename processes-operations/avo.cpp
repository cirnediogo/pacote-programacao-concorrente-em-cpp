#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{

// declaracao de variaveis
  pid_t pid1, pid2;          // definindo um identificador de processo - inteiro longo
  char *mensagem = "Processo avo...";     // string que contem a mensagem
  int n = 10;              // contador
   
  printf("Comecando o programa avo ... \n");
  for(;n>0;n--) {
    printf("meu pai eh %d , meu pid eh %d      ",getppid(),getpid());
    puts(mensagem);
    sleep(1);
  }
  
  pid1 = fork();   // dividindo o processo em dois
  switch(pid1)
    {
    case -1:       // erro na abertura do processo filho
      exit(1);
    case 0:        // retorno de fork para processo filho
      mensagem = "Processo filho1...";
      n = 30;
      for(;n>0;n--) {
       printf("meu pai eh %d , meu pid eh %d      ",getppid(),getpid());
       puts(mensagem);
       sleep(1);
      }  
      break;
    default:
      
      mensagem = "Processo avo ...";
      n = 10;
      for(;n>0;n--) {
       printf("meu pai eh %d , meu pid eh %d      ",getppid(),getpid());
       puts(mensagem);
       sleep(1);
      }
      pid2 = fork();
      switch(pid2) {
	case -1: exit(1);
	case 0:
	mensagem = "Processo filho2...";
        n = 30;
        for(;n>0;n--) {
         printf("meu pai eh %d , meu pid eh %d      ",getppid(),getpid());
         puts(mensagem);
         sleep(1);
        }
	break;
	default:
	mensagem = "Processo avo ...";
         n = 10;
         for(;n>0;n--) {
          printf("meu pai eh %d , meu pid eh %d      ",getppid(),getpid());
          puts(mensagem);
          sleep(1);
         }  
      }
      break;
    }
 
  //for(;n>0;n--) {
  //  printf("Valor de pid %d     pid do pai eh %d      ",pid, getppid());
  //  puts(mensagem);
  //  sleep(1);
 // }
  printf("Terminando o processo ");
  puts(mensagem);
  return 0;

}
