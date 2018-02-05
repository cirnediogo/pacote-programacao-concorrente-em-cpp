#include  <time.h>  // time()
//nclude <iostream> // para: cout
#include <stdio.h>
#include <unistd.h>  // para: sleep()
#include <stdlib.h>
#include <math.h>


//using std::cout;


// funcao para simular carregamento da CPU
void carga(int k)
{
  float f = 0.999999;
  for(int i=0; i<k; i++)
    {
      f = f*f*f*f*f;
      f = 1,56;
        for(int j=0; j<k; j++)
           {
	     f = sin(f)*sin(f)*f*f*f;

            }
    }

}


int main( ){

     clock_t time_1, time_2, saida;
     time_t  real_time_1, real_time_2, delta_real_time;

     double saida2;

     time_1 = clock();
     real_time_1 = time(0);
     carga(1000);
     sleep(3);
     real_time_2 = time(0);
     time_2 = clock();
     
     saida = (time_2) - (time_1);
     saida2 = (double) ((saida) / (double) CLOCKS_PER_SEC) ;

     delta_real_time = (real_time_2) - (real_time_1);

     printf("\n Tempo de uso da CPU em microsegundos: %d \n", saida);
     printf(" Tempo de uso da CPU em segundos: %f \n", saida2);

     printf(" Tempo Real decorrido em microsegundos: %d \n", (int) delta_real_time);

     printf("\n Qual e a diferenca entre as funcoes clock( ) e time( )? \n\n");

     return 1;

}
