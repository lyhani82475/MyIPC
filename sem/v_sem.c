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

	struct sembuf v;
	v.sem_num=0;
	v.sem_op=1;
	v.sem_flg=0;
	int ret=Semop(sem_id,&v,1);
	printf("sem V sucess!\n");
	return 0;
}
