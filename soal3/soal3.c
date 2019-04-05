#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <signal.h>
void tunggu();
int WakeUp_Status=0;
int Spirit_Status=100;
int status=0,status1=0,jalan=0,jalan1=0,flag=0,flag1=0;
int print=0,flag3=0;
int turu=0, turu1=0;
int bunuh=0,sudah=0,masuk;
pthread_t tid1, tid2, tid3, tid4,tid5;

void* Agmal(void *arg)
{
	while(1)
	{
	if(bunuh==1)
	{
		sudah=1;
		pthread_kill(tid1,SIGKILL);
	}
	while(jalan1>0)
	{
		printf("Agmal Ayo Bangun disabled 10 s\n");
		flag=0;
		sleep(10);
		jalan1=0;
	}
	if(flag==1)
	{
		WakeUp_Status+=15;
		status++;
		flag=0;
	}
		if(status==3)
		{
			status=0;
			jalan++;
		}
	}
}

void* Iraj(void *arg)
{
	while(1)
	{
		if(bunuh==1)
		{
			sudah=1;
			pthread_kill(tid2,SIGKILL);
		}
	while(jalan>0)
	{
		printf("Fitur Iraj Ayo Tidur disabled 10 s\n");
		flag1=0;
		sleep(10);
		jalan=0;
	}

	if(flag1==1)
	{
		Spirit_Status-=20;
		status1++;
		flag1=0;
	}
		if(status1==3)
		{
			status1=0;
			jalan1++;
		}
	}
}

void* cetak(void *arg)
{
	while(1)
	{
		if(bunuh==1)
		{
			sudah=1;
			pthread_kill(tid3,SIGKILL);
		}
		while(print!=1)
		{

		}
		printf("Wake Up Status : %d\n",WakeUp_Status);
		printf("Spirit Status : %d\n",Spirit_Status);
		print=0;
	}
}

void tunggu()
{
	sleep(10);
}

void* masukan(void *arg)
{
	while(bunuh!=1)
	{
		scanf("%d",&masuk);
		flag3=1;
	}
}

void* menu(void *arg)
{
	char opsi1[70];
	flag1=0;
        strcpy(opsi1,"All Status");
        char opsi2[70];
        strcpy(opsi2,"Agmal Ayo Bangun");
        char opsi3[70];
        strcpy(opsi3,"Iraj Ayo Tidur");
        printf("Pilih Fitur:\n");
        printf("1. All Status\n");
        printf("2. Agmal Ayo Bangun\n");
        printf("3. Iraj Ayo Tidur\n");
	while(flag3!=1){}
	while(1)
	{
                if(masuk==1)
                {
			masuk=0;
                        print=1;
                }
                else if(masuk==2)
                {
			masuk=0;
                        if(jalan1==0)
                        {
                                flag=1;
                        }
                }
                else if(masuk==3)
                {
			masuk=0;
                        if(jalan==0)
                        {
                                flag1=1;
                        }
                }
		while(WakeUp_Status >=100)
		{
			bunuh=1;
                        printf("Agmal Terbangun, mereka bangun pagi dan berolahraga\n");
			pthread_kill(tid4,SIGKILL);
			break;
		}
		while(Spirit_Status <=0)
                {
			bunuh=1;
                        printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n");
			pthread_kill(tid4,SIGKILL);
			break;
                }

        }
}



int main()
{
	pthread_create(&tid4,NULL,menu,NULL);
	pthread_create(&tid1,NULL,cetak,NULL);
	pthread_create(&tid2,NULL,Agmal,NULL);
	pthread_create(&tid3,NULL,Iraj, NULL);
	pthread_create(&tid5, NULL, masukan, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	pthread_join(tid5, NULL);
	return 0;
}
