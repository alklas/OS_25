//Программа, анализирующая аргументы командной строки
#include <stdio.h>

int main(int argc, char* argv[], char* envp[]) {
	//Количество аргументов, переданных программе - argc
	printf("Программе передано %d аргументов\n\n", argc);

	if (argc>=2) {
		//Список значений аргументов (массив argv)
		for (int i=0; i<argc; i++)
			printf("Аргумент [%d]: %s\n", i, argv[i]);
		printf("\n");
	}
	else {
		//Список значений переменных среды
		int j=0;

		while (envp[j]!=NULL) {
			printf("%d %s\n", j, envp[j]);
			j++;
		}
	}
}
