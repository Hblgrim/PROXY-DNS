#include "shared.h"


int id;
int get_Shared_mem(int key, int size){

    int sm;

    if((sm=shmget((key_t)key, size,  IPC_CREAT|0666)) == -1){
		perror("Error get shm");
        exit(1);
	}
    
    return sm;
}

void* write_shared_mem(void* structure, int size){
    void* ptr;
    ptr=shmat(id,NULL,0);
    
    if((ptr=shmat(id,NULL,0))== NULL){
        perror("Error write");
        exit(1);
    }

    memcpy(ptr, structure, size);
    return ptr;
}

void* get_add(int id){
	void* addresse;
	if((addresse = shmat(id,NULL,0)) == (void *) -1 ){
		perror("Error get addrsm");
        exit(1);
	}
	return addresse;
}


int free_shared_memory(void* shm){
    int sh;
    if( (sh=shmdt(shm) == -1)){
		perror("Error free fsm");
        exit(1);
	}
	return sh;
}

int free_sm(int id){
    int sh;
    if( ( sh=shmctl(id, IPC_RMID, NULL) ) == -1){
		perror("Error free fsm");
        exit(1);
	}
	return sh;
}