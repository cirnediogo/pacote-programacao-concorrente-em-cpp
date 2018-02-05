#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main ()
{
 printf("Rodando o comando ps com system: Inicio \n");
 // system ("ps -ax");
 printf("     eu sou o sistema\n");
 printf("     meu pid: %d\n",getpid());
 printf("     pid do meu pai: %d\n", getppid());
 
 system ("g++ tempo2.cpp -o tempo2");
 system ("./tempo2");
 printf("Rodando o comando ps com system: Fim \n");
 return 0;
}