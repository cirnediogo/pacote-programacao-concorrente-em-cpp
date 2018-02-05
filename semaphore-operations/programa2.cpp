#include <stdio.h>


#include "Class_sem.cpp"
             

int  main()
{

  int i;
  //Class_sem(key_t chave,int valor_inicial_do_semaforo,flags_de_permissao);
  
 //Class_sem sem1(1234,0,0666|IPC_EXCL);
  Class_sem sem1(1234, 1,0666|IPC_CREAT);
  i = 0;
  while(1)
    { 
      i= i+ 1;
      printf("Sou o programa2\n ");
      printf("Vou Executar o m�todo P()\n");
      sem1.P();
      printf("Vou dormir por 1s, se o programa2 deixar! \n");
      printf("N�mero do sono = %d\n", i);
      sleep(1);
      printf("Vou Executar o m�todo V()\n");
      sem1.V();
      sleep(1);
      printf("Vou terminar\n");
      //exit(EXIT_SUCCESS);
    }

}
