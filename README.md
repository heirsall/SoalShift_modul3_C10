# SoalShift_modul3_C10
Soal Shift Modul 3 Sistem Operasi

# 3
3.Agmal dan Iraj merupakan 2 sahabat yang sedang kuliah dan hidup satu kostan, sayangnya mereka mempunyai gaya hidup yang berkebalikan, dimana Iraj merupakan laki-laki yang sangat sehat,rajin berolahraga dan bangun tidak pernah kesiangan sedangkan Agmal hampir menghabiskan setengah umur hidupnya hanya untuk tidur dan ‘ngoding’. Dikarenakan mereka sahabat yang baik, Agmal dan iraj sama-sama ingin membuat satu sama lain mengikuti gaya hidup mereka dengan cara membuat Iraj sering tidur seperti Agmal, atau membuat Agmal selalu bangun pagi seperti Iraj. Buatlah suatu program C untuk menggambarkan kehidupan mereka dengan spesifikasi sebagai berikut:
Terdapat 2 karakter Agmal dan Iraj
Kedua karakter memiliki status yang unik
Agmal mempunyai WakeUp_Status, di awal program memiliki status 0
Iraj memiliki Spirit_Status, di awal program memiliki status 100
Terdapat 3 Fitur utama
All Status, yaitu menampilkan status kedua sahabat
Ex: Agmal WakeUp_Status = 75 
      Iraj Spirit_Status = 30
“Agmal Ayo Bangun” menambah WakeUp_Status Agmal sebesar 15 point
“Iraj Ayo Tidur” mengurangi Spirit_Status Iraj sebanyak 20 point
Terdapat Kasus yang unik dimana:
Jika Fitur “Agmal Ayo Bangun” dijalankan sebanyak 3 kali, maka Fitur “Iraj Ayo Tidur” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Fitur Iraj Ayo Tidur disabled 10 s”)
Jika Fitur  “Iraj Ayo Tidur” dijalankan sebanyak 3 kali, maka Fitur “Agmal Ayo Bangun” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Agmal Ayo Bangun disabled 10 s”)
Program akan berhenti jika Salah Satu :
WakeUp_Status Agmal >= 100 (Tampilkan Pesan “Agmal Terbangun,mereka bangun pagi dan berolahraga”)
Spirit_Status Iraj <= 0 (Tampilkan Pesan “Iraj ikut tidur, dan bangun kesiangan bersama Agmal”)


Syarat Menggunakan Lebih dari 1 Thread
Penjelasan :

```int agmal = 0,iraj =100;
int bakmal = 0,bakraj = 0;
char print[]="";
int bangun=1; // diset 1 untuk agmal ayo bangun supaya berjalan
int tidur=1; // diset 1 untuk iraj ayo tidur supaya berjalaan
```
Diatas adalah set untuk variabel gloval

Menggunakan 2 Tid Thread Yaitu 
  ```   if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {  while(stat){
	if(bakmal == 3){
		tidur = 0;
		
		bakmal =0;
		sleep(10);
		tidur = 1;
	
	}
	
	
	}
					
    }
    ```  
  ```
 Pada Thread diatas berguna untuk Mensleep jika Agmal Sudah Dipanggil 3x maka akan mengset variabel tidur siraj supaya off selama 10 detik dengan mengset tidur = 10 lalu mengubahnya kembali jadi 1 ketika sudah 10 detik
 
 ```
 else if(pthread_equal(id,tid[1]))
    {	
	while(stat){
      if(bakraj == 3){
   		
		bangun = 0;
		
      	bakraj = 0;
      	sleep(10);
      	bangun = 1;
	  }
	}
	}
  ```
  
  ```
  ```
 Pada Thread diatas berguna untuk Mensleep jika Iraj Sudah Dipanggil 3x maka akan mengset variabel bangun Iraj supaya off selama 10 detik dengan mengset tidur = 0 lalu mengubahnya kembali jadi 1 ketika sudah 10 detik
 
 Pada Main :
  ```
  pthread_create(&(tid[0]),NULL,&playandcount,NULL);//membuat thread tid 1

