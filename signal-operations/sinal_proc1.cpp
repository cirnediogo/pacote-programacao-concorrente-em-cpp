// Programa sinal_proc1.cpp
// Sinais s�o eventos gerados pelo Unix em resposta a algumas condi��es:
//  erros, viola��o de mem�ria, instru��a ilegal, ...


// Processo mandando um alarme
// 

#include <signal.h> // defini��o dos sinais de interrup��es
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>




void sinal_de_morte (int sig)
{
  printf("Recebi um tiro fatal. \n");
 
}

int main()
{
  // o processo que vai esperar pelo sinal de morte

  int meu_pid;

  meu_pid = getpid();
    
 
  //(void) signal(SIGKILL, sinal_de_morte);

  while(1)
  {
    printf("Meu pid e: %d \n", meu_pid);
    printf("Vou dormir por 2 segundos e esperar que alguem me mata \n");
    sleep(2);
  }

  //(void) signal(SIGKILL, sinal_morte);
  //   printf(" Ap�s a fun��o signal()\n");
  // pause();
  // exit(0);
}
