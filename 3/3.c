#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[4];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int angka=0;
int stat = 1;
int agmal = 0,iraj =100;
int bakmal = 0,bakraj = 0;
int tidur=0;
int length=0;//inisialisasi jumlah looping
char print[]=""; //="print";
void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
     
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {  while(stat){
	scanf("%[^\n]%*c",print);
}
					
    }

    else if(pthread_equal(id,tid[1]))
    {	
	char temp[100];	
	while(stat){
	strcpy(temp,"All Status");
      if(strcmp(print,temp)==0){
      	print[0]='\0';
	printf("Agmal = %d \nIraj = %d\n",agmal,iraj);		
	  printf("%s\n",print);
	}
	}
	}
   else if(pthread_equal(id,tid[2]))
    {	
	char temp[100];
	while(stat){
	
	strcpy(temp,"Agmal Ayo Bangun");
	if(iraj<=0 || agmal >=100){
	printf("Agmal Bangun,Dan Berangkat Bersama Agmal");	
	exit(0);	
	}

      if(strcmp(print,temp)==0){
	agmal = agmal + 15;
	//printf("Agmal sekarang = %d\n",agmal);
	
	print[0]='\0';	
	bakmal = bakmal + 1;

	
	}
	if(bakraj == 3){
	printf("Fitur Agmal ayo bangun disabled 10 s\n");
	sleep(10);
	bakraj = 0;
	}
	}
}
    else if(pthread_equal(id,tid[3]))
    {	
	char temp[100];
	while(stat){
	
	strcpy(temp,"Iraj Ayo Tidur");
	if(iraj<=0 || agmal >=100){
	printf("Iraj Ikut Tidur,Dan Bangun Kesiangan Bersama Agmal");	
	exit(0);	
	}

      if(strcmp(print,temp)==0){
	iraj = iraj - 20;
	//printf("Iraj sekarang = %d\n",iraj);
	
	print[0]='\0';	
	bakraj = bakraj + 1;

	
	}
	if(bakmal == 3){
	printf("Fitur Iraj ayo tidur disabled 10 s\n");
	sleep(10);
	bakmal = 0;
	}
	}
}
}


int main(void)
{
    int i=0;
    int err;
    while(i<4)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
//            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    pthread_join(tid[3],NULL);
    return 0;
}
