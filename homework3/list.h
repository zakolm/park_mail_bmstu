#ifndef __LIST__H__
#define __LIST__H__

typedef struct words_s {
	int count;
	char *word;
	struct word_s *next;
} words_s;

words_s* my_sort (words_s *list, int (*cmp)(const void *, const void *));
void print_word_list(words_s* new_list);
int find_word(char *word, words_s* new_list);
words_s* add_word(words_s *head, words_s *new_head);
words_s* create_list_words(char *word);

#endif //__LIST__H__
