#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define DEL "\\/:;=- "


/*
 * Написать программу, которая в качестве аргумента командной строки
 * принимает имя текстового файла, содержащего слова. Необходимо вывести
 * на стандартный выходной поток список всех различных слов в файле в порядке убывания
 * количества вхождений слов (с указанием количества вхождений).
 * При реализации алгоритма необходимо использовать односвязный список,
 * каждый узел которого должен содержать указатель на слово и
 * количество вхождений этого слова. Слова во входном файле разделяются символами,
 * для которых библиотечные функции isspace() илиispunct() возвращают ненулевое значение.
 */

struct words_s {
	int count;
	char *word;
	struct word_s *next;
};

struct words_s* add_word(struct word_s *head, struct word_s *word) {
	word->next = head;
	return word;
}

//struct words_s

int main(void) {//int argc, char** argv) {
	int argc = 2;
	char** argv = {".", "test.txt"};
	if ( argc != 2 ) {
		printf("%s\n", strerror(EIO));
		printf("Run program this way: ");
		printf("./example.exe <name file>\n");
		return EIO;
	}
	//printf("%s\n", argv[0]);
	FILE *file = fopen("test.txt", "r");
	if( !file ) {
		printf("%s", strerror(errno));
		return errno;
	}
	char str[1024];
	//printf("chaeck");
	int i = 0;
	while(fgets(str, 1024, file)){
		printf("%s", str);
		char *word, *word1;
		word1 = strtok_r(str, "\\/:;=- ",  &word);
		printf("[dbg]%s\n", word1);
		for (;word != NULL;) {
			word1 = strtok_r(word, DEL,  &word);
			printf("[dbg]%s\n", word1);
		}

	}
	//printf("check");

	fclose(file);
	return 0;
}
