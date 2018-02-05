// Programa sinal1.cpp
// Sinais s�o eventos gerados pelo Unix em resposta a algumas condi��es:
//  erros, viola��o de mem�ria, instru��a ilegal, ...


// Processo mandando um sinal si mesmo: ;
// 

#include <signal.h> // defini��o dos sinais de interrup��es
#include <stdio.h>
#include <unistd.h>




void ouch (int sig)
{
  printf("Ah, Ah, Ah-  Eu nao morro com : %d \n", sig);
  printf("Peno menos, da primeira vez. Tente denovo..\n");
  signal(SIGINT, SIG_DFL);
}

int main()
{
  (void) signal(SIGINT, ouch); // SIGINT - Terminal Interrupt
  int tempo_de_sono = 0;

  while(1) {
    printf("Alo Mundo Cruel! Voo dormir por  1 segundo.\n");
    sleep(1);
    tempo_de_sono = tempo_de_sono + 1; 
    if(tempo_de_sono >= 10 )
      {
        printf("Vou me matar.\n");
	kill(getpid(),SIGKILL);
      
      }

  }
  // exit(0);
}

