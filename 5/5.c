#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>

int angka=0;
int stat = 1;
int agmal = 0,iraj =100;
int bakmal = 0,bakraj = 0;
int tidur=0;
int npchealt = 100;

int health=300;
int hunger = 200;
int hygiene =100;
int food = 100;
int stok = 100;
int bath = 0;
int choice = 0;
char monster[] = ".";


pthread_t tid[9];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread



int length=0;//inisialisasi jumlah looping
char print[]=""; //="print";

int mygetch(void)
{
struct termios oldt,
newt;
int ch;
tcgetattr( STDIN_FILENO, &oldt );
newt = oldt;
newt.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}

void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
     key_t key = 1234;
        int *value;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);
		*value = stok; 
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {  
	printf("Masukkan Nama Monster = ");

	while(stat){
    	if(choice != 51 && choice !=52 && monster[0]!='.'){
			
	system("clear");	
	printf("Health : %d \nHunger : %d \nHygiene : %d \nFood left : %d\nBath will be ready in %d s\n",health,hunger,hygiene,food,bath);
	printf("Choices \n 1.Eat \n 2.Bath \n 3.Battle \n 4.Shop \n 5.Exit\n");
	//choice = getch();
	printf("Pilihan = ");
	
//	choice=mygetch();
	
//	scanf("%d",&choice);
	if(choice == 53)exit(0);
}
}
					
    }

    else if(pthread_equal(id,tid[1]))
    {	
	while(stat){
	
     //code here HUNGER
     if(choice !=51){
	 
    	 if(hunger>0)
	 	hunger = hunger - 5;
    
		 else {
		 printf("GAME OVER");
		exit(0);	}
		 sleep(10);
		}
	}
	}
	
	
	
    else if(pthread_equal(id,tid[2]))
    {	
	
	while(stat){
	
		//Code here HYGIENE
		if(choice != 51){
		
			hygiene = hygiene - 10;
			if(hygiene <= 0){
				printf("GAME OVER");
				exit(0);
			}
			sleep(30);
		}
	}

}
    else if(pthread_equal(id,tid[3]))
    {	
	
	while(stat){
	//Code Here Healt
	if(choice != 51){
	
		health = health + 5;
		if(health<=0){
			printf("GAME OVER");
			exit(0);
		}
		sleep(10);
	}
	}
	
}
   else if(pthread_equal(id,tid[4]))
    {	
	
	while(stat){
	//Code Here
	
	if(bath!=0)
	bath = bath - 1 ;
	
	sleep(1);
	}
	
}

	else if(pthread_equal(id,tid[5]))
    {	
	
	while(stat){
	//Code Here
	if(food!=0)
	if(choice == 49){
		
		hunger = hunger + 15;
		food = food - 15;
		choice = 0;
		if(food <0)food = 0;
		sleep(1);
	}
	
	}
	
}


	else if(pthread_equal(id,tid[6]))
    {	
	
	while(stat){
	//Code Here
	if(choice == 50){
	if(bath == 0){
	
	hygiene = hygiene + 30;		
	bath = 20;
	choice = 0;
	}
	
	}
	
	}
	
	}
	
	else if(pthread_equal(id,tid[7]))
    {	
	int pilih;
	while(stat){
	//Code Here
	
	int tarung = 1;
	if(choice == 51){
		while(tarung == 1){
		
	system("clear");
		printf("Monster Health = %d\n",health);
		printf("Enemy Health = %d\n",npchealt);
		printf("Choices \n1. Attack \n2. Run\n");
		pilih = mygetch();
		//scanf("%d",&pilih);
		if(pilih == 49){
			health = health - 20;
			npchealt = npchealt - 20;
			if(health <=0){
				printf("Anda Kalah\n");
				tarung = 0;
				choice = 0;
			}
			else if(npchealt<=0){
				printf("Anda Menang\n");
				tarung = 0;
				choice = 0;
				npchealt = 100;
			}
		}		
		else {
			
		choice = 0;
		tarung = 0;
		}
		}
		
	}
	}
	
	}
	
	else if(pthread_equal(id,tid[8]))
    {	
	int pilih;
	while(stat){
	//Code Here
	
	int tarung = 1;
	if(choice == 52){
		while(tarung == 1){
		
	system("clear");
		printf("Shop Food Stock = %d\n",*value);
		printf("Your Food Stock = %d\n",food);
		printf("Choices \n1. Buy \n2. Back\n");
		//scanf("%d",&pilih);
		pilih = mygetch();
		if(pilih == 49){
			food = food + 20;
			*value = *value - 20;
			if(*value <=0){
				printf("Stok Habis\n");
				tarung = 0;
				choice = 0;
			}
		}		
		
		else {
			
		choice = 0;
		tarung = 0;
		}
		
		}
		
	}
	}
	
	}
	
	else if(pthread_equal(id,tid[9]))
    {	 
	scanf("%c",monster);
	
	while(stat){
	//Code Here
	if(choice != 51 && choice !=52 && monster[0] != '.')
	choice = mygetch();
	

	}
	
}
	
	
}




int main(void)
{
	
	
    int i=0;
    int err;
    while(i<10)//looping membuat thread 2x
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
	pthread_join(tid[4],NULL);
    pthread_join(tid[5],NULL);
    pthread_join(tid[6],NULL);
	pthread_join(tid[7],NULL);
    pthread_join(tid[8],NULL);
    pthread_join(tid[9],NULL);
    return 0;
}
