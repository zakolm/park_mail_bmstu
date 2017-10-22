#include "list.h"

list_s* create_list_words(char *word) {
	list_s *word_list = (list_s*) malloc(sizeof(list_s));
	if (word) {
		word_list->count_in_text = 1;
		word_list->word = word;
		word_list->next = 0;
	}
	
	return word_list;
}

list_s* add_word(list_s *head, list_s *new_head) {
	new_head->next = (list_s*) head;
	return new_head;
}

list_s* push_word(const char* word, list_s* word_list) {
	list_s *new_word = (list_s*) create_list_words(word);
	return ( (list_s*)add_word(word_list, new_word));
}

void free_all(list_s *head) {
	list_s *next;
// while(next) ?
    //while (head)
    //	next = head->next;
    //	free(head);
    //	head = next;
    //
    for ( ; head; head = next)
    {
        next = (list_s*) head->next;
        free(head);
    }
}

void print_word_list(const list_s* new_list) {
	for (; new_list; new_list = new_list->next) {
		printf("%d %s\n", new_list->count_in_text, new_list->word);
	}
}

int find_word(char *word, list_s* my_list) {
	for (; my_list; my_list = my_list->next) {
		i++;
		printf("%d", i);
		if ( !strcmp(word, my_list->word) ){
			my_list->count_in_text++;
			return 0;
		}
	}
	return 1;
}
