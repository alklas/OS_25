//Программа для чтения информации из FIFO
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
	printf("Процесс-приёмник готов к чтению информации из FIFO\n");
	if((fd = open(name, O_RDONLY)) < 0) {
		printf("Не удалось открыть FIFO на чтение\n");
		exit(-1);
	}
	size = read(fd, resstring, BYTES);
	if (size < 0) {
		printf("Не удалось прочитать строки из FIFO\n");
		exit(-1);
	}
	printf("Содержимое прочитанной строки: %s\n", resstring);
	if(close(fd) < 0) {
		printf("Не удалось закрыть FIFO\n");
		exit(-1);
	}
	printf("Процесс-приёмник завершает работу\n");
	return 0;
}
