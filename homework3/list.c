#include "list.h"

words_s* create_list_words(char *word) {
	words_s *word_list;
	word_list = (words_s*) malloc(sizeof(words_s));
	if (word) {
		word_list->count = 1;
		word_list->word = word;
		word_list->next = 0;
	}
	return word_list;
}

words_s* add_word(words_s *head, words_s *new_head) {
	new_head->next = head;
	return new_head;
}

void print_word_list(words_s* new_list) {
	for (; new_list; new_list = new_list->next) {
		printf("%d %s\n", new_list->count, new_list->word);
	}
}

int find_word(char *word, words_s* new_list) {
	//words_s *new_list = &word_list;
	int i = 0;
	for (; new_list; new_list = new_list->next) {
		i++;
		printf("%d", i);
		if ( !strcmp(word, new_list->word) ){
			printf("check");
			new_list->count++;
			return 0;
		}
	}
	return 1;
}
