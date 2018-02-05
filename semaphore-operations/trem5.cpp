#include <stdio.h>


#include "Class_sem.cpp"
          

int  main()
{
//Class_sem(key_t chave,int valor_inicial_do_semaforo,flags_de_permissao);
  Class_sem sem8(1208, 1,0666|IPC_CREAT);
  Class_sem sem13(1213, 1,0666|IPC_CREAT);
  Class_sem sem15(1215,0666|IPC_EXCL);
  
  int t_sono_l8, t_sono_l13, t_sono_l17, t_sono_l18, t_sono_l15;
  t_sono_l8 = 8;
  t_sono_l13 = 8;
  t_sono_l17 = 1;
  t_sono_l18 = 1;
  t_sono_l15 = 8;
  
  //printf("D� o valor do tempo de sono no trilho L5 = ");
  //scanf("%d", &t_sono_l5);
  //printf("D� o valor do tempo de sono no trilho L6 = ");
  //scanf("%d", &t_sono_l6);
  //printf("D� o valor do tempo de sono no trilho L7 = ");
  //scanf("%d", &t_sono_l7);
  //printf("D� o valor do tempo de sono no trilho L3 = ");
  //scanf("%d", &t_sono_l3);

  while(1)
    {
      printf("Sou o trem5, estou no trilho L18\n");
      printf("Vou dormir por %ds\n", t_sono_l18);
      sleep(t_sono_l18);
      printf("Vou pegar o semaforo do trilho L15\n");
      
      sem15.P();

      printf("Vou pegar o semaforo do trilho L8\n");
      
      sem8.P();

      printf("Vou pegar o semaforo do trilho L13\n");
      
      sem13.P();

      printf("Sou o trem5, estou no trilho L15\n");
      printf("Vou dormir por %ds\n", t_sono_l15);
      sleep(t_sono_l15);
      printf("Vou devolver o semaforo do trilho L15\n");
      
      sem15.V();
      
      printf("Sou o trem5, estou no trilho L8\n");
      printf("Vou dormir por %ds\n", t_sono_l8);
      sleep(t_sono_l8);
      printf("Vou pegar o semaforo do trilho L8\n");

      sem8.P();

      printf("Sou o trem5, estou no trilho L13\n");
      printf("Vou dormir por %ds\n", t_sono_l13);
      sleep(t_sono_l13);
      printf("Vou devolver o semaforo do trilho L13\n");
      
      sem13.V();
      
      printf("Sou o trem5, estou no trilho L17\n");
      printf("Vou dormir por %ds\n", t_sono_l17);
      sleep(t_sono_l17);
      
      //exit(EXIT_SUCCESS);
    }

}