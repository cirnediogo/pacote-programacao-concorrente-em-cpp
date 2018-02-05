#include <stdio.h>


#include "Class_sem.cpp"
          

int  main()
{
//Class_sem(key_t chave,int valor_inicial_do_semaforo,flags_de_permissao);
  Class_sem sem5(1205, 1,0666|IPC_CREAT);
  Class_sem sem9(1209, 1,0666|IPC_CREAT);
  Class_sem sem15(1215, 1,0666|IPC_CREAT);
  
  int t_sono_l5, t_sono_l9, t_sono_l15, t_sono_l16, t_sono_l14;
  t_sono_l5 = 8;
  t_sono_l9 = 8;
  t_sono_l15 = 8;
  t_sono_l16 = 1;
  t_sono_l14 = 1;
  
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
      printf("Sou o trem4, estou no trilho L14\n");
      printf("Vou dormir por %ds\n", t_sono_l14);
      sleep(t_sono_l14);
      printf("Vou pegar o semaforo do trilho L5\n");
      
      sem5.P();

      printf("Vou pegar o semaforo do trilho L9\n");
      
      sem9.P();

      printf("Vou pegar o semaforo do trilho L15\n");
      
      sem15.P();

      printf("Sou o trem4, estou no trilho L5\n");
      printf("Vou dormir por %ds\n", t_sono_l5);
      sleep(t_sono_l5);
      printf("Vou devolver o semaforo do trilho L5\n");
      
      sem5.V();
      
      printf("Sou o trem4, estou no trilho L9\n");
      printf("Vou dormir por %ds\n", t_sono_l9);
      sleep(t_sono_l9);
      printf("Vou pegar o semaforo do trilho L9\n");

      sem9.P();

      printf("Sou o trem4, estou no trilho L15\n");
      printf("Vou dormir por %ds\n", t_sono_l15);
      sleep(t_sono_l15);
      printf("Vou devolver o semaforo do trilho L15\n");
      
      sem15.V();
      
      printf("Sou o trem4, estou no trilho L16\n");
      printf("Vou dormir por %ds\n", t_sono_l16);
      sleep(t_sono_l16);
      
      //exit(EXIT_SUCCESS);
    }

}