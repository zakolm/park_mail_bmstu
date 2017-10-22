#ifndef __LIST__H__
#define __LIST__H__

typedef struct list_s {
	int count_in_text;
	char *word;
	struct word_s *next;
} list_s;

list_s* my_sort (list_s *list, int (*cmp)(const void *, const void *));
void print_word_list(list_s* new_list);
int find_word(char *word, list_s* new_list);
list_s* add_word(list_s *head, list_s *new_head);
list_s* create_list_words(char *word);
void free_all(list_s *head);
list_s* push_word(const char* word, list_s* word_list);

#endif //__LIST__H__
