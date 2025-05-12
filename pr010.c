#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BYTES 44

int main() {
	int fd, result;
	size_t size;
	char resstring[BYTES];
	char name[]="file.fifo";
	/*
	if(mknod(name, S_IFIFO | 0664, 0) < 0) {
		printf("Не удалось создать файл FIFO\n");
		exit(-1);
	}
	*/
	if ((result = fork()) < 0) {
		printf("Не удалось создать дочерний процесс\n");
		exit(-1);
	}
	else if (result > 0) {
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
		printf("Родитель записал строку в FIFO и завершает работу\n");
	}
	else {
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
	}
	return 0;
}
