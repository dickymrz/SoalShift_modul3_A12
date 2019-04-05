#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
char input1[100];
void bikinFile();
void kompresFile();
void ekstrakFile();
void *thread(void *argv);


int main(){
    int num_t = 2, i;
    pthread_t tid[num_t];
    
    for (i=0; i<num_t; i++) {
        pthread_create(&tid[i], NULL, thread, &i);
    }
    for (i=0; i<num_t; i++) {
        pthread_join(tid[i], NULL);
    }
}

void *thread(void *argv){
    int *ptr = (int *) argv;
    int id = *ptr + 1;
    
    bikinFile(id);
    sleep(3);
    kompresFile(id);
    printf("istirahat 15 detik\n");
    sleep(5);
    ekstrakFile(id);
    
    return 0;
}

void ekstrakFile(int x){
    if(x == 1)
        system("unzip /home/dennas/Documents/FolderProses1/KompresProses1.zip -d /home/dennas/Documents/FolderProses1/");
    if(x == 2)
        system("unzip /home/dennas/Documents/FolderProses2/KompresProses2.zip -d /home/dennas/Documents/FolderProses2/");
}

void kompresFile(int x){
    if(x == 1)
        system("zip -jm /home/dennas/Documents/FolderProses1/KompresProses1.zip /home/dennas/Documents/FolderProses1/SimpanProses1.txt");
    if(x == 2)
        system("zip -jm /home/dennas/Documents/FolderProses2/KompresProses2.zip /home/dennas/Documents/FolderProses2/SimpanProses2.txt");
    printf("Menunggu 15 detik untuk mengekstrak kembali\n");
    sleep(15);
}

void bikinFile(int x){
    if(x == 1)
        system("ps -aux | head -10 > /home/dennas/Documents/FolderProses1/SimpanProses1.txt");
    if(x == 2)
    system("ps -aux | head -10 > /home/dennas/Documents/FolderProses2/SimpanProses2.txt");
}
