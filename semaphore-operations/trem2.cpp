#include <stdio.h>


#include "Class_sem.cpp"
          

int  main()
{
//Class_sem(key_t chave,int valor_inicial_do_semaforo,flags_de_permissao);
  Class_sem sem7(1207, 1,0666|IPC_CREAT);
  Class_sem sem3(1203, 1,0666|IPC_CREAT);
  Class_sem sem8(1208,0666|IPC_EXCL); 
  Class_sem sem9(1209,0666|IPC_EXCL); 
  
  int t_sono_l3, t_sono_l6, t_sono_l7, t_sono_l8, t_sono_l9;
  t_sono_l3 = 5;
  t_sono_l6 = 1;
  t_sono_l7 = 1;
  t_sono_l8 = 1;
  t_sono_l9 = 1;
  
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
      printf("Sou o trem2, estou no trilho L6\n");
      printf("Vou dormir por %ds\n", t_sono_l6);
      sleep(t_sono_l6);
      printf("Vou pegar o semaforo do trilho L7\n");
      
      sem7.P();

      printf("Vou pegar o semaforo do trilho L8\n");
      
      sem8.P();

      printf("Vou pegar o semaforo do trilho L9\n");
      
      sem9.P();

      printf("Vou pegar o semaforo do trilho L3\n");
      
      sem3.P();

      printf("Sou o trem2, estou no trilho L7\n");
      printf("Vou dormir por %ds\n", t_sono_l7);
      sleep(t_sono_l7);
      printf("Vou devolver o semaforo do trilho L7\n");
      
      sem7.V();
      
      printf("Sou o trem2, estou no trilho L8\n");
      printf("Vou dormir por %ds\n", t_sono_l8);
      sleep(t_sono_l8);
      printf("Vou pegar o semaforo do trilho L8\n");

      sem8.P();

      printf("Sou o trem2, estou no trilho L9\n");
      printf("Vou dormir por %ds\n", t_sono_l9);
      sleep(t_sono_l9);
      printf("Vou devolver o semaforo do trilho L9\n");
      
      sem9.V();
      
      printf("Sou o trem2, estou no trilho L3\n");
      printf("Vou dormir por %ds\n", t_sono_l3);
      sleep(t_sono_l3);
      printf("Vou devolver o semaforo do trilho L3\n");
      
      sem3.V();
      
      //exit(EXIT_SUCCESS);
    }

}