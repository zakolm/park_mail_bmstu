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

static int cmp (const void *value_a, const void *value_b) {
  int value_1 = ((list_s *)value_a)->count_in_text;
  int value_2 = ((list_s *)value_b)->count_in_text;
  return (value_1 < value_2)? -1: (value_1 == value_2) ? 0: 1;
}

list_s* my_sort (list_s *my_list, int (*cmp)(const void *, const void *)){
  if ( my_list ) {
	  list_s *res = my_list;
	  my_list = (list_s*) my_list->next;
	  res->next = NULL;
	  // 1 3 4 5 8 6 10 12 13
	  while ( my_list ) {
		  list_s *elem = my_list;
		  my_list = (list_s*) my_list->next;
      if ( cmp(elem,res) < 0 ) {
        elem->next = (list_s*) res;
        res = elem;
      } else {
    	  list_s *p = res;
        while (p->next) {
          if ( cmp(p->next,elem) > 0 ) {
            break;
          }
          p = (list_s*) p->next;
        }
        elem->next = p->next;
        p->next = (list_s*) elem;
      }
    }
    my_list = res;
  }
  return my_list;
}

int main(void) {//int argc, char** argv) {
	int argc = 2;char** argv = {".", "test.txt"};
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
	short flag_first_word = 0;
	list_s *word_list;

	while(fgets(str, 1024, file)){
		char *work_str, *word;
		word = strtok_r(str, DEL,  &work_str);
		while( work_str != NULL ) {
			if ( !flag_first_word ){
				word_list = create_list_words(word);
				flag_first_word++;
			} else if ( find_word(word, word_list) && !strchr(word, '\n') ) {
				word_list = push_word(word, word_list);
			} else if ( !find_word(word, word_list) ) {

			}
			word = strtok_r(work_str, DEL,  &work_str);
		}

		if ( find_word(word, word_list) && !strchr(word, '\n') ) {
			word_list = push_word(word, word_list);
		}
	}
	print_word_list(word_list);
	printf("\n\n");
	word_list = my_sort(word_list, cmp);
	print_word_list(word_list);
	free_all(word_list);

	fclose(file);
	return 0;
}
