#include"../ipc.h"

int main()
{
	key_t sem_key=Ftok("mysem",0xff);
	int sem_id=Semget(sem_key,0,0);
	union semun init;
	init.val=3;
	int i=semctl(sem_id,0,SETVAL,init);
	if(i==-1)
	{
		perror("semctl");
		exit(1);
	}
	printf("set sem sucess!\n");
	return 0;
}