pthread_create(&(tid[1]),NULL,&playandcount,NULL);//membuat thread tid 2
  ```
  setelah itu membuat looping dengan while(1);
  Melakukan Scan untuk string yang bisa membaca spasi
  `
  scanf("%[^\n]%*c",print);
  `
    
   ``` 
   if(strcmp(print,"All Status")==0){
      	print[0]='\0'; // mereset string supaya netral
	printf("Agmal = %d \nIraj = %d\n",agmal,iraj);		
        printf("%s\n",print);
	}
   ```
   ```
   ```
   Diatas adalah menampilkan status agmal dan iraj jika dimasukkan string All Status
      ``` 
else if(strcmp(print,"Iraj Ayo Tidur")==0 && tidur == 1){
	iraj = iraj - 20;
	
	print[0]='\0';	
	bakraj = bakraj + 1; //menghitung dijalankan berapa kali
	}
   ``` 
   ```
   Diatas adalah untuk mengurangi iraj 20 ketika string diinputka
    ```
     if(strcmp(print,"Agmal Ayo Bangun")==0 && bangun ==1){
	agmal = agmal + 15;
	//printf("Agmal sekarang = %d\n",agmal);
	
	print[0]='\0';	
	bakmal = bakmal + 1; //menghitung dijalankan berapa kali

	
	}
    ```
   ```
   ```
   
   Diatas adalah untuk menambah Agmal 15 ketika string diinputkan 
   
  ```
  if(bakmal == 3){ //jika agmal ayo bangun sudah dijalankan 3x 
		printf("Fitur Iraj ayo tidur disabled 10 s\n");} //mengprint ini
		
      if(bakraj == 3){ //jika iraj ayo tidur sudah dijalankan 3x
   		
		printf("Fitur Agmal ayo bangun disabled 10 s\n");} // akan mengprint ini
			
	if(iraj<=0){ //jika iraj status sudah 0 atau kurang maka program akan berhenti
	printf("Iraj Ikut Tidur,Dan Bangun Kesiangan Bersama Agmal");	
	exit(0);	
	}
	 if(agmal >= 100){ // jika agmal status sudah 100 atau lebih maka program akan berhenti
	 printf("Agmal Ikut Bangun,Dan Olahraga Bersama Iraj");
	 }

  ```
  
# 4
Buatlah sebuah program C dimana dapat menyimpan list proses yang sedang berjalan (ps -aux) maksimal 10 list proses. Dimana awalnya list proses disimpan dalam di 2 file ekstensi .txt yaitu  SimpanProses1.txt di direktori /home/Document/FolderProses1 dan SimpanProses2.txt di direktori /home/Document/FolderProses2 , setelah itu masing2 file di  kompres zip dengan format nama file KompresProses1.zip dan KompresProses2.zip dan file SimpanProses1.txt dan SimpanProses2.txt akan otomatis terhapus, setelah itu program akan menunggu selama 15 detik lalu program akan mengekstrak kembali file KompresProses1.zip dan KompresProses2.zip 
Dengan Syarat : 
Setiap list proses yang di simpan dalam masing-masing file .txt harus berjalan bersama-sama
Ketika mengkompres masing-masing file .txt harus berjalan bersama-sama
Ketika Mengekstrak file .zip juga harus secara bersama-sama
Ketika Telah Selesai melakukan kompress file .zip masing-masing file, maka program akan memberi pesan “Menunggu 15 detik untuk mengekstrak kembali”
Wajib Menggunakan Multithreading
Boleh menggunakan system


Source Code 
```C
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
```
Berikut Adalah Penjelasan Source Code Diatas
```C
while(masuk<2)
    {
        err=pthread_create(&(tid[masuk]),NULL,&buatfile,NULL);
   
        masuk++;
    }
    ```
