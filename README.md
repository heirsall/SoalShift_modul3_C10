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
  
  asda
