#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#define DEL "\\/:;=- "


/*
 * Написать программу, которая в качестве аргумента командной строки
 * принимает имя текстового файла, содержащего слова. Необходимо вывести
 * на стандартный выходной поток список всех различных слов в файле в порядке убывания
 * количества вхождений слов (с указанием количества вхождений).
 * При реализации алгоритма необходимо использовать односвязный список,
 * каждый узел которого должен содержать указатель на слово и
 * количество вхождений этого слова. Слова во входном файле разделяются символами,
 * для которых библиотечные функции isspace() или ispunct() возвращают ненулевое значение.
 */

static int cmp (const void *a1, const void *a2) {
  int n1 = ((words_s *)a1)->count;
  int n2 = ((words_s *)a2)->count;
  return (n1 < n2)? -1: (n1 == n2)? 0: 1;
}

words_s* my_sort (words_s *list, int (*cmp)(const void *, const void *)){
  if (list) {
    words_s *res = list;
    list = list->next;
    res->next = NULL;

    while (list) {
      words_s *elem = list;
      list = list->next;
      if (cmp(elem,res) < 0) {
        elem->next = res;
        res = elem;
      } else {
        words_s *p = res;
        while (p->next) {
          if (cmp(p->next,elem) > 0) {
            break;
          }
          p = p->next;
        }
        elem->next = p->next;
        p->next = elem;
      }
    }
    list = res;
  }
  return list;
}

int main(void) {//int argc, char** argv) {
	int argc = 2; char** argv = {".", "test.txt"};
	if ( argc != 2 ) {
		printf("%s\n", strerror(EIO));
		printf("Run program this way: ");
		printf("./example.exe <name file>\n");
		return EIO;
	}

	FILE *file = fopen("test.txt", "r");
	if( !file ) {
		printf("%s", strerror(errno));
		return errno;
	}

	char str[1024];
	int i = 0;
	words_s *word_list;
	words_s *new_word;
	while(fgets(str, 1024, file)){
	//	printf("%s", str);
		char *word, *word1;
		word1 = strtok_r(str, DEL,  &word);
	//	printf("[dbg]%s\n", word1);
		for (;word != NULL;) {
			if (!i){
				printf("111\n");
				word_list = create_list_words(word1);
				i++;
				printf("1 %p\n", word_list);
			} else if (find_word(word1, word_list) && !isspace(word1) ) {
				printf("next %p\n", word_list);
				new_word = create_list_words(word1);
				word_list = add_word(word_list, new_word);
				i++;
				printf("new %p\n", word_list);
			}
			word1 = strtok_r(word, DEL,  &word);
			//printf("[dbg]%s\n", word1);
		}
		//if (find_word(word1, word_list) && !isspace(word1)) {
		//	new_word = create_list_words(word1);
		//	word_list = add_word(new_word, word_list);
		//	i++;
		//}
	}
	printf("\n\n");
	print_word_list(word_list);
	printf("\n\n");
	word_list = my_sort(word_list, cmp);
	print_word_list(word_list);

	fclose(file);
	return 0;
}
