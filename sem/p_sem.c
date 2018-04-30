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
	struct sembuf p;
	p.sem_num=0;
	p.sem_op=-1;
	p.sem_flg=0;
	int ret=Semop(sem_id,&p,1);
	printf("sem P sucess!\n");
	return 0;
}
