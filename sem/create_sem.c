#include"../ipc.h"


//1.利用ftok函数产生关键字key。
//2.利用semget函数创建或打开IPC通道

int main(int argc,char *argv[])
{
	if(argc!=4)
	{
		printf("Error:>Please input %s pathname proj_id nsems!\n",argv[0]);
		exit(1);
	}
	key_t sem_key=Ftok(argv[1],atoi(argv[2]));//atoi函数是将字符串转换为整数
	printf("sem_key = %x\n",sem_key);

	//2.
	int sem_id=Semget(sem_key,atoi(argv[3]),IPC_CREAT|IPC_EXCL|0755);
	printf("sem_id = %d\n",sem_id);
	return 0;
}
