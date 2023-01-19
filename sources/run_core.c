/// @mainpage Calc Polish
/// @section intro_sec Назначение:
/// Вычисление строки с инфиксной записью математического выражения
/// с или без "х".


#include "run_core.h"
int run_test(char *str, double *result) {
    int ret =  0;
    item_list * lexems = NULL;
    if (str[0] == '\0') {
       // printf("Пустая строка\n");
        ret = 1;
    } else {
        ret = get_lexems_from_input_test(&lexems, str);
        if (ret != 0) {
           // printf("Error get lexems from input\n");
            ret = 2;
        } else {
            item_list * polish_list = NULL;
            polish_notation(lexems, &polish_list);
            *result = polish_arifmetic(&polish_list);
            clear_list(&polish_list);
        }
    }
    return ret;
}

int run_calc(char *str, double *result) {
    /**
     * запускает ядро калькулятора
     */ 
    double ret = 0;
    item_list * lexems = NULL;
     if (str[0] == '\0') {
       // printf("Пустая строка\n");
        ret = 14;
    } else {
        ret = get_lexems_from_input_test(&lexems, str);
        if (ret != 0) {
          //  printf("Error get lexems from input\n");
        } else {
            item_list * polish_list = NULL;
            polish_notation(lexems, &polish_list);
            *result = polish_arifmetic(&polish_list);
            clear_list(&polish_list);
             // clear_list(&lexems);
        }
//        clear_list(&lexems);
    }
    return ret;
}

int check_value(char *str) {
    /**
     * @brief проверку строки на валидного, запуская модуль проверки
     */ 
    if (str[0] == '\0') return 1;
    int ret = 0;
    item_list * lexems = NULL;
    if (get_lexems_from_input_test(&lexems, str) == 1) {
        ret = 1;
    } else {
        clear_list(&lexems);
    }
    return ret;
}
