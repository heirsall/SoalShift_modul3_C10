#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
 
pthread_t tid[6];
int step;
void* buatfile(void *arg)
{
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[0]))
    {
        system("ps aux | head -10 > /home/zahrul/Documents/FolderProses1/SimpanProses1.txt");
}
    if(pthread_equal(id,tid[1]))
    {
     
        system("ps aux | head -10 > /home/zahrul/Documents/FolderProses2/SimpanProses2.txt");
    }
    step =1;
    return NULL;
}

void* compress(void *arg)
{
    while(step != 1)
    {

    }
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[2]))    {
        system("zip -qmj /home/zahrul/Documents/FolderProses1/KompresProses1.zip /home/zahrul/Documents/FolderProses1/SimpanProses1.txt");


    }
if(pthread_equal(id,tid[3]))
    {
        system("zip -qmj /home/zahrul/Documents/FolderProses2/KompresProses2.zip /home/zahrul/Documents/FolderProses2/SimpanProses2.txt");

    }
    

    step =2;
    return NULL;

}

void* extract(void *arg)
{
    while(step !=2)
    {

    }
    printf("Menunggu 15 detik untuk mengekstrak kembali\n");
	int x = 1;
	while(x!=16){    
	sleep(1);		
	printf("%d\n",x);
	x=x+1;
		
	}
    
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[4]))
    {
    	
        system("unzip -qd /home/zahrul/Documents/FolderProses1/ /home/zahrul/Documents/FolderProses1/KompresProses1.zip");

        system("unzip -qd /home/zahrul/Documents/FolderProses2/ /home/zahrul/Documents/FolderProses2/KompresProses2.zip");
        
    }
    step =3;
    return NULL;
}

int main(void)
{
    unsigned long masuk=0,k=0;
    int err;
    
    while(masuk<2)
    {
        err=pthread_create(&(tid[masuk]),NULL,&buatfile,NULL);
   
        masuk++;
    }
	if(masuk >= 2)
    while(masuk<4)
    {
        err=pthread_create(&(tid[masuk]),NULL,&compress,NULL);
 
        masuk++;
    }
	if(masuk >= 4)
    while(masuk<6)
    {
        err=pthread_create(&(tid[masuk]),NULL,&extract,NULL);
        masuk++;
    }
    
    while(k<6){
	
    pthread_join(tid[k],NULL);
    k++;
	}
    
    return 0;
}
