// UFRN-CT-DCA, Primeiro semestre de 2003
// Programacao para Tempo Real
// Programa: tempo1e2


#include <iostream> // para: cout
#include <time.h>   // para: time()
#include <unistd.h>



using std::cout;
using std::cin;


int main ( )
{

  time_t tempo_real_antes, tempo_real_depois;
  
  int numero;

  tempo_real_antes = time( (time_t *) 0);  // apontando o ponteiro para null.
  cout << "Ja se passaram  " << tempo_real_antes << " segundos desde 0:00:00 de 01/01/1970 " << '\n';

  cout << "Escreva um numero inteiro :  " << '\n';
  cin >> numero;

 tempo_real_depois = time( (time_t *) 0);  // apontando o ponteiro para null.
 cout << "Agora, ja se passaram  " << tempo_real_depois << " segundos desde 0:00:00 de 01/01/1970 " << '\n';

 cout << "Voce gastou " << difftime(tempo_real_depois, tempo_real_antes) << " segundos para escrever o numero" << '\n';
  return 0;
}

