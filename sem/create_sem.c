#include"../ipc.h"


//1.利用ftok函数产生关键字key。
//2.利用semget函数创建或打开IPC通道

int main()
{
	key_t sem_key=Ftok("mysem",0xff);
	printf("sem_key = %x\n",sem_key);

	//2.
	int sem_id=Semget(sem_key,1,IPC_CREAT|IPC_EXCL|0755);
	printf("sem_id = %d\n",sem_id);
	return 0;
}