```
Diatas DIgunakan untuk membuat thread sesuai dengan urutan tid dan Mutual Exclusionnya
```C
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
```
Diatas digunakan untuk membuat Mutual Exclusion dan Thread yang berjalan secara bersamaan dan gunanya untuk membuat file simpan proses1.txt dan simpanproses2.txt dengan megambil max 10 proses.

```C
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
```
Diatas digunakan untuk membuat Mutual Exclusion dan Thread yang berjalan secara bersamaan dan gunanya untuk Mengunzip file simpan proses1.txt dan simpanproses2.txt dan mengilangkannya yang bukan zip.


```C
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
```
Diatas 
```C
 printf("Menunggu 15 detik untuk mengekstrak kembali\n");
	int x = 1;
	while(x!=16){    
	sleep(1);		
	printf("%d\n",x);
	x=x+1;
		
	}
```
Digunakan untuk mensleep dan menghitung selama 15 detik

```C

        system("unzip -qd /home/zahrul/Documents/FolderProses1/ /home/zahrul/Documents/FolderProses1/KompresProses1.zip");

        system("unzip -qd /home/zahrul/Documents/FolderProses2/ /home/zahrul/Documents/FolderProses2/KompresProses2.zip");
```
Pada Diatas digunakan untuk mengunzip


#5
Angga, adik Jiwang akan berulang tahun yang ke sembilan pada tanggal 6 April besok. Karena lupa menabung, Jiwang tidak mempunyai uang sepeserpun untuk membelikan Angga kado. Kamu sebagai sahabat Jiwang ingin membantu Jiwang membahagiakan adiknya sehingga kamu menawarkan bantuan membuatkan permainan komputer sederhana menggunakan program C. Jiwang sangat menyukai idemu tersebut. Berikut permainan yang Jiwang minta. 
Pemain memelihara seekor monster lucu dalam permainan. Pemain dapat  memberi nama pada monsternya.
Monster pemain memiliki hunger status yang berawal dengan nilai 200 (maksimalnya) dan nanti akan berkurang 5 tiap 10 detik.Ketika hunger status mencapai angka nol, pemain akan kalah. Hunger status dapat bertambah 15 apabila pemain memberi makan kepada monster, tetapi banyak makanan terbatas dan harus beli di Market.
Monster pemain memiliki hygiene status yang berawal dari 100 dan nanti berkurang 10 tiap 30 detik. Ketika hygiene status mencapai angka nol, pemain akan kalah. Hygiene status' dapat bertambah 30 hanya dengan memandikan monster. Pemain dapat memandikannya setiap 20 detik(cooldownnya 20 detik).
Monster pemain memiliki health status yang berawal dengan nilai 300. Variabel ini bertambah (regenerasi)daa 5 setiap 10 detik ketika monster dalam keadaan standby.
Monster pemain dapat memasuki keadaan battle. Dalam keadaan ini, food status(fitur b), hygiene status'(fitur c), dan ‘regenerasi’(fitur d) tidak akan berjalan. Health status dari monster dimulai dari darah saat monster pemain memasuki battle. Monster pemain akan bertarung dengan monster NPC yang memiliki darah 100. Baik monster pemain maupun NPC memiliki serangan sebesar 20. Monster pemain dengan monster musuh akan menyerang secara bergantian. 
Fitur shop, pemain dapat membeli makanan sepuas-puasnya selama stok di toko masih tersedia.
Pembeli (terintegrasi dengan game)
Dapat mengecek stok makanan yang ada di toko.
Jika stok ada, pembeli dapat membeli makanan.
Penjual (terpisah)
Bisa mengecek stok makanan yang ada di toko
Penjual dapat menambah stok makanan.
	Spesifikasi program:
Program mampu mendeteksi input berupa key press. (Program bisa berjalan tanpa perlu menekan tombol enter)
Program terdiri dari 3 scene yaitu standby, battle, dan shop.
Pada saat berada di standby scene, program selalu menampilkan health status, hunger status, hygiene status, stok makanan tersisa, dan juga status kamar mandi (“Bath is ready” jika bisa digunakan, “Bath will be ready in [bath cooldown]s” jika sedang cooldown). Selain itu program selalu menampilkan 5 menu, yaitu memberi makan, mandi, battle, shop, dan exit. Contoh :

Standby Mode
Health : [health status]
Hunger : [hunger status]
Hygiene : [hygiene status]
Food left : [your food stock]
Bath will be ready in [cooldown]s
Choices
Eat
Bath
Battle
Shop
Exit

Pada saat berada di battle scene, program selalu menampilkan health status milik pemain dan monster NPC. Selain itu, program selalu menampilkan 2 menu yaitu serang atau lari. Contoh :

Battle Mode
Monster’s Health : [health status]
Enemy’s Health : [enemy health status]
Choices
Attack
Run

Pada saat berada di shop scene versi pembeli, program selalu menampilkan food stock toko dan milik pemain. Selain itu, program selalu menampilkan 2 menu yaitu beli dan kembali ke standby scene. Contoh :

		Shop Mode
		Shop food stock : [shop food stock]
		Your food stock : [your food stock]
		Choices
Buy
Back

Pada program penjual, program selalu menampilkan food stock toko. Selain itu, program juga menampilkan 2 menu yaitu restock dan exit. Contoh :

Shop
Food stock : [shop food stock]
Choices
Restock
Exit

Pastikan terminal hanya mendisplay status detik ini sesuai scene terkait (hint: menggunakan system(“clear”))

Source Code Ada di folder 5
Berikut penjelasannya
```C
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
```
Merupakan Fungsi untuk memanggil Getch yaitu untuk menginputkan tanpa enter

```C
 key_t key = 1234;
        int *value;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);
		*value = stok; 
