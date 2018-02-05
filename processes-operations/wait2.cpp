#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{

// declaracao de variaveis
  pid_t pid;          // definindo um identificador de processo - inteiro longo
  char *mensagem;     // string que contem a mensagem
  int n;              // contador
  int exit_code;      // codigo para saida
   
  printf("Comecando o programa wait2 ... \n");
  pid = fork();   // dividindo o processo em dois
  switch(pid)
    {
    case -1:       // erro na abertura do processo filho
      exit(1);  
    case 0:        // retorno de fork para processo filho
      // system("ps "); 
      printf("\n\n");
      mensagem = "                   Processo filho...";
      n = 5;
      exit_code = 37; // codigo de sa?da do filho, tente colocar outros valores 39, 29 123 233
      break;
    default:
      mensagem = "Processo pai ...";
      n = 3;
      exit_code = 0;
      break;
    }
 
  for(;n>0;n--) {
    printf("Valor de pid %d   ",pid);
    puts(mensagem);
    sleep(1);
  }

  if(pid)
   {
      int stat_val;
      pid_t pid_filho;

      pid_filho = wait(&stat_val);

      printf("O Filho foi finalizado: PID = %d \n", pid_filho);

      // WIFEXITED(stat_val) - nao-zero se o filho terminou normalmente
      // WEXITSTATUS(stat_val) - se WIFEXITED ? nao-zero, retorna o codigo de saida do filho
      if( WIFEXITED(stat_val) ) 
          printf( "O Filho terminou com codigo  %d\n", WEXITSTATUS(stat_val) );
      else
          printf( "O Filho terminou de forma anormal \n");
    }
  printf( "Terminando o programa wait2 ... \n");
  return exit_code;
}
