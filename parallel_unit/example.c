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

#define NUM_THREADS 15

void* funzione(void*arg){
    
    int id = ((int*)arg)[0];

    printf("Thread Number: %d\n",id);

    // the return value is never checked, so... doesn't really matters...
    return NULL;
}


int main(void) {

    // We initialize a buffer with numbers that go from 0 to NUM_THREADS-1
    int buffer[NUM_THREADS];
    for(size_t i=0;i<NUM_THREADS;i++) buffer[i]=i;

    // We create a parallel_unit by passing the number of threads that we want on this unit and a function to associate to the threads
    parallel_unit pu = create_parallel_unit(NUM_THREADS,funzione);

    // We use pu.args to pass out parameters to each thread
    for(size_t i=0;i<pu.num_threads;i++){
        pu.args[i] = &buffer[i];
    }
    
    // Now we can call execute_parallel_unit(...) by passing out parallel unit
    // The main thread will wait until the execution of each thread has finished
    printf("--- first  execution ---\n");
    execute_parallel_unit(pu);
    
    // A parallel_unit acts as a Thread pool. We can execute it again without any thread creation overhead (but we won't have any return value)
    printf("--- second execution ---\n");
    execute_parallel_unit(pu);
    
    // We destroy the parallel unit, this will deallocate all the memory used internally and destroy the semaphores
    destroy_parallel_unit(pu);

}

// to compile, stay in the directory of this file and the run: 
//      gcc example.c parallel_unit.c -o example
