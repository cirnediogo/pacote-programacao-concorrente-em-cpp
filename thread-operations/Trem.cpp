/*
  Classe servirá de base para o problema dos trens
  Na modelagem, um trem pode ser considerado uma
  thread.
*/

#include "Trem.h"
#include <stdio.h>
#include <unistd.h>

/*
  O construtor da classe Trem
  Parametros:
  identificador  - id do trem
  vetorSemaforos - vetor com os semaforos utilizados pelo trem
  vetorTrilhos
*/
Trem::Trem( int id,
            vector<Semaforo*> vetorSem,
	    vector<Trilhos*> vetorTr,
            int speed
           )           
{
  idTrem = id;
  vetorSemaforos = vetorSem;
  vetorTrilhos = vetorTr;
  posicao[0] = 0;
  posicao[1] = 0;
  velocidade = speed;
}

/*
  Destrutor não faz nada. Colocar alguma ação se necessário
*/
Trem::~Trem()
{}

/*
  Metodo utilizado para deslocar o trem sobre os trilhos
*/

void 
Trem::mover()
{
  // Verificar se já atingiu o limite do caminho dentro do Trilho atual
  if (posicao[1] == ( ( vetorTrilhos.at(posicao[0]) )->getCaminho() ).capacity() -1)
  {
    //Verificar se já foi dado uma volta completa
    if (posicao[0] == vetorTrilhos.capacity() - 1)
    {
      posicao[0] = 0;
      posicao[1] = 0;
    }
    //Se uma volta ainda não foi dada, incrementa para o inicio do proximo trilho
    else
    {
      posicao[0]++;
      posicao[1] = 0;
    }
  }
  //Apenas incrementa o caminho atual
  else
  {
    posicao[1]++;
  }
}


/*
  Metodo que implementara o loop de execução da thread
*/
void
Trem::run()
{
  while(true)
  {
     if (idTrem == 1){
      printf("Piuiiiiiiiiii, sou o trem: %d\n", idTrem);
      printf("Minha posicao: %d\n\n", ( ( vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) );
      mover();
      sleep(velocidade);
     }
  }
}

/*
  Métodos get e set. São utilizados para alterar e retornar
  os atributos private da classe. Isso garente o encapsulamento
  mantendo as boas práticas de programação
*/

int
Trem::getIdTrem() const
{
  return idTrem;
}

void
Trem::setIdTrem(int id)
{
  idTrem = id;
}
