#include"../ipc.h"

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Error:>Please input %s pathname proj_id!\n",argv[0]);
		exit(1);
	}
	key_t sem_key=Ftok(argv[1],atoi(argv[2]));
	int sem_id=Semget(sem_key,0,0);
	int sem_val=semctl(sem_id,0,GETVAL);
	if(sem_val==-1)
	{
		perror("semctl");
		exit(1);
	}
	printf("sem val = %d \n",sem_val);
	return 0;
}
