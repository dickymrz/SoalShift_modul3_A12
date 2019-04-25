# SoalShift_modul3_A12

SOAL 1 :
Tujuan dari soal nomer 1 adalah denga dapat mencari suatu nilai faktorial dari list angka yang tidak urut sehingga dapat ditampilkan secara urut dari kecil ke besar, dan proses untuk menghitung harus dilakukan secara bersamaan.

PENYELESAIAN : 
Yang dibutuhkan adalah threading untuk menghitung nilai faktorial secara bersamaan, sorting untuk mensorting argumen yang diinputkan dengan quick sort, dan mencari nilai faktorial.

```
//Quick Sort
int sort(const void * a, const void * b) {
return ( *(int*)a - *(int*)b );

//Untuk mencari faktorial
void* fak(void *a){// Untuk memanggil angka atau value yang sama
    int fact = 1;
    int y =*((int *)a);// untuk mengembalikan nilai void ke int
    int z;
    for (z = 1; z <= y; z++)
    {
        fact = fact * z;
    }
    fx[c]=z;
    hx[c]=fact;
    c++;
}

//Untuk mengubah char menjadi Int
int main(int argc, char* argv[]){
    int x[100];
    for (int i = 0; i < argc-1; ++i)
        x[i]=atoi(argv[i+1]);
        
//Bagian Thread
pthread_t tid[100];
    for(int i=0; i < argc-1; i++){
    pthread_create(&tid[i],NULL,fak,&x[i]);
    }
    for(int i=0; i < argc-1; i++){
    pthread_join(tid[i],NULL);
    }
       
//Quick Sort
qsort(fx,argc-1,sizeof(int),sort);
qsort(hx,argc-1,sizeof(int),sort);
    
//Bagian Print
for(int i=0; i < argc-1; i++){
    printf("%d! = %d\n", fx[i], hx[i]);
    }
    return 0;
```
    
SOAL 2 :
Tujuan nomer 2 adalah membuat suatu program server penjual dan pembeli serta client penjual dan pembeli yang dapat dihubungkan oleh user untuk dapat mengakses suatu stok barang yang merupakan shared memory, yang dimana jika user tersebut terhubung dengan server penjual maka user dapat menambahkan stok barang dan dapat menampilkan stock barang. Begitu juga dengan server pembeli, user dapat membeli stock sehingga dapat mengurangi nilai dari stock barang.

PENYELESAIAN :
Untuk setiap server dan client sama menggunakan panduan seperti di Modul 3 hanya saja perlu beberapa bagian yang harus ditambahkan 

```
//Untuk Client Pembeli
    while(1){
        
        scanf("%s",beli);
        send(sock , beli , strlen(beli) , 0 );
        valread = read( sock , buffer, 1024);
        printf("%s\n",buffer );
        memset(buffer,0,sizeof(buffer));//Untuk set semua var buffer menjadi 0
    
    }
    return 0;

//Untuk Client Penjual
    while(1){
        scanf("%s",tambah);
        send(sock , tambah , strlen(tambah) , 0 );
        valread = read( sock , buffer, 1024);
        printf("%s\n",buffer );
        memset(buffer,0,sizeof(buffer));
        
    }
    return 0;
    
//Untuk Server Pembeli
void *beli(void *arg){

    int *sock_client;
    sock_client = (int *)arg;
    char c_response[100];
    memset(c_response,0,sizeof(c_response));
    while(recv(*sock_client, &c_response, sizeof(c_response), 0)){ 
        
        if(strcmp(c_response,"beli") == 0){
           if(*stok>0) {
              *stok=*stok-1;
              char pesan[100] = "Transaksi berhasil";
              send(*sock_client, pesan, sizeof(pesan), 0);
           } else {
              char pesan[100] = "Transaksi gagal";
              send(*sock_client, pesan, sizeof(pesan), 0);
           }

        }else{
            char pesan[100] = "Error";
            send(*sock_client, pesan, sizeof(pesan), 0);
        }
        
        printf("Data terkirim : %s\n",c_response);
        printf("Stok sekarang : %d\n", *stok);
        memset(c_response,0,sizeof(c_response));
    }
}

//Untuk Server Penjual
void *jual(void *arg){

    int *sock_client;
    sock_client = (int *)arg;
    char c_response[100];
    memset(c_response,0,sizeof(c_response));
    while(recv(*sock_client, &c_response, sizeof(c_response), 0)){ 

        if(strcmp(c_response,"jual") == 0){

            *stok=*stok+1;
            char pesan[100] = "Transaksi berhasil";
            send(*sock_client, pesan, sizeof(pesan), 0);

        }else{

            char pesan[100] = "Error";
            send(*sock_client, pesan, sizeof(pesan), 0);

        }

        printf("Data telah terkirim : %s\n",c_response);
        memset(c_response,0,sizeof(c_response));
    }
}

void *lihatStok(void *arg){

    while(1){
        sleep(5);
        printf("Banyak stok : %d\n",*stok);
    }

}
```

SOAL 5 :
Soal nomer 5 adalah game survival yang mempunyai menu health, hunger, hygiene, battle, pada monster.

PENYELESAIAN : 
Membuat 2 bagian, bagian pertama untuk pemain dan bagian kedua untuk penjual
```
//Bagian Pemain
//using namespace std;

char nama_monster[11];
char pnjng[1], input;
int food, hunger_status, hygiene_status, health_status, time_hunger, time_hygiene;
int time_health,st,sh,ba, bath, lose, lawan, keluar;

//set food stock
	key_t key = 1234;
	int *food_stock;
  
//membuat getch
//membuat get_nama
//membuat display
//membuat input game

//set status awal
	hunger_status = 200;
	hygiene_status = 100;
	health_status = 300;
	food = '0';
	
//beri nama
	get_nama();

	iret1 = pthread_create( &thread1, NULL, display, NULL); //membuat thread pertama
    if(iret1) //jika eror
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
        exit(EXIT_FAILURE);
    }

	iret2 = pthread_create( &thread2, NULL, inputgame, NULL);//membuat thread kedua
    if(iret2)//jika gagal
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
        exit(EXIT_FAILURE);
    }
    
    
 //bagian Penjual
 //using namespace std;
char input;
int keluar;

//set food stock
	key_t key = 1234;
	int *food_stock = 0;
  
//membuat getch
//membuat display
//membuat inputgame
```
