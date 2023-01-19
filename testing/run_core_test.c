#include "run_core_test.h"




int run_test(char *str, double *result) {
    int ret =  0;
    item_list * lexems = NULL;
    if (str[0] == '\0') {
        // printf("Пустая строка\n");
      ret = 1;
    } else {
        ret = get_lexems_from_input_test(&lexems, str);
        if (ret != 0) {
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
