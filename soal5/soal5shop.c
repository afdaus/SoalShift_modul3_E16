#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <signal.h>
#include <termios.h>

pthread_t tid1,tid2,tid3;
char input;
int temp;
int *shopfoodstock;
int flag=0;

void* shop(void *arg)
{
	key_t key=1234;
	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	shopfoodstock = shmat(shmid, NULL, 0);
	while(1)
	{

		printf("Shop\n");
		printf("Food Stock : %d\n", *shopfoodstock);
		printf("Choices\n");
		printf("1. Restock\n");
		printf("2. Exit\n");
		if(input=='1'){flag=1; input=0;}
		else if(input=='2')
		{
			pthread_kill(tid1, SIGKILL);
			pthread_kill(tid2, SIGKILL);
			pthread_kill(tid3, SIGKILL);
		}
		sleep(1);
		system("clear");
	}
	shmdt(shopfoodstock);
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* reads from keypress, echoes */
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void* masuk(void *arg)
{
	while(1){
	input=getch();
	}
}

void* incrementstock(void *arg)
{
	while(1)
	{
	while(flag!=1){}
	(*shopfoodstock)++;
	flag=0;
	}
}

int main()
{

	pthread_create(&tid1, NULL, shop, NULL);
	pthread_create(&tid2, NULL, masuk, NULL);
	pthread_create(&tid3, NULL, incrementstock, NULL);
	pthread_join(tid1, NULL);
}

