#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <Windows.h>

#define MAX_LENGHT_LIST 1000

int *pa;
int n;

void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void Load();
void SaveResult();


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	task_5();
}

void task_1() {
	printf("Rauf Fathutdinov\n");
	printf("Task one\n");
    
	int list[MAX_LENGHT_LIST], list_result[MAX_LENGHT_LIST];
	int summa = 0, result, n_res = 0;

	FILE* finp = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\input19_1.txt", "rt");

	if (finp == NULL) {
		printf("File not find");
		return;
	}
	printf("Input list:\n");
	fscanf(finp, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(finp, "%d", &list[i]);
		printf("%d ", list[i]);
		summa += list[i];
	}
	printf("\n");
	fclose(finp);

	result = summa / n;
	printf("Result = %d\n", result);
	for (int i = 0; i < n; i++) {
		if (list[i] > result) {
			list_result[n_res] = list[i];
			n_res += 1;
		}
	}

	FILE* fout = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\result19_1.txt", "wt");

	if (fout == NULL) {
		printf("File not find");
		return;
	}
	printf("Lenght new of list = %d: ", n_res);
	fprintf(finp, "%d\n", n_res);
	for (int i = 0; i < n_res; i++) {
		fprintf(finp, "%d ", list_result[i]);
		printf("%d ", list_result[i]);
	}
	fclose(fout);
}

void task_2() {
	printf("Rauf Fathutdinov\n");
	printf("Task two\n");

	Load();
	SaveResult();

	free(pa);
}

void task_3() {
	printf("Rauf Fathutdinov\n");
	printf("Task three\n");

	FILE* fin = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\input19_3.txt", "rt");

	if (fin == NULL) {
		printf("File not found");
		return;
	}

	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	fclose(fin);

	float sa = 0;
	float s = 0;
	int m = 0;

	for (int i = 0; i < n; i++) {
		s += pa[i];
	}

	sa = s / n;

	for (int i = 0; i < n; i++) {
		if (pa[i] > 0 && pa[i] < sa) {
			m++;
		}
	}

	FILE* fout = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\result19_3.txt", "wt");

	if (fout == NULL) {
		printf("File not found");
		return;
	}

	fprintf(fout, "%d\n", m);

	for (int i = 0; i < n; i++) {
		if (pa[i] > 0 && pa[i] < sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);

}

void task_4() {
	printf("Rauf Fathutdinov\n");
	printf("Task four\n");

	FILE* fin = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\input19_4.txt", "rt");

	if (fin == NULL) {
		printf("File not found");
		return;
	}

	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	fclose(fin);

	float max = 0;
	int m = 0;

	for (int i = 0; i < n; i++) {
		if (max < pa[i]) {
			max = pa[i];
		}
	}

	max = max * 2 / 3;

	for (int i = 0; i < n; i++) {
		if (max < pa[i]) {
			m++;
		}
	}

	FILE* fout = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\result19_4.txt", "wt");

	if (fout == NULL) {
		printf("File not found");
		return;
	}

	fprintf(fout, "%d\n", m);

	for (int i = 0; i < n; i++) {
		if (pa[i] > max) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);

}

void task_5() {
	printf("Rauf Fathutdinov\n");
	printf("Task five\n");

	int time_var = 1000000;

	FILE* fin = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\input19_5.txt", "rt");

	if (fin == NULL) {
		printf("File not found");
		return;
	}

	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	fclose(fin);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (pa[j] % 2 == 0 && time_var > pa[j]) {
				time_var = pa[j];
				pa[j] = pa[i];
				pa[i] = time_var;
			}
		}
		if (time_var == 1000000) {
			time_var = 0;
			for (int j = i; j < n; j++) {
				if (pa[j] % 2 == 1 && time_var < pa[j]) {
					time_var = pa[j];
					pa[j] = pa[i];
					pa[i] = time_var;
				}
			}
		}
		time_var = 1000000;
	}

	FILE* fout = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\result19_5.txt", "wt");

	if (fout == NULL) {
		printf("File not found");
		return;
	}

	fprintf(fout, "%d\n", n);

	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d ", pa[i]);
	}

	fclose(fout);
}

void Load() {
	FILE* fin = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\input19_2.txt", "rt");

	if (fin == NULL) {
		printf("File not found");
		return;
	}

	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	fclose(fin);
}

void SaveResult() {

	float sa = 0;
	float s = 0;
	int m = 0;

	for (int i = 0; i < n; i++) {
		s += pa[i];
	}

	sa = s / n;

	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) {
			m++;
		}
	}

	FILE* fout = fopen("d:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_18\\text_file\\result19_2.txt", "wt");

	if (fout == NULL) {
		printf("File not found");
		return;
	}

	fprintf(fout, "%d\n", m);

	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);
}