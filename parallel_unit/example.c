#include "parallel_unit.h"

// typedef struct{
// 
//     sem_t* gate;
//     sem_t* done;
//     
//     pthread_t* threads;
// 
//     void** args;
// 
//     size_t num_threads;
// 
// }parallel_unit;

// il massimo (?)
// #define TEST_NUM 39923

#define TEST_NUM 15

void* funzione(void*arg){
    
    int id = ((int*)arg)[0];

    printf("Thread Number: %d\n",id);

    // the return value is never checked, so... doesn't really matters...
    return NULL;
}


int main(void) {
    int buffer[TEST_NUM];
    for(size_t i=0;i<TEST_NUM;i++) buffer[i]=i;

    parallel_unit pu = create_parallel_unit(TEST_NUM,funzione);

    for(size_t i=0;i<pu.num_threads;i++){
        pu.args[i] = &buffer[i];
    }

    printf("--- first  execution ---\n");
    execute_parallel_unit(pu);
    printf("--- second execution ---\n");
    execute_parallel_unit(pu);
    
    destroy_parallel_unit(pu);

    printf("Per vedere se non esplode tutto dopo la destroy\n");
}

// to compile, stay in the directory of this file and the run: 
//      gcc example.c parallel_unit.c -o example
