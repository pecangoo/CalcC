
#include "in_polish.h"


#define elif else if


int priority_of_operation(int operation) {
    /**
     * @brief Определяет приоритет операции при подсчете польской записи
     */
    int priority = 0;
    if (operation == BRO || operation == BRC) {
        priority = 1;
    } else if (operation == SUM || operation == SUB) {
        priority = 2;
    } else if (operation == MUL || operation == DIV ||  operation == MOD) {
        priority = 3;
    } else if (  operation == POW || operation == SQRT || operation == COS ||
                 operation == SIN || operation == TAN || operation == CTG || operation == LN ||
                 operation == ACOS || operation == ASIN || operation == ATAN || operation == LOG) {
        priority = 4;
    } else if (operation == PLUS || operation == MINUS) {
       // printf("Unaric opertion\n");
        priority = 5;
    } else {
    //    printf("Error in priority: %d\n", operation);
    }
    return priority;
}

int polish_notation(item_list *parced_list, item_list **result_list) {
/**
 * @brief Функция переводит входящую строку в польскую
 */
    item_list* current_parced_list = parced_list;  // Текущий элемент входящего списка
    item_list *stck_head = NULL;  // Заголовок рабочего стака
    while (1) {
        if (current_parced_list->value.item_type == NUM) {  // Если число
            // Заносим в стек, создавая ноду в списке результата
            insert_element_to_list(result_list, current_parced_list->value, END);
        } else if (current_parced_list->value.item_type == OPER ||
                    current_parced_list->value.item_type == OPER_U) {
            checking_node(&stck_head, result_list, current_parced_list->value);
        }
        if (current_parced_list) {
            if (current_parced_list->next) {
                current_parced_list = current_parced_list->next;
            } else {
                insert_stack_to_result_reverse_simple(&stck_head, result_list);
                break;
            }
        }
    }
    return 0;
}


void checking_node(item_list **stck, item_list** result, element_of_list current_element) {
    /**
     * Проверяет входящую ноду
     */
    if (current_element.operation == BRO) {
        insert_element_to_list(stck, current_element, END);
    } else if (current_element.operation == BRC) {
        item_list * current_stck_pos = return_last_element_of_list(*stck);
        while (current_stck_pos->value.operation != BRO) {
            insert_element_to_list(result, current_stck_pos->value, END);
            current_stck_pos = current_stck_pos->before;
            remove_element_from_list(stck, END);
        }
        if (current_stck_pos->value.operation == BRO)
            remove_element_from_list(stck, END);
        } else {
        item_list * last_stck_pos = return_last_element_of_list(*stck);
        if (last_stck_pos) {
            if (current_element.priority <= last_stck_pos->value.priority) {
                // Выдавливаем все из стака
                // В конце добавляем в стак
                insert_stack_to_result_reverse(stck, result, current_element.priority);
                insert_element_to_list(stck, current_element, END);
            } else if (current_element.priority > last_stck_pos->value.priority) {
                insert_element_to_list(stck, current_element, END);
            }
        } else {
            insert_element_to_list(stck, current_element, END);
        }
    }
}

void insert_stack_to_result_reverse(item_list** stack, item_list **result, int priority) {
   /**
    *  Добавляет в стак все элементы до открывающей скобки, пока совпадает условие
    */
    item_list *current_element = return_last_element_of_list(*stack);
    unsigned int priority_last_element = priority;
    if (current_element) {
        if (priority_last_element <= current_element->value.priority) {
            insert_element_to_list(result, current_element->value, END);
            remove_element_from_list(stack, END);
            current_element = return_last_element_of_list(*stack);
            if (current_element) {
                while (priority_last_element <= current_element->value.priority &&
                        current_element->value.operation != BRO) {
                    insert_element_to_list(result, current_element->value, END);
                    current_element = current_element->before;
                    remove_element_from_list(stack, END);
                    if (!current_element)
                        break;
                }
            }
        }
    }
}

void insert_stack_to_result_reverse_simple(item_list** stack, item_list **result) {
    /**
     * добавляет из стака элементы в результат без условий
     * Работает только в конце
     */ 
    item_list *current_stack_position = return_last_element_of_list(*stack);
    while (current_stack_position) {
        insert_element_to_list(result, current_stack_position->value, END);
        remove_element_from_list(stack, END);
        current_stack_position = return_last_element_of_list(*stack);
    }
}
/*
void test_show_struct_polish(item_list* head_list) {
    /// @brief  Тестовая функция для показа структуры
    /// @param head_list
    item_list* p = NULL;
    if (head_list) {
        p = head_list;
        while (1) {
            if (p->value.item_type == NUM) {  // Если число
                printf("Value: %f\n", p->value.num);
            } else if (p->value.item_type == OPER  || p->value.item_type == OPER_U) {
                printf("Oper: %d  Priority: %d Pointer: %p, Before; %p, Next: %p, Type: %d\n",
                    p->value.operation, p->value.priority, p,
                    p->before, p->next, p->value.item_type);
            } else {
                printf("Err: %d\n", p->value.item_type);
            }
            if (!p->next) {
                break;
            }
            p = p->next;
        }
    } else {
        printf("NULL 149\n");
    }
}
*/
