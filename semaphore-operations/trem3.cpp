#include <stdio.h>


#include "Class_sem.cpp"
             

int  main()
{

  //Class_sem(key_t chave,int valor_inicial_do_semaforo,flags_de_permissao);
  
 //Class_sem sem1(1234,0,0666|IPC_EXCL);
  Class_sem sem7(1207,0666|IPC_EXCL);
  Class_sem sem13(1213,0666|IPC_EXCL);
  
  int t_sono_l7, t_sono_l10, t_sono_l11, t_sono_l12, t_sono_l13;
  t_sono_l7 = 8;
  t_sono_l10 = 1;
  t_sono_l11 = 1;
  t_sono_l12 = 1;
  t_sono_l13 = 8;
  
  //printf("D� o valor do tempo de sono no trilho L9 = ");
  //scanf("%d", &t_sono_l9);
  //printf("D� o valor do tempo de sono no trilho L10 = ");
  //scanf("%d", &t_sono_l10);
  //printf("D� o valor do tempo de sono no trilho L6 = ");
  //scanf("%d", &t_sono_l6);
  //printf("D� o valor do tempo de sono no trilho L8 = ");
  //scanf("%d", &t_sono_l8);
  
  while(1)
    { 
      printf("Sou o trem3, estou no trilho L10\n");
      printf("Vou dormir por %ds\n", t_sono_l10);
      sleep(t_sono_l10);
      
      printf("Sou o trem3, estou no trilho L11\n");
      printf("Vou dormir por %ds\n", t_sono_l11);
      sleep(t_sono_l11);
      
      printf("Sou o trem3, estou no trilho L12\n");
      printf("Vou dormir por %ds\n", t_sono_l12);
      sleep(t_sono_l12);
      printf("Vou pegar o semaforo do trilho L13\n");
      
      sem13.P();
      
      printf("Vou pegar o semaforo do trilho L7\n");
      
      sem7.P();
      
      printf("Sou o trem3, estou no trilho L13\n");
      printf("Vou dormir por %ds\n", t_sono_l13);
      sleep(t_sono_l13);
      printf("Vou devolver o semaforo do trilho L13\n");

      sem13.V();

      printf("Sou o trem3, estou no trilho L7\n");
      printf("Vou dormir por %ds\n", t_sono_l7);
      sleep(t_sono_l7);
      printf("Vou devolver o semaforo do trilho L7\n");

      sem7.V();

      //exit(EXIT_SUCCESS);
    }

}