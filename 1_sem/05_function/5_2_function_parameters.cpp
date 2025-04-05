#include <stdio.h>

// Для C и C++

void func_1(int parameter) {
	parameter = 1000;
	printf("In func_1: parameter = %d\n", parameter);
}

void func_2(const int parameter) {
	// parameter = 1000; //ошибка компиляции
	printf("In func_2: parameter = %d\n", parameter);
}

void func_3(int* parameter) {
	*parameter = 1000;
	printf("In func_3: parameter = %d\n", *parameter);
	// 
	parameter = NULL;
	parameter = nullptr; // доступно с C++11
}

void func_4(int* const parameter) {
	*parameter = 1000; //OK
	printf("In func_4: parameter = %d\n", *parameter);
	// parameter = nullptr; //Ошибка
}

void func_5(const int* const parameter) {
//	*parameter = 1000; //Ошибка
	printf("In func_5: parameter = %d\n", *parameter);
//	parameter = nullptr; //Ошибка
}

int main() {
}
