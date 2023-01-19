
#include "parcer.h"

void unaric_transform(item_list **parced_list);
int is_operation_binary(item_list* operation);
int is_operation_tg(item_list* operation);

int get_lexems_from_input_test(item_list ** head_list, char* str_input) {
/**
* Данная функция парсит с входящей строки лексемы и записывает их в список
*/
    item_list* last_list = *head_list;
    int ret = 0, i = 0;
    char c;
    while (str_input[i] != '\0' && str_input[i] != '\n' && ret != -1) {
        element_of_list a;
        c = str_input[i];
        if (str_input[i] == ' ') {
            i++;
            continue;
        } else if (c == '*' || c == '/' || c == '+' ||
            c == '-' || c == '(' || c == ')' || c == '^') {
           // printf("Math operation: %c\n", c);
            ret_math_operations(&a, c);
        } else if ((c <= '9' && c >= '0') || c == '.'  || c == ',') {
            // Ищем число в строке и возвращаем его в виде массива?
            if (numbers_search(&i, str_input, &c, &a) == -1) {
                ret = -1;
                break;
            }
        } else if (c == 'c' || c == 't' || c == 's' || c == 'l' || c == 'm' || c == 'a') {
            if (tg_search(&i, str_input, &c, &a) == -1) {
                ret = -1;
                break;
            }
        } else {
            ret = -1;
            break;
        }
        i += 1;
        a.priority = priority_of_operation(a.operation);
        insert_element_to_list(&last_list, a, END);
        if (!*head_list)
            *head_list = last_list;
    }
    if (ret == 0) {
        unaric_transform(head_list);
        ret = checking_input(*head_list);
        //  test_show_struct_polish(*head_list);
    }
    return ret;
}

int checking_input(item_list *str_input) {
    /**
     * Проверяет входящую строку на корректность ввода
     */ 

    int ret = 0;
    // Прогоняем циклично список
    // 1. Счетчик скобок. Если открывается скобка, то +1, если закрывается, то -1. В итоге должно получится 0.
    // 2. Проверка корректности очередности операций
    int counter_breaks = 0;
    while (str_input) {
        if (str_input->value.operation == BRO) {
            counter_breaks++;
            // После скобки могут стоять: число, унарная операция,тригонометрическая операция
            // Если после скобки стоит бинарная операция - ошибка +-*/^mod
            // Если после скобки ничего нет - ошибка(дублирует счетчик скобок
            if (str_input->next) {  //  Если существует следующая операция
                if (is_operation_binary(str_input->next)) {
                   // printf("Неверная лексема после открывающей скобки.\n");
                    ret = 2;
                }
            } else {
               // printf("После открывающей скобки нет лексемы.\n");
                ret = 3;
            }
        } else if (str_input->value.operation == BRC) {
            counter_breaks--;
            //  После закрывающей скобки могут быть:
            //  бинарная операция всегда
            //  закрывающая скобка не может быть на первом месте
            if (str_input->next) {
                if (str_input->next->value.operation == BRO ||
                    str_input->next->value.item_type == 2 ||
                    str_input->next->value.item_type == 0) {
                    ret = 4;
                   // printf("Неверная лексема после закрывающей скобки.\n");
                } else if (!str_input->before) {
                    ret = 5;
                  //  printf("Закрывающая скобка на первом месте. \n");
                }
            }
        } else if (str_input->value.item_type == NUM) {
            // После числа может быть
            // Закрывающая скобка, бинарная операциz
            if (str_input->next) {
                if (str_input->next->value.operation == BRO ||
                    str_input->next->value.item_type == 2 ||
                    is_operation_tg(str_input->next) ||
                    str_input->next->value.item_type == 0) {
                   ret = 6;
                 //  printf("Неверная лексема после числа Oper: %d Type: %d\n, Value: %f",
                  //          str_input->value.operation,
                  //          str_input->value.item_type,
                   //         str_input->value.num);
                }
            }
        } else if (is_operation_tg(str_input)) {
            //   операция
            //  После операции всегда должна быть скобки
            //  Тг операция не может быть в конце
            if (str_input->next) {
                if (str_input->next->value.operation != BRO) {
                    ret = 7;
                //    printf("После тригометрической операцией отсутствует скобка.\n");
                }
            } else {
                ret = 8;
             //   printf("Ошибка. Тригонометрическая операция в конце выражения\n");
            }
        } else if (is_operation_binary(str_input)) {
            // Бинарная операция
            // можно BRO, число, унарная операция,тг операция
            // нельзя в конце, нельзя другую опреацию, нельзя в начале
            if ((str_input->next && str_input->before)) {  //  Если не в начале и не в конце
                if (is_operation_binary(str_input->next) || str_input->next->value.operation == BRC) {
                   // printf("Неверная лексема после бинарной операции\n");
                    ret = 9;
                }
            } else {
                ret = 10;
               // printf("Бинарная операция либо в начале, либо в конце\n");
            }
        } else if (str_input->value.item_type == OPER_U) {  // Если операция унарная
            // Унарные операции:
            // Не может быть в конце
            // Перед открывающей скобкой, либо тригонометрической операцией, оибо числом
            // Потенциально может быть перед другим унарником
            if (str_input->next) {
                if (str_input->next->value.operation == BRC ||
                    is_operation_binary(str_input->next)) {
                    ret = 11;
                   // printf("Неверная позиция унарной операции.\n");
                }
            } else {
                ret = 12;
                printf("Унарная операция не может стоять в конце выражения.");
            }
        }
        if (ret != 0) break;
        str_input = str_input->next;
    }
    if (counter_breaks != 0 && ret == 0) {
       // printf("Незакрытые скобки\n");
        ret = 13;
    }
    return ret;
}

