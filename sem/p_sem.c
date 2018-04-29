#include"../ipc.h"

int main()
{
	key_t sem_key=Ftok("mysem",0xff);
	int sem_id=Semget(sem_key,0,0);
	struct sembuf p;
	p.sem_num=0;
	p.sem_op=-1;
	p.sem_flg=0;
	int ret=semop(sem_id,&p,1);
	if(ret==-1)
	{
		perror("semop");
		exit(1);
	}
	printf("sem P sucess!\n");
	return 0;
}
