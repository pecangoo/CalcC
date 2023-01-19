
#include "polish_arifmetic.h"

double polish_arifmetic(item_list **polish_string) {
    /**
     * Главная функция польской арифметики. Считает входящий список
     */
    double result = 0;
    item_list * stack = NULL;
    item_list *current_element  = *polish_string;
    while (current_element) {
        if (current_element->value.item_type == NUM) {
            // Заносим в стак
            insert_element_to_list(&stack, current_element->value, END);
        }  else if (current_element->value.item_type == OPER_U) {
            // Добавиь плюс
            item_list *temp = take_element_from_list(&stack, END);
            temp->value.num = temp->value.num * (-1);
            element_of_list el_temp = temp->value;
            remove_element_from_list(&stack, END);
            insert_element_to_list(&stack, el_temp, END);
        } else if (current_element->value.item_type == OPER) {
            /// Задаем диапозон для простых операция
            if ((current_element->value.operation >= SUM && current_element->value.operation <= POW)) {
                double temp = 0;
                item_list * element = NULL;
                temp = take_element_from_list(&stack, END)->value.num;
                remove_element_from_list(&stack, END);
                element = take_element_from_list(&stack, END);
                return_result_oper((element->value.num), temp, current_element->value.operation, element);
            } else {
                item_list * element = NULL;
                element = take_element_from_list(&stack, END);
                return_result_tg_oper(element, current_element->value.operation);
            }
        }
        current_element = current_element->next;
    }
    result = take_element_from_list(&stack, END)->value.num;
    remove_element_from_list(&stack, get_current_pos(&stack, take_element_from_list(&stack, END)));
    return result;
}

void return_result_oper(double a, double b, int oper, item_list *result_element) {
    /**
     * Возвращает результат подсчета бинарных операций
     */ 
    switch (oper) {
    case SUM:
        result_element->value.num = a + b;
        break;
    case SUB:
        result_element->value.num = a - b;
        break;
    case MUL:
        result_element->value.num = a * b;
        break;
    case DIV:
        result_element->value.num = a / b;
        break;
    case MOD:
        result_element->value.num = fmod(a, b);
        break;
     case POW:
        result_element->value.num = pow(a, b);
        break;
    default:
        printf("ERROR");
        exit(1);
        break;
    }
}

void return_result_tg_oper(item_list *result_element, int oper) {
    /**
     * Возвращает результат подсчета тригонометрических  операций
     */ 

    switch (oper) {
        case SIN:
            result_element->value.num = sin(result_element->value.num);
            break;
        case COS:
            result_element->value.num = cos(result_element->value.num);
            break;
        case TAN:
            result_element->value.num = tan(result_element->value.num);
            break;
        case ASIN:
            result_element->value.num = asin(result_element->value.num);
            break;
        case ACOS:
            result_element->value.num = acos(result_element->value.num);
            break;
        case ATAN:
            result_element->value.num = atan(result_element->value.num);
            break;
        case SQRT:
            result_element->value.num = sqrt(result_element->value.num);
            break;
        case LN:
             result_element->value.num = log(result_element->value.num);
            break;
        case LOG:
            result_element->value.num = log10(result_element->value.num);
            break;
        case CTG:
            result_element->value.num = cos(result_element->value.num)/sin(result_element->value.num);
            break;
        case ACTG:
            result_element->value.num = M_PI/2 - atan(result_element->value.num);
            break;
        default:
            break;
    }
}
