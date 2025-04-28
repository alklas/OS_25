//Изменение пользовательского контекста процесса во время выполнения программы
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
	printf("Программа начала работу ...\n");
	(void) execle("/bin/cat", "/bin/cat", "./pr007.c", 0, envp);
	printf("Ошибка при выполнении системного вызова exec\n");
	exit(-1);
	return 0;
}
