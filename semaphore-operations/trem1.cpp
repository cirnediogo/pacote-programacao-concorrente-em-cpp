#include <stdio.h>


#include "Class_sem.cpp"
             

int  main()
{

  int i;
  //Class_sem(key_t chave,int valor_inicial_do_semaforo,flags_de_permissao);
  
 //Class_sem sem1(1234,0,0666|IPC_EXCL);
  Class_sem sem3(1203,1,0666|IPC_CREAT); 
  Class_sem sem5(1205,1,0666|IPC_CREAT); 
  
  int t_sono_l1, t_sono_l2, t_sono_l3, t_sono_l4, t_sono_l5;
  t_sono_l1 = 1;
  t_sono_l2 = 1;
  t_sono_l3 = 5;
  t_sono_l4 = 1;
  t_sono_l5 = 1;
  
  //printf("D� o valor do tempo de sono no trilho L1 = ");
  //scanf("%d", &t_sono_l1);
  //printf("D� o valor do tempo de sono no trilho L2 = ");
  //scanf("%d", &t_sono_l2);
  //printf("D� o valor do tempo de sono no trilho L3 = ");
  //scanf("%d", &t_sono_l3);
  //printf("D� o valor do tempo de sono no trilho L4 = ");
  //scanf("%d", &t_sono_l4);
  
  while(1)
    { 
      printf("Sou o trem1, estou no trilho L1\n");
      printf("Vou dormir por %ds\n", t_sono_l1);
      sleep(t_sono_l1);
      
      printf("Sou o trem1, estou no trilho L2\n");
      printf("Vou dormir por %ds\n", t_sono_l2);
      sleep(t_sono_l2);
      printf("Vou pegar o semaforo do trilho L3\n");
      
      sem3.P();
      
      printf("Vou pegar o semaforo do trilho L5\n");
      
      sem5.P();
      
      printf("Sou o trem1, estou no trilho L3\n");
      printf("Vou dormir por %ds\n", t_sono_l3);
      sleep(t_sono_l3);
      printf("Vou devolver o semaforo do trilho L3\n");

      sem3.V();

      printf("Sou o trem1, estou no trilho L5\n");
      printf("Vou dormir por %ds\n", t_sono_l5);
      sleep(t_sono_l5);
      printf("Vou devolver o semaforo do trilho L5\n");

      sem5.V();
      
      printf("Sou o trem1, estou no trilho L4\n");
      printf("Vou dormir por %ds\n", t_sono_l4);
      sleep(t_sono_l4);
      
      //exit(EXIT_SUCCESS);
    }

}