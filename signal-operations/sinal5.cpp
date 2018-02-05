// Programa sinal5.cpp -- utiliza��o do sinal ALARME

#include <signal.h>
#include <unistd.h>
#include <stdio.h>


void detecao_alarme (int sig)
{
  printf("O sinal %d foi recebido: SIGALRM\n", sig);
}

main()
{
  unsigned segundos;
  signal(SIGALRM, detecao_alarme); // intercepta��o do sinal
  printf("Gerando o alarme em 5s\n");
  segundos = alarm(5);
  printf("Valor retornado pela funcao alarm(): %d\n",segundos);
  printf("Vai entrar num loop infinito (CTRL-C para acabar)\n");
  while(1)
  {
    sleep(1);
    printf("Estou num loop infinito\n");
    printf("CTRL-C para me matar\n");
   }
}

