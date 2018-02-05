// Programa sinal4.cpp
// Sinais s�o eventos gerados pelo Unix em resposta a algumas condi��es:
//  erros, viola��o de mem�ria, instru��a ilegal, ...


// Processo mandando um alarme
// 

#include <signal.h> // defini��o dos sinais de interrup��es
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>




void alarme (int sig)
{
  printf("Alarme foi desligado. \n");
 
}

int main()
{
  // o processo filho espera por 5 segundos antes de enviar um sinal SIGALRM para seu pai

  int pid;
 

  printf("O alarme foi disparado. \n");

  if ( (pid = fork()) == 0)
  {
    // c�digo do processo filho
    printf("\n\n            Execucao do Filho- vai dormir por 5 segundos\n");
    sleep(5);
    kill(getppid(), SIGALRM);
    printf("            Execucao do Filho- filho vai morrer\n\n");
    exit(0);
  }
  printf("Pai esperando pelo Sinal de alarme desligar (5s). \n");
  //(void) signal(SIGALRM, alarme);
  printf(" Apos a funcao signal()\n");
  pause();
  printf("O sinal de alarme chegou ao Pai .\n");
  exit(0);
  
  // exit(0);
}
