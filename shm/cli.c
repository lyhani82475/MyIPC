#include"../ipc.h"

int main(int argc,char *argv[])
{
	key_t shm_key=Ftok(argv[1],atoi(argv[2]));
	int shm_id=Shmget(shm_key,0,0);
	char *addr=Shmat(shm_id,NULL,0);
	int sem_id=Semget(shm_key,0,0);
	struct sembuf v={0,1,0};
	struct sembuf p={1,-1,0};
	while(1)
	{
		semop(sem_id,&p,1);
		printf("Ser:>%s\n",addr);
		printf("Cli:>");
		scanf("%s",addr);
		semop(sem_id,&v,1);
	}
	shmdt(addr);
	return 0;
}
