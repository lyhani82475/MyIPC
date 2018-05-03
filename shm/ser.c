#include"../ipc.h"

//1.创建关键字
//2.创建共享内存
//3.链接共享内存
//同步机制：用信号量实现
//4.发送信息
//5.断开与共享内存的链接
//6.删除共享内存

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Error:>Please input %s pathname proj_id\n",argv[0]);
		exit(1);
	}
	key_t shm_key=Ftok(argv[1],atoi(argv[2]));
	int shm_id=Shmget(shm_key,1024,IPC_CREAT|IPC_EXCL|0755);

	char *addr=(char*)Shmat(shm_id,NULL,0);
	//同步机制
	
	int sem_id=Semget(shm_key,2,IPC_CREAT|IPC_EXCL|0755);
	union semun init;
	init.val=0;
	semctl(sem_id,0,SETVAL,init);//将信号量集中的0下标的信号量赋值为0
	semctl(sem_id,1,SETVAL,init);
	struct sembuf p={0,-1,0};//用0号信号量实现P操作
	struct sembuf v={1,1,0};

	//4
	while(1)
	{
		printf("Ser:>");//服务器先发起会话
		scanf("%s",addr);
		semop(sem_id,&v,1);//当服务器完成完成数据的输入后，希望客户端能读走数据，对1号信号量进行V操作，此时客户端就可对1号信号量进行P操作，以下P操作类似

		semop(sem_id,&p,1);
		printf("Cli:>%s\n",addr);
	}

	//5
	shmdt(addr);
	semctl(sem_id,IPC_RMID,0);//删除信号量集上的0号信号量
	semctl(sem_id,IPC_RMID,1);
	//6
	int ret=Shmctl(shm_id,IPC_RMID,NULL);//删除共享内存
	return 0;
}