int is_operation_binary(item_list* operation) {
/**
 * Проверяет, бинарна ли входящая операци]
 */ 
    int ret = 0;
    if (operation->value.item_type == OPER) {
        int oper = operation->value.operation;
        if (oper >= SUM && oper <= POW)
            ret = 1;
    }
    return ret;
}

int is_operation_tg(item_list* operation) {
    /**
     * Проверяет, является ли элемент списка - тригонометрической операцией
     */ 
    int ret = 0;
    if (operation->value.item_type == OPER) {
        int oper = operation->value.operation;
        if ((oper >= LOG && oper <= ACTG))
            ret = 1;
    }
    return ret;
}


int tg_search(int * i, char * str_input, char * c, element_of_list* a) {
    /**
     * Ищет и определяет тригонометрическую операцию в строке
     */ 
    int ret = 0;
    char temp[50];
    (*i)++;
    int j = 0;
    temp[j] = *c;
    j = j+1;
    *c = str_input[(*i)];
    while (*c != '\0' && (*c >= 'a' && *c < 'z') && j < 4) {
        temp[j] = *c;
        j++; (*i)++;
        *c = str_input[(*i)];
    }
    temp[j] = '\0';
    if (ret_tg_operations(a, temp) == -1)
        ret = -1;
    // printf("%s\n", temp);
    *i = *i - 1;
    return ret;
}

int numbers_search(int * i, char * str_input, char * c, element_of_list* a) {
    /**
     * Ищет число в входящей строке
     */ 
    int flag = 0;
    int ret = 0;
    (*i)++;
    int j = 0;
    char temp[50];
    temp[j] = *c;
    j = j+1;
    *c = str_input[(*i)];
    while (*c != '\0' &&  ((*c <= '9' && *c >= '0') || *c == '.' || *c == ',')) {
        if (*c == 46 || *c == 44) flag = 1;
        if (*c == 46) *c = ',';
        temp[j] = *c;
        j++; (*i)++;
        *c = str_input[(*i)];
            if (*c == 46 && flag == 1) {
                ret = -1;
                break;
            }
    }
    temp[j] = '\0';
    numbers(a, temp);
    *i = (*i) - 1;
    return ret;
}

int ret_tg_operations(element_of_list* a, char *temp) {
    /**
     * Заносит в значение элемента списка тригонометрическую операцию
     */ 
    int ret = 0;
    int flag = 0;
    if      (strcmp("sin", temp) == 0) a->operation = SIN;
    else if (strcmp("cos", temp) == 0) a->operation = COS;
    else if (strcmp("tan", temp) == 0) a->operation = TAN;
    else if (strcmp("tg", temp) == 0) a->operation = TAN;
    else if (strcmp("ln", temp) == 0) a->operation = LN;
    else if (strcmp("log", temp) == 0) a->operation = LOG;
    else if (strcmp("ctg", temp) == 0) a->operation = CTG;
    else if (strcmp("sqrt", temp) == 0) a->operation = SQRT;
    else if (strcmp("mod", temp) == 0) a->operation = MOD;
    else if (strcmp("asin", temp) == 0) a->operation = ASIN;
    else if (strcmp("acos", temp) == 0) a->operation = ACOS;
    else if (strcmp("atan", temp) == 0) a->operation = ATAN;
    else if (strcmp("actg", temp) == 0) a->operation = ACTG;
    else
        flag = 1;
    if (flag == 0) {
        a->item_type = OPER;
    } else {
        a->item_type = ERR;
        ret = -1;
    }
    return ret;
}

void ret_math_operations(element_of_list* a, char c) {
    /*
     * Заносит в значение элемента списка бинарную операцию
     */ 

    if (c == '/') a->operation =  DIV;
    else if (c == '*') a->operation = MUL;
    else if (c == '+') a->operation = SUM;
    else if (c == '-') a->operation = SUB;
    else if (c == '(') a->operation = BRO;
    else if (c == ')') a->operation = BRC;
    else if (c == '^') a->operation = POW;
    a->item_type = OPER;
}

void numbers(element_of_list* a, char * c) {
    double n;
    sscanf(c, "%lf", &n);
    a->item_type = NUM;
    a->num = n;
}

void unaric_transform(item_list **parced_list) {
    /**
     * Находит во входящем списке унарные операции
    */
    item_list *current_element =  *parced_list;
    while (current_element) {
        if (current_element->value.item_type == OPER) {
            if ((current_element->value.operation == SUM || current_element->value.operation == SUB)) {
                if (current_element->before == NULL || (current_element->before->value.item_type == OPER &&
                            (is_operation_binary(current_element->before) ||
                            current_element->before->value.operation == BRO) )) {
                    // Случай когда операция перед унарной
                    if (current_element->value.operation == SUM) current_element->value.operation = PLUS;
                    else if (current_element->value.operation == SUB)
                        current_element->value.operation = MINUS;
                    current_element->value.item_type = OPER_U;
                    current_element->value.priority = 5;
                }
            }
        }
        current_element = current_element->next;
    }
}
