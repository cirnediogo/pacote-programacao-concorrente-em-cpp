// UFRN-CT-DCA, Primeiro semestre de 2003
// Programacao para Tempo Real
// Programa: tempo3


#include <iostream> // para: cout
#include <time.h>     // para: gmtime()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // para: sleep()

using std::cout;


int  main ( )
{

  struct tm *tm_ptr; // um ponteiro para a estrutura tm
  time_t  tempo_valor;  // variavel para armazenar o tempo em segundos

  (void) time(&tempo_valor);  // outra forma de armazenar o tempo em segundos 
  tm_ptr = gmtime(&tempo_valor); // obtendo a esttutura

  cout <<"Programa que utiliza varias funcoes de captura de data ";

  cout << "O tempo em segundos e;  " << tempo_valor << '\n';
  cout << "Saida padronizada " << '\n';
  cout << "Data: " << tm_ptr->tm_mday << "/" << tm_ptr->tm_mon +1 << "/" <<1900 + (tm_ptr->tm_year) << '\n';


  cout << "\n\n";
  cout << "Usando a funcao ctime( )\n";     
  cout << "Tempo Atual: " << ctime(&tempo_valor) << '\n';

  cout << "\n\n";
  cout << "Usando a funcao asctime( )\n";     
  cout << "Tempo Atual: " << asctime(tm_ptr) << '\n';

  return 0;

}
