// Programa sinal_proc1.cpp
// Sinais s�o eventos gerados pelo Unix em resposta a algumas condi��es:
//  erros, viola��o de mem�ria, instru��a ilegal, ...


// Processo mandando um alarme
// 

#include <signal.h> // defini��o dos sinais de interrup��es
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int  main()
{
  // o processo que vai motar

  int meu_pid=99;
  int pid_vitima=4213;

  meu_pid = getpid();
    

  
 printf( "Eu sou um programa matador de programa \n" );
 printf( "Digite o pid do processo que deve morrer: ");
 scanf( "%d", &pid_vitima);
 printf("\n Vou matar o processo %d \n", pid_vitima);
  
 kill(pid_vitima, SIGKILL);
 printf( "\nAgora posso morrer\n");
 exit(0);
}


