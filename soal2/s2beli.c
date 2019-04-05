#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#define PORT 8080
int *stok;
pthread_t tid;
int new_socket;

void* baca_input()
{
	while(1)
	{
		int soket = new_socket;
		int temp,valread;
		char buffer[1024]= {0};
		temp = *stok;
		char input[10];
       		char exit[10];
        	strcpy(exit,"exit");
        	strcpy(input,"beli");
        	valread = read(soket, buffer, 1024);
                if(strcmp(exit,buffer)==0)
                {
                        shmdt(stok);
                        send(soket, "Exit Server", strlen("Exit Server"), 0);
                        break;
                }
                if(strcmp(input,buffer)==0)
                {
                        if(temp>0)
                        {
                                temp--;
                                *stok = temp;
                                send(soket , "transaksi berhasil" , strlen("transaksi berhasil"),0);
                        }
                        else
                        {
                                send(soket , "transaksi gagal" , strlen("transaksi gagal"),0);
                        }
                }
                else
                {
                        send(soket, "invalid input", strlen("invalid input"), 0);
                }
	}
}

int main(int argc, char const *argv[])
{
	key_t key = 1234;
	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	stok = shmat(shmid, NULL, 0);
	int server_fd;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char *hello = "Hello from server";
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	pthread_create(&(tid), NULL, &baca_input,NULL);
	pthread_join(tid,NULL);
	return 0;
}

