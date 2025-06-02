//Работа с семафорами IPC
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int semid; //IPC-дескриптор для массива семафоров IPC
	char pathname[] = "pr012a.c";
	key_t key; //IPC-ключ
	struct sembuf mybuf; //Структура для задания операций над семафором
	//Генерация IPC-ключа
	if((key = ftok(pathname, 0))<0) {
		printf("Не удалось сгенерировать IPC-ключ\n");
		exit(-1);
	}
	if((semid = semget(key, 1, 0666|IPC_CREAT))<0) {
		printf("Не удалось получить IPC-дескриптор\n");
		exit(-1);
	}
	mybuf.sem_op=-1;
	mybuf.sem_flg=0;
	mybuf.sem_num=0;
	if(semop(semid, &mybuf, 1) < 0) {
		printf("Не удалось выполнить операцию D для семафора\n");
		exit(-1);
	}
	printf("Условия для разблокирования процесса выполнены\n");
	return 0;
}
