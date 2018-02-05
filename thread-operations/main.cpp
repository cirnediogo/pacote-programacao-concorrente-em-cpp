/*

Exemplo de 4 trilhos
       1 2 .... .....7 
        _ _ _ _ _ _ _
   18  |             |   8  
   17  |_ _ _ _ _ _ _|   9

       16........... 10
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Trem.h"

int
main(int argc, char *argv[])
{

  //  Criando os caminhos dos trilhos
  const int aux_caminho1[] = {1,2,3,4,5,6,7};
  const int aux_caminho2[] = {8,9};
  const int aux_caminho3[] = {10,11,12,13,14,15,16};
  const int aux_caminho4[] = {17,18};

  vector<int> caminho1(aux_caminho1,aux_caminho1+7);
  vector<int> caminho2(aux_caminho2,aux_caminho2+2);
  vector<int> caminho3(aux_caminho3,aux_caminho3+7);
  vector<int> caminho4(aux_caminho4,aux_caminho4+2);

  Trilhos *trilho1 = new Trilhos(caminho1,1);
  Trilhos *trilho2 = new Trilhos(caminho2,2);
  Trilhos *trilho3 = new Trilhos(caminho3,3);
  Trilhos *trilho4 = new Trilhos(caminho4,4);

  //Fim da criação dos trilhos
  
  // Criando os semaforo usados no programa
  Semaforo *sem1;

  // VARIAVEIS DO TREM

  // vetor de semaforos
  vector<Semaforo*> vetorSemaforo;
  vetorSemaforo.push_back(sem1);

  // vetor de trilhos
  vector<Trilhos*> vetorTrilhos;
  vetorTrilhos.push_back(trilho1);
  vetorTrilhos.push_back(trilho2);
  vetorTrilhos.push_back(trilho3);
  vetorTrilhos.push_back(trilho4);

  //Criando um Trem
  Trem *trem1 = new Trem(1,vetorSemaforo,vetorTrilhos,2);

  //Inicializando o trem
  trem1->start();

  pthread_exit(NULL);
  return 0;
}

