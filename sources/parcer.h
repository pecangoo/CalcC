
#ifndef PARCER_H
#define PARCER_H


#include "list.h"
#include "in_polish.h"
#include <stdio.h>
#include <string.h>




int get_lexems_from_input_test(item_list ** head_list, char* str_input);
int tg_search(int * i, char * str_input, char * c, element_of_list* a);
int numbers_search(int * i, char * str_input, char * c, element_of_list* a);
int ret_tg_operations(element_of_list* a, char *temp);
void ret_math_operations(element_of_list* a, char c);
void numbers(element_of_list* a, char * c);
int checking_input (item_list *str_input);



#endif
