// Programa Class_sem.cpp
// Programa para implementa uma classe de sem�foro escalar de Dijsktra.

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun 
 {
   int val;
   
};
             
class Class_sem
{
 public:
    int sem_id; // identificador do sem�foro
    int num_sems; // n�mero de sem�foros- sugere-se valor igual a 1: sem�foro escalar
    union  semun sem_union; // union utilizada para a fun��o semtcl()
    struct sembuf sem_b;   // estrutura utilizado para semop()
    int retorno_inicio, valor_final;
  
    Class_sem(key_t chave, int val_inicial, int sem_flags)
    {

    // val_inicial - valor sugerido = 1
    // sem_flags - valor sugerido = 0666 | IPC_CREAT

    num_sems = 1;
    sem_b.sem_num = 0; // uma opera��o
    sem_b.sem_flg = SEM_UNDO;
   
    sem_union.val = val_inicial;

    
    // criando um sem�foro
    sem_id = semget(chave,num_sems, sem_flags); 
    
    // iniciando o sem�foro
    printf("Cirado semaforo de id %d, e chave %d", sem_id, chave);
    
    retorno_inicio = semctl(sem_id,0,SETVAL, sem_union);
    }  

   Class_sem(key_t chave,int sem_flags)
    {

    // val_inicial - valor sugerido = 1
    // sem_flags - valor sugerido = 0666 | IPC_CREAT

    num_sems = 1;
    sem_b.sem_num = 0; // uma opera��o
    sem_b.sem_flg = SEM_UNDO;
   
        
    // criando um sem�foro
    sem_id = semget(chave,num_sems, sem_flags); 
    
    }  

   void P(void)
   {
    sem_b.sem_op = -1;
    semop(sem_id, &sem_b,1);
   }

   void V(void)
   {
    sem_b.sem_op = 1; 
    semop(sem_id, &sem_b,1);
   }

  ~Class_sem(void)
   {
     // union semun sem_union2;
     valor_final = semctl(sem_id,0,IPC_RMID,sem_union);
   }
};
