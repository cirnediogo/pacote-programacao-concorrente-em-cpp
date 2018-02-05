#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{

// declaracao de variaveis
  pid_t pid;          // definindo um identificador de processo - inteiro longo
  char *mensagem;     // string que contem a mensagem
  int n;              // contador
   
  printf("Comecando o programa fork1 ... \n");
  pid = fork();   // dividindo o processo em dois
  switch(pid)
    {
    case -1:       // erro na abertura do processo filho
      exit(1);  
    case 0:        // retorno de fork para processo filho
      system("ps "); 
      mensagem = "                   Processo filho...";
      n = 5;
      break;
    default:
      mensagem = "Processo pai ...";
      n = 3;
      break;
    }
 
  for(;n>0;n--) {
    printf("Valor de pid %d   ",pid);
    puts(mensagem);
    sleep(1);
  }
  printf("Terminando o programa fork1 ... \n");
  return 0;

}
