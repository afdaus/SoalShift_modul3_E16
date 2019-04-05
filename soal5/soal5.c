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

pthread_t tid1,tid2,tid3,tid4,tid5,tid6,tid7,tid8,tid9,tid10,tid11,tid12,tid13;

int flag=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag8=0;
int flag9=0,test=0,flag11=0;
int hunger_status=200;
int bathtime=20;
int Hygiene_Status=100;
int Health_Status=300;
int Hunger_Status=200;
int Enpisi_Status=100;
int Enpisi_Attack=20;
int myfoodstock=0;
int *shopfoodstock;
int Monster_Attack=20;
char nama[1000]="";
char input;
int getch(void)
{
    struct termios oldattr, newattr;
    int ambil;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ambil = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ambil;
}

/* reads from keypress, echoes */
int getche(void)
{
    struct termios oldattr, newattr;
    int ambil;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ambil = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ambil;
}

void* namabinatang(void *arg)
{

	printf("Masukkan nama monster:");
	scanf("%[^\n]s", nama);
	flag=1;
	flag8=1;
	system("clear");

}

void* masuk(void *arg)
{
	while(1)
	{
//		char input;
		while(flag8!=1){}
		input=getch();
	}
}

void* eat(void *arg)
{
	while(1)
	{

	while(flag11!=1){}
	if(myfoodstock>0)
		{

			myfoodstock--;
			Health_Status+=15;
			flag11=0;

		}

	}

}

void* standbyscene(void *arg)
{
	while(1)
	{
	while(flag!=1){}
	flag1=1;
	printf("Standby Mode\n");
	printf("Nama Monster : %s\n", nama);
	printf("Health : %d\n", Health_Status);
	printf("Hunger : %d\n", Hunger_Status);
	printf("Hygiene : %d\n", Hygiene_Status);
	printf("Food Left : %d\n", myfoodstock);
	if(flag3==0)
	{
		printf("Bath is ready\n");
	}
	else
	{
		printf("Bath will be ready in %d s\n", bathtime);
	}
	printf("Choices\n");
	printf("1. Eat\n");
	printf("2. Bath\n");
	printf("3. Battle\n");
	printf("4. Shop\n");
	printf("5. Exit\n");
	if(input=='2' && bathtime>0 && flag3==0 && flag2==0){flag2=1; input=0;}
	else if(input=='4')
	{
		system("clear");
		flag1=0;
		test=1;
		input=0;
		flag=0;
	}
	else if(input=='3')
	{
		system("clear");
		flag1=0;
		flag4=1;
		input=0;
		flag=0;
		Enpisi_Status=100;
	}
	else if(input=='1')
	{
		system("clear");
		flag11=1;
		input=0;
	}
	else if(input=='5')
	{
		 		pthread_kill(tid1, SIGKILL);
                                pthread_kill(tid2, SIGKILL);
                                pthread_kill(tid3, SIGKILL);
                                pthread_kill(tid4, SIGKILL);
                                pthread_kill(tid5, SIGKILL);
                                pthread_kill(tid6, SIGKILL);
                                pthread_kill(tid7, SIGKILL);
                                pthread_kill(tid8, SIGKILL);
                                pthread_kill(tid9, SIGKILL);
                                pthread_kill(tid10, SIGKILL);
                                pthread_kill(tid11, SIGKILL);
                                pthread_kill(tid12, SIGKILL);
                                pthread_kill(tid13, SIGKILL);
	}
	if(Hunger_Status<=0)
	{
				pthread_kill(tid1, SIGKILL);
                                pthread_kill(tid2, SIGKILL);
                                pthread_kill(tid3, SIGKILL);
                                pthread_kill(tid4, SIGKILL);
                                pthread_kill(tid5, SIGKILL);
                                pthread_kill(tid6, SIGKILL);
                                pthread_kill(tid7, SIGKILL);
                                pthread_kill(tid8, SIGKILL);
                                pthread_kill(tid9, SIGKILL);
                                pthread_kill(tid10, SIGKILL);
                                pthread_kill(tid11, SIGKILL);
                                pthread_kill(tid12, SIGKILL);
                                pthread_kill(tid13, SIGKILL);
	}

	if(Hygiene_Status<=0)
	{
				pthread_kill(tid1, SIGKILL);
                                pthread_kill(tid2, SIGKILL);
                                pthread_kill(tid3, SIGKILL);
                                pthread_kill(tid4, SIGKILL);
                                pthread_kill(tid5, SIGKILL);
                                pthread_kill(tid6, SIGKILL);
                                pthread_kill(tid7, SIGKILL);
                                pthread_kill(tid8, SIGKILL);
                                pthread_kill(tid9, SIGKILL);
                                pthread_kill(tid10, SIGKILL);
                                pthread_kill(tid11, SIGKILL);
                                pthread_kill(tid12, SIGKILL);
                                pthread_kill(tid13, SIGKILL);
	}

	sleep(1);
	system("clear");
	}
}

