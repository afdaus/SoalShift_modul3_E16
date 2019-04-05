#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int flag,flag1;
pthread_t tid1, tid2, tid3, tid4, tid5, tid6, tid7;

void* proses1(void *arg)
{

	int status;
	status=system("ps aux | head -n 11 > ~/Documents/FolderProses1/SimpanProses1.txt");
	flag=1;
//	sleep(5);
//	status1=system("zip KompresProses1.zip SimpanProses1.txt");

}

void* proses2(void *arg)
{

	int status;
	status=system("ps aux | head -n 11 > ~/Documents/FolderProses2/SimpanProses2.txt");
	flag1=1;
//	sleep(5);
//	status1=system("zip KompresProses2.zip SimpanProses2.txt");

}

void* zipproses1(void *arg)
{

//	sleep(4);
	while(flag!=1){}

		int status;
		status=system("zip -rmj ~/Documents/FolderProses1/KompresProses1.zip ~/Documents/FolderProses1/SimpanProses1.txt");
//	sleep(15);
		flag=2;


}

void* zipproses2(void *arg)
{

//	sleep(4);
	while(flag1!=1){}

		int status;
		status=system("zip -rmj ~/Documents/FolderProses2/KompresProses2.zip ~/Documents/FolderProses2/SimpanProses2.txt");
		flag1=2;
//	sleep(15);


}

void* print15detik(void *arg)
{

	while(flag!=2){}
	printf("Menunggu 15 detik untuk mengekstrak kembali\n");
	flag=3;
	flag1=3;

}

void* unzipproses1(void *arg)
{

	while(flag!=3){}
	int status;
	sleep(15);
	status=system("unzip ~/Documents/FolderProses1/KompresProses1.zip -d ~/Documents/FolderProses1/");

}

void* unzipproses2(void *arg)
{

        while(flag1!=3){}
	int status;
	sleep(15);
        status=system("unzip ~/Documents/FolderProses2/KompresProses2.zip -d ~/Documents/FolderProses2/");

}




int main(void)
{

    pthread_create(&(tid1), NULL, proses1, NULL);
    pthread_create(&(tid2), NULL, proses2, NULL);
    pthread_create(&(tid3), NULL, zipproses1, NULL);
    pthread_create(&(tid4), NULL, zipproses2, NULL);
    pthread_create(&(tid5), NULL, print15detik, NULL);
    pthread_create(&(tid6), NULL, unzipproses1, NULL);
    pthread_create(&(tid7), NULL, unzipproses2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);
    pthread_join(tid6, NULL);
    pthread_join(tid7, NULL);

    return 0;
}
