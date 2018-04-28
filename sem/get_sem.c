#include"../ipc.h"

int main()
{
	key_t sem_key=Ftok("mysem",0xff);
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
