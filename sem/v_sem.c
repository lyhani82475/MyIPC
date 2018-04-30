#include"../ipc.h"

int main()
{
	key_t sem_key=Ftok("mysem",0xff);
	int sem_id=Semget(sem_key,0,0);

	struct sembuf v;
	v.sem_num=0;
	v.sem_op=1;
	v.sem_flg=0;
	int ret=Semop(sem_id,&v,1);
	printf("sem V sucess!\n");
	return 0;
}
