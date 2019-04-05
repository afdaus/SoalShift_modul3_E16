#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>

int arr[10000];
pthread_t tid[50];
int nilai;

void* tulis(void* args){
    unsigned long long fctr=1;
	for(int i=1; i<=nilai; ++i)
    {
        fctr = i*fctr;
    }
    printf("%d! Factorial = %llu\n",nilai,fctr);

}

void bubblesort(int arr[])
{
	int i,j,x;
	
 	for (i = 0; arr[i]!='\0'; ++i) 
    {
        for (j = i + 1; arr[j]!='\0'; ++j)
        {
            if (arr[i] > arr[j]) 
            {
                x =  arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }     
    }
}

int main(){
	int i=0;
	char temp;
	do {
	    scanf("%d%c", &arr[i], &temp);
	    i++;
	} while(temp != '\n');
	 
	bubblesort(arr);
	
	i=0;
	while(arr[i]!='\0')
	{
		nilai = arr[i];
		pthread_create(&tid[arr[i]], NULL, &tulis,(void *)&nilai);
	    pthread_join(tid[arr[i]],NULL);
	    //if (pthread_equal(tid[1], tid[2])) printf("Thread 2 is same as thread 1.\n");
		//else printf("Thread 2 is NOT same as thread 1.\n");
	    i++;
	}
	i=0;
	while(arr[i]!='\0')
	{
		//nilai = arr[i];
		//pthread_create(&tid[arr[i]], NULL, &tulis,(void *)&nilai);
	    pthread_join(tid[arr[i]],NULL);
	    //if (pthread_equal(tid[1], tid[2])) printf("Thread 2 is same as thread 1.\n");
		//else printf("Thread 2 is NOT same as thread 1.\n");
	    i++;
	}
	    
    return 0;
}
