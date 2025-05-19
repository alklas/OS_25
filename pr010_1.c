//Программа-отправитель информации в FIFO

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BYTES 44

int main() {
	int fd;
	size_t size;
	char resstring[BYTES];
	char name[]="file.fifo";
	/*
	if(mknod(name, S_IFIFO | 0664, 0) < 0) {
		printf("Не удалось создать файл FIFO\n");
		exit(-1);
	}
	*/

	printf("Процесс-отправитель начинает запись в FIFO\n");
	if((fd = open(name, O_WRONLY))<0) {
		printf("Не удалось открыть FIFO на запись\n");
		exit(-1);
	}
	size = write(fd, "Текстовая строка для FIFO", BYTES);
	if(size != BYTES) {
		printf("Не удалось записать всю строку в FIFO\n");
		exit(-1);
	}
	if(close(fd)<0) {
		printf("Не удалось закрыть FIFO\n");
		exit(-1);
	}
	printf("Отправитель записал строку в FIFO и завершает работу\n");
	return 0;
}
