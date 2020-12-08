#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int Checklet(char d){
	if ((d >= 'a') && (d <= 'z')) {
		return 1;
	}
	if ((d >= 'A') && (d <= 'Z')) {
		return 1;
	}
	return 0;

}
// посимвольное получение динамической строки с пробелами c получением её реальной длины
char* get_string(int* len) {
	*len = 0; // изначально строка пуста
	int capacity = 1; // ёмкость контейнера динамической строки (1, так как точно будет '\0')
	char* s = (char*)malloc(sizeof(char)); // динамическая пустая строка

	char c = getchar(); // символ для чтения данных

	// читаем символы, пока не получим символ переноса строки (\n)
	while (c != '\n') {

		s[(*len)++] = c; // заносим в строку новый символ

		// если реальный размер больше размера контейнера, то увеличим его размер
		if (*len >= capacity) {
			capacity *= 2; // увеличиваем ёмкость строки в два раза
			s = (char*)realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной ёмкостью  
		}

		c = getchar(); 
		// считываем следующий символ          
	}

	s[*len] = '\0'; // завершаем строку символом конца строки

	return s; // возвращаем указатель на считанную строку
}

int main() {
	
	int len=0;
	char str[100];
	int size;
	int len2 = 0;
	int answer = 0;
	int blen;
	
	printf(" enter word\n");
	char* s = get_string(&blen);
	for (int i = 0; i < blen; i++) {
		if (Checklet(s[i]) != 1) {
			return printf("not a word");
		}
	}
	printf(" enter string\n");

	fgets(str, sizeof(str), stdin);
	for (int i = 0; i < sizeof(str); i++) {
		if (Checklet(str[i]) != 1) {
			str[i] = '\0';
		}
	}
	for (int i = 0; i < sizeof(str); i++) {
		if (str[i] != '\0') {
			if (len2 > blen) {
				break;
			}
			len2++;
		}
		else { 
			if (blen == len2)answer++;
			len2 = 0; 
		}
	}
	printf("%d", answer);

	return 0;
}