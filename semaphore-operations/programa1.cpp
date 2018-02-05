#include <stdio.h>


#include "Class_sem.cpp"
          

int  main()
{
//Class_sem(key_t chave,int valor_inicial_do_semaforo,flags_de_permissao);
  Class_sem sem1(1234, 1,0666|IPC_CREAT);
  int i, t_sono;
  
  printf("D� o valor do tempo de sono = ");
  scanf("%d", &t_sono);
  printf("\n Ent�o o programa vai dormir por intervalos de %d segundos\n", t_sono);

  i = 0;
  
  while(i< 10)
    {
      i = i+ 1;
        
      printf("Sou o programa1\n");
      printf("Vou Executar o m�todo P()\n");
      sem1.P();
      printf("Vou dormir por %ds\n", t_sono);
      printf("N�mero do sono = %d\n", i);
      sleep(t_sono);
      printf("Vou Executar o m�todo V()\n");
      sem1.V();
      sleep(1);
      printf("Vou terminar\n");
      //exit(EXIT_SUCCESS);
    }

}
