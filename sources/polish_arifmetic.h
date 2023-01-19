#ifndef POLISH_ARIFMETIC_H
#define POLISH_ARIFMETIC_H

#include <math.h>
#include "list.h"
#include "in_polish.h"
#include <stdio.h>
#include <stdlib.h>



double polish_arifmetic(item_list **polish_string);
void return_result_oper(double a, double b, int oper, item_list *result_element);
void return_result_tg_oper(item_list *result_element, int oper);

#endif
