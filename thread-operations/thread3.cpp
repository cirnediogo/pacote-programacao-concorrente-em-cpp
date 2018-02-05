/* 
 Descri��o:
 - Programa que cria 3 threads.
 Compilar: g++ -pthread -o nomeExecutavel nomeDesseArquivo
*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 3

//Estrutura usada como par�metro da funcaoHelper
struct dataParam{
   int  idThread;
   int	valor;
};

// Fun��o auxiliar da thread
void* funcaoHelper(void* param) {
  printf("Thread.id: %d\n", ((struct dataParam *) param)->idThread);
  printf("Thread.valor: %d\n", ((struct dataParam *) param)->valor);
  //Finalizar de forma expl�cita a thread
  pthread_exit(NULL);
}  

int main(int argc, char *argv[]) {

  //Vetor de threads
  pthread_t vetorThreads[NUM_THREADS];

  //Vetor da estrutura de par�metro
  struct dataParam vetorParam[NUM_THREADS];

  //Status de cria��o
  int statusRetorno;

  //Loop para criar as threads
  for(int i=0; i < NUM_THREADS; i++){
      //Inicializando o vetor de parametros
      vetorParam[i].idThread = i;
      vetorParam[i].valor = i*10;

      printf("Criando a thread: %d\n", i);
      //Criar a thread i
      statusRetorno = pthread_create(&vetorThreads[i], NULL, funcaoHelper, (void *)&vetorParam[i]);
      //Verificando a exist�ncia de erros na cria��o
      if (statusRetorno){
         printf("Erro ao criar a thread: %d\n", statusRetorno);
         exit(-1);
      }
   }
   printf("Finalizando o m�todo main\n");
   pthread_exit(NULL);
}
