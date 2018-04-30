#include"../ipc.h"

int main(int argc,char *argv[])
{
	if(argc!=4)
	{
		printf("Error:>Please input %s pathname proj_id sem_value\n",argv[0]);
		exit(1);
	}
	key_t sem_key=Ftok(argv[1],atoi(argv[2]));
	int sem_id=Semget(sem_key,0,0);
	union semun init;
	init.val=atoi(argv[3]);
	int i=semctl(sem_id,0,SETVAL,init);
	if(i==-1)
	{
		perror("semctl");
		exit(1);
	}
	printf("set sem sucess!\n");
	return 0;
}
