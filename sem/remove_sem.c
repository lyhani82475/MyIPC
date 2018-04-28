#include"../ipc.h"

int main()
{
	key_t sem_key=Ftok("mysem",0xff);
	
	//2.获取信号量的id
	int sem_id=Semget(sem_key,0,0);

	//3.删除信号量
	int i=semctl(sem_id,0,IPC_RMID);
	if(i==-1)
	{
		perror("semctl");
		exit(1);
	}
	printf("remove sem  sucess!\n");
	return 0;
}
