#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void* faktorial(void *a){ 
	int nilai=1;
	int x=*((int *)a);
	int y=x;
	while(x>0){
	nilai=nilai*x; x=x-1;
	}
	printf("%d!= %d\n", y, nilai);
    }

int sort(const void * a, const void * b) 
	{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char** argv){

    int hasil[120];
    for (int i = 1; i < argc; i++)
    	hasil[i-1]=atoi(argv[i]);
    qsort(hasil,argc-1,sizeof(int),sort);

    for(int i=0; i < argc-1; i++){
	pthread_t tid;
	pthread_create(&tid,NULL,faktorial,&hasil[i]);
	pthread_join(tid,NULL);
	}
	
    return 0;
}