#ifndef IN_POLISH_H
#define IN_POLISH_H

#include <math.h>
#include "list.h"
#include <stdio.h>

int polish_notation(item_list *noda, item_list **result);
int priority_of_operation(int operation);
void checking_node(item_list **stck, item_list **result, element_of_list current_element);
void insert_stack_to_result_reverse(item_list** stack, item_list **result, int priority);
void insert_stack_to_result_reverse_simple(item_list** stack, item_list **result);


void test_show_struct_polish(item_list* head_list);

#endif