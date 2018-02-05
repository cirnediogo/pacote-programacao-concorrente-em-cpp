// Programa sinal1.cpp
// Sinais s�o eventos gerados pelo Unix em resposta a algumas condi��es:
//  erros, viola��o de mem�ria, instru��a ilegal, ...

#include <signal.h> // defini��o dos sinais de interrup��es
#include <stdio.h>
#include <unistd.h>




void ouch (int sig)
{
  static int cont = 1;
  printf("Ah, Ah, Ah-  Eu nao morro com : %d \n", sig);
  printf("Peno menos, ainda nao. Tente denovo..\n");
  cont += 1;
  if (cont == 4) {
    signal(SIGINT, SIG_DFL);
  }
}

int main()
{
  (void) signal(SIGINT, ouch); // SIGINT - Terminal Interrupt

  while(1) {
    printf("Alo Mundo Cruel! Voo dormir por  1 segundo.\n");
    sleep(1);
  }
  // exit(0);
}

