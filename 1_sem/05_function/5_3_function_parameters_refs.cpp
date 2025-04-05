#include <stdio.h>

// Для C и C++

void func_6(int& parameter) {
	parameter = 1000;
	printf("In func_6: parameter = %d\n", parameter);
}

void func_7(const int& parameter) {
//	parameter = 1000; //Ошибка
	printf("In func_2: parameter = %d\n", parameter);
}

int main() {
	int n = 5;
	printf("In main before func_6() n = %d\n", n);
	func_6(n);
	printf("In main after func_6() n = %d\n", n);
	n = 5;
	
	// Этот код не будет скомпилирован
	// func_6(5);

	// А с этим все хорошо
	func_7(n);

	// Компилируется только для константных ссылок
	func_7(5);

	//Ссылки (reference) можно использовать и вне функций
	int value = 10;
	int& valueRef = value; //обязательно нужно инициализировать при объявлении
	valueRef++;
	printf("value = %d, valueRef = %d\n", value, valueRef);
}
