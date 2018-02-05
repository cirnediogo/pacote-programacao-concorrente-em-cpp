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

// Fun��o auxiliar da thread
void* funcaoHelper(void* idThread) {
  sleep(3);
  printf("Thread: %d\n", (int)idThread);
  //Finalizar de forma expl�cita a thread
  pthread_exit(NULL);
}  

int main(int argc, char *argv[]){

  //Vetor de threads
  pthread_t vetorThreads[NUM_THREADS];

  //Status de cria��o
  int statusRetorno;

  //Loop para criar as threads
  for(int i=0; i < NUM_THREADS; i++){
      printf("Criando a thread: %d\n", i);
      //Criar a thread i
      statusRetorno = pthread_create(&vetorThreads[i], NULL, funcaoHelper, (void *)i);
      //Verificando a exist�ncia de erros na cria��o
      if (statusRetorno){
         printf("Erro ao criar a thread: %d\n", statusRetorno);
         exit(-1);
      }
   }
   printf("Finalizando o m�todo main\n");
   exit(0); //deleta todas as threads
}
