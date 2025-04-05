#include <stdio.h>
//#include <windows.h>
int main() {
//	system("chcp 1251");
    char* str = "dfkjd";
    printf("%s\n", str);
    printf("What\'s your name?\n");
    char s[100];
    scanf("%s", s);
    int age;
    printf("What\'s your age?\n");
    scanf("%d", &age);
    printf("Hello, %s!\n\tYour age = %d", s, age);
//	system("pause");
}
