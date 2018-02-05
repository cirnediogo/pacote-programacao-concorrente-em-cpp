// UFRN-CT-DCA, Primeiro semestre de 2003
// Programacao para Tempo Real
// Programa: tempo1e


#include <iostream> // para: cout
#include <time.h>   // para: time()
#include <unistd.h>



using std::cout;
using std::cin;


int main ( )
{

  time_t tempo_real;
  
  int numero;

  tempo_real = time( (time_t *) 0);  // apontando o ponteiro para null.
  cout << "Ja se passaram  " << tempo_real << " segundos desde 0:00:00 de 01/01/1970 " << '\n';

  cout << "Escreva um numero inteiro :  " << '\n';
  cin >> numero;

 tempo_real = time( (time_t *) 0);  // apontando o ponteiro para null.
 cout << "Ja se passaram  " << tempo_real << " segundos desde 0:00:00 de 01/01/1970 " << '\n';

  return 0;
}
