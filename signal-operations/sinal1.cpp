// Programa sinal1.cpp
// Sinais s�o eventos gerados pelo Unix em resposta a algumas condi��es:
//  erros, viola��o de mem�ria, instru��a ilegal, ...

#include <signal.h> // defini��o dos sinais de interrup��es
#include <stdio.h>
#include <unistd.h>




void ouch (int sig)
{
  printf("Ah, Ah, Ah-  Eu nao morro com : %d \n", sig);
  printf("Eu so morro com kill -9 \n");
  printf("Digite o comando ps -aux e identifique o meu numero \n");
  printf("Depois, mate-me com kill -9 <pid> \n");
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