```
Diatas adalah untuk shared memory pada nanti pilihan shop yang mengisi stok

```C
 if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {  
	printf("Masukkan Nama Monster = ");

	while(stat){
    	if(choice != 51 && choice !=52 && monster[0]!='.'){
			
	system("clear");	
	printf("Health : %d \nHunger : %d \nHygiene : %d \nFood left : %d\nBath will be ready in %d s\n",health,hunger,hygiene,food,bath);
	printf("Choices \n 1.Eat \n 2.Bath \n 3.Battle \n 4.Shop \n 5.Exit\n");
	
	printf("Pilihan = ");

	if(choice == 53)exit(0);
}
```
Diatas adalah thread yang berguna untuk menampilkan tampilan dan menggunakan clear untuk merefresh status terbaru

```C
else if(pthread_equal(id,tid[9]))
    {	 
	scanf("%c",monster);
	
	while(stat){
	//Code Here
	if(choice != 51 && choice !=52 && monster[0] != '.')
	choice = mygetch();
	

	}
```
Pada diatas berguna untuk menginputkan nama monster dan menginputkan pilihan

```C
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
```
Diatas berguna untuk mengurangi hunger - 5 setiap 10 detik

```C
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
```
Diatas adalah untuk mengurangi hygiene - 10 setiap 30 detik dan game over jika habis
```C
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
```
Diatas berguna untuk meregen health monster + 5 setiap 10 detik
```C
  else if(pthread_equal(id,tid[4]))
    {	
	
	while(stat){
	//Code Here
	
	if(bath!=0)
	bath = bath - 1 ;
	
	sleep(1);
	}
	
}
```
Diatas adalah untuk mengurangi detikan bath jika telah dipakai

```C

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
```
Diatas adalah jika memilih 1 maka akan memberi makan hunger bertambah 15 dan stok berkurang 15

```C

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
	
```
Diatas adalah untuk memandikan hygiene menjadi + 30 dan bath akan delay selama 20 detik

```C
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
```
Diatas adalah untuk tarung maka akan mengganti tampilan dan jika memilih 1 Attac akan menyerang secara bergantian monster - 10 dan musuh - 10
```C
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
```
Diatas adalah untuk pada pilihan shop akan membeli  jika pilih buy 

```C
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
```
Main diatas kurang lebi digunakan untuk membuat thread dan menjoinkannya saja

Selanjutnya adalah pada restock
```C
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
void main()
{
        key_t key = 1234;
        int *value;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
     	int hay=1;
	int pilih;	
	while(hay=1){
	   value = shmat(shmid, NULL, 0);
	printf("Food Stock = %d\n1.Restock\n2.Exit\n",*value);
	scanf("%d",&pilih);        
		if(pilih==1) *value = *value + 10;
		else if(pilih==2) exit(0);
	
	}       
	 shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}
```
Menggunakan shared memory dan jika pilihan 1 akan menambah stok  dajn jika 2 akan exit
