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
key_t key = 1234;
void* cetak(void *arg)
{
	while(1)
	{
        	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        	stok = shmat(shmid, NULL, 0);
		printf("stok saat ini: %d\n",*stok);
		sleep(5);
		shmdt(stok);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, cetak,NULL);
	int cek_konek=0;
	int server_fd,new_socket;
	struct sockaddr_in address;
	int opt = 1,valread;
	int addrlen = sizeof(address);
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
	if (listen(server_fd, -1) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
	if(cek_konek==0)
	{
		cek_konek++;
		if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
		{
			close(new_socket);
			perror("accept");
			exit(EXIT_FAILURE);
		}
	}
		int soket = new_socket;
                int temp;
                char buffer[1024]= {0};
                temp = *stok;
                char input[10];
                char exit[10];
                strcpy(exit,"exit");
                strcpy(input,"tambah");
                valread = read(soket, buffer, 1024);
                if(strcmp(exit,buffer)==0)
                {
                        send(soket, "Exit Server", strlen("Exit Server"), 0);
                        break;
                }
                if(strcmp(input,buffer)==0)
                {
   			temp++;
                       	*stok = temp;
			send(soket, "Transaksi Berhasil", strlen("Transaksi Berhasil"), 0);
                }
                else
                {
                        send(soket, "invalid input", strlen("invalid input"), 0);
                }
        }
	close(new_socket);
	return 0;
}

