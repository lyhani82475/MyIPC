#pragma once

#include<stdio.h>
#include<sys/ipc.h>//ftok
#include<sys/sem.h>
#include<stdlib.h>//exit

//////////////////////////////////////////////////////////
//ftok

key_t Ftok(const char* pathname,int proj_id)
{
	key_t key=ftok(pathname,proj_id);
	if(key==-1)
	{
		perror("ftok");
		exit(1);
	}
	return key;
}

//////////////////////////////////////////////////////////
//sem

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

int Semget(key_t key,int nsems,int semflg)
{
	int sem_id=semget(key,nsems,semflg);
	if(sem_id==-1)
	{
		perror("semget");
		exit(1);
	}
	return sem_id;
}


///////////////////////////////////////////////////////////
