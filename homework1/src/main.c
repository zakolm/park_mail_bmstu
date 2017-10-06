#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "result.h"
#include "CONSTANT.h"

/*
 * Необходимо для входного слова посчитать медиану его вхождений в предложенния входного документа.
 * Т.е. надо найти такое кол-во вхождений x заданного слова в предложения, что кол-во предложений,
 * в которые слово входило не более x раз, максимально близко к кол-ву предложений, в которые это
 * слово входило более x раз.
 */

// Мое сравнение строк, без учета регистра.
int my_strcmp(char* a, char* b) {
	if ( strlen(a) != strlen(b) )
		return 1;
	int i = 0;
	for ( ; i < strlen(a); ++i ) {
		if ( (tolower(*(a+i)) - tolower(*(b+i))) ) {
			return 1;
		}
	}
	return OK;
}

// Вывод массива вхождений для Debug
void cout(const int* array, const int count) {
	int j = 0;
	for ( ; j < count; ++j ) {
		printf("%d %d\n", *(array+j), j);
	}
}

int main(int argc, char** argv) {
	if ( argc != 3 ) {
		printf("./example.exe <word> <name file>\n");
		return ERROR_INPUT;
	}

    FILE *f = fopen(*(argv+2), "r");
    if ( !f ) {
    	fprintf(stderr, "File not %s found! %s\n", *(argv+2), strerror(errno));
    	return ERROR_FILE;
    }

    int register_word = -1, count_sentence = 0, Max_Len_Word = 10, count_myword_in_sentensce = 0, Max_Len_Sentence = 2;

    int *sentence_myword = (int*) malloc(sizeof(*sentence_myword)*Max_Len_Sentence);
    if ( !sentence_myword ) {
		printf("Fail with memory! I'm so sorry:(\n");
		return ERROR_WORK_WITH_MEMORY;
	}

    char *word = (char*) malloc(sizeof(*word)*Max_Len_Word), *super = *(argv+1), tmp_item_char;
    if ( !word ) {
    	printf("Fail with memory! I'm so sorry:(\n");
    	return ERROR_WORK_WITH_MEMORY;
    }
    // Обнуление строки word.
    clear(Max_Len_Word, word);

    // Работа с нашим файлом по символам.
    while( (tmp_item_char = fgetc(f)) != EOF ) {
    	// Увеличение длины слова.
        if ( register_word >= Max_Len_Word ) {
        	Max_Len_Word += 10;
            word = (char*) realloc(word, sizeof(*word)*Max_Len_Word);
            if ( !word ) {
            	printf("Fail with memory! I'm so sorry:(\n");
            	return ERROR_WORK_WITH_MEMORY;
            }
        }
        // Проверка на конец предложения.
        if ( tmp_item_char == '.' || tmp_item_char == '!' || tmp_item_char == '?') {
            count_sentence++;

            // Сравнивание последнего слова.
			if ( !my_strcmp(word, super) ) {
				++count_myword_in_sentensce;
			}
			// Считываем пробел после символа окончания строки, чтобы не допустить "ложного сравнения".
			tmp_item_char = fgetc(f); clear(register_word, word); register_word = -1;

			// Увеличиваем число предложений.
			if ( count_sentence > Max_Len_Sentence ) {
				Max_Len_Sentence *= 2;
				sentence_myword = (int*) realloc(sentence_myword, sizeof(*sentence_myword)*Max_Len_Sentence);
				if ( !sentence_myword ) {
					printf("Fail with memory! I'm so sorry:(\n");
					return ERROR_WORK_WITH_MEMORY;
				}
			}
			sentence_myword[count_sentence-1] = count_myword_in_sentensce;
            count_myword_in_sentensce = 0;

        } else if ( isspace(tmp_item_char) || ispunct(tmp_item_char) ) {

        	// Сравнивание слов после пробелов.
        	if ( !my_strcmp(word, super) ) {
				++count_myword_in_sentensce;
			}
        	// Обнуление строки word.
			clear(register_word, word); register_word = -1;
        } else {
        	++register_word;
            *(word+register_word) = tmp_item_char;
        }
    }

    free(word);
    //[DBG]
    //cout(sentence_myword, count_sentence);

    // Нахождение и печать медианы.
    int* end_sentence_myword = sentence_myword+count_sentence;
    qsort(sentence_myword, end_sentence_myword - sentence_myword, sizeof(sentence_myword[0]), compare);
    int med = mediana(count_sentence, sentence_myword);

    printf("Mediana : %d\n", med);
    //[DBG]
    //cout(sentence_myword, count_sentence);

    free(sentence_myword);

    fclose(f);

    return OK;
}
