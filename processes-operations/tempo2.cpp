// UFRN-CT-DCA, Primeiro semestre de 2003
// Programacao para Tempo Real
// Programa: tempo2


#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()

using std::cout;


main ( )
{

  double x = 1;
  printf("eu sou o tempo2\n");
  printf("meu pid: %d\n",getpid());
  printf("pid do meu pai: %d\n", getppid());
  
  for(int i=0; i<5; i++) {
    sleep(i);
   cout << x +i << '\n';
  }
  cout << "Buummmm\n";
  //   std::cout << x <<'\n'; 
}