void* battlescene(void *arg)
{

	while(1)
	{
	while(flag4!=1)
		{}
			printf("Battle Mode");
			printf("Monster's Health : %d\n", Health_Status);
			printf("Enemy's Health : %d\n", Enpisi_Status);
			printf("Choices\n");
			printf("1. Attack \n");
			printf("2. Run\n");
			if(input=='1')
			{
				flag5=1;input=0;
			}
			else if(input=='2')
			{
				system("clear");
				flag=1;
				flag4=0;
				input=0;
			}
			if(Enpisi_Status<=0)
			{
				flag=1;
				flag4=0;
			}
			else if(Health_Status<=0)
			{
				printf("Monster anda mati!");
				pthread_kill(tid1, SIGKILL);
				pthread_kill(tid2, SIGKILL);
				pthread_kill(tid3, SIGKILL);
				pthread_kill(tid4, SIGKILL);
				pthread_kill(tid5, SIGKILL);
				pthread_kill(tid6, SIGKILL);
				pthread_kill(tid7, SIGKILL);
				pthread_kill(tid8, SIGKILL);
				pthread_kill(tid9, SIGKILL);
				pthread_kill(tid10, SIGKILL);
				pthread_kill(tid11, SIGKILL);
				pthread_kill(tid12, SIGKILL);
				pthread_kill(tid13, SIGKILL);

			}
			sleep(1);
			system("clear");
	}

}

void* monsterattack(void *arg)
{

	while(1)
	{
	while(flag5!=1)
		{}
		Enpisi_Status-=20;
		flag6=1;
		flag5=0;
	}

}

void* enemyattack(void *arg)
{

	while(1)
	{
	while(flag6!=1)
		{}
		sleep(2);
		Health_Status-=20;
		flag6=0;
	}

}

void* hungerngurang(void *arg)
{
	while(1)
	{
	while(flag1!=1){}
	sleep(10);
	if(flag4==0)
		{
		Hunger_Status-=5;
		}
	}
}

void* hygienengurang(void *arg)
{
        while(1)
        {
        while(flag1!=1){}
	sleep(30);
        if(flag4==0)
		{
      		  Hygiene_Status-=10;
      	  	}
	}
}

void* healthnambah(void *arg)
{
        while(1)
        {
        while(flag1!=1){}
	sleep(10);
        if(flag4==0)
	{
        	Health_Status+=5;
        }
	}
}

void* monstermandi(void *arg)
{
	while(1)
	{
		while(flag2!=1){}
		Hygiene_Status+=30;
		flag2=0;
		flag3=1;
		sleep(20);
	}

}

void* ngurangbathtime(void *arg)
{
	while(1)
	{
		while(flag3!=1){}
		if(bathtime<0)
		{
			flag3=0;
			bathtime=20;
		}
		sleep(1);
		bathtime--;

	}
}

void* shopscene(void *arg)
{

	while(1)
	{
		while(test!=1)
		{
		}
	        key_t key = 1234;
        	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        	shopfoodstock = shmat(shmid, NULL, 0);

//		flag8=0;
		printf("Shop Mode\n");
		printf("Your Food Stock : %d\n", myfoodstock);
		printf("Choices\n");
		printf("1. Buy\n");
		printf("2. Back\n");
		if(input=='1')
		{

			if((*shopfoodstock)>0)
			{
			myfoodstock++;
			(*shopfoodstock)--;
			input=0;
			}

		}
		else if(input=='2')
		{
			system("clear");
			test=0;
			flag=1;
			input=0;

		}
		sleep(1);
		system("clear");
		shmdt(shopfoodstock);
	}
}

int main()
{

	pthread_create(&tid1, NULL, namabinatang, NULL);
	pthread_create(&tid2, NULL, standbyscene, NULL);
	pthread_create(&tid3, NULL, hungerngurang, NULL);
	pthread_create(&tid4, NULL, hygienengurang, NULL);
	pthread_create(&tid5, NULL, healthnambah, NULL);
	pthread_create(&tid6, NULL, monstermandi, NULL);
	pthread_create(&tid7, NULL, ngurangbathtime, NULL);
	pthread_create(&tid8, NULL, battlescene, NULL);
	pthread_create(&tid9, NULL, masuk, NULL);
	pthread_create(&tid10, NULL, monsterattack, NULL);
	pthread_create(&tid11, NULL, enemyattack, NULL);
	pthread_create(&tid12, NULL, shopscene, NULL);
	pthread_create(&tid13, NULL, eat, NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	pthread_join(tid5,NULL);
	pthread_join(tid6,NULL);
	pthread_join(tid7,NULL);
	pthread_join(tid8,NULL);
	pthread_join(tid9,NULL);
	pthread_join(tid10,NULL);
	pthread_join(tid11,NULL);
	pthread_join(tid12,NULL);
	pthread_join(tid13,NULL);
	return 0;
}
