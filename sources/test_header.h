
#include <stdlib.h>
#include <stdio.h>

enum item_types {
    NUM,
    OPER,
    OPER_U,
    ERR,
};

enum operations {
    SUM = 0,
    SUB,  // binary minus 1
    MUL, // 2
    DIV, // 3
    MOD, // 4
    POW, // 5
    SQRT, // 6
    BRO, // 7
    BRC, // 8
    MINUS,  // undefined minus // 9
    PLUS, // UNO PLUS 10
    LOG, // 11
    LN, // 12
    SIN, // 13
    COS, // 14
    TAN, // 15
    CTG, // 16
    ACOS, // 17
    ASIN, // 18
    ATAN, // 19
    ACTG // 20
};

enum item_pos_define {
    END = -1,
    START =  0
};

typedef struct lexem {
    enum item_types item_type;
    union {
        double num;
        enum operations operation;
    };
    unsigned priority;
} element_of_list;

typedef struct items {
    unsigned int number;
    element_of_list value;
    struct items *next;
    struct items *before;
} item_list;


item_list * init_element_of_list(element_of_list value);
void insert_element_to_list (item_list **item,  element_of_list element, int item_position);
void remove_element_from_list(item_list **item, int item_position);
void clear_list(item_list **item);
item_list * return_last_element_of_list(item_list  * element);
item_list * take_element_from_list(item_list ** item, int item_position);
int get_current_pos (item_list ** item, item_list *pointer);


int priority_of_operation(int operation);
void checking_node(item_list **stck, item_list **result, element_of_list current_element);
void insert_stack_to_result_reverse(item_list** stack, item_list **result, int priority);
void insert_stack_to_result_reverse_simple(item_list** stack, item_list **result);


void test_show_struct_polish(item_list* head_list);


int check_value (char *str);
int run_calc(char *str, double *result);
int run_test(char *str, double *result);
int get_lexems_from_input_test(item_list ** head_list, char* str_input);
int tg_search(int * i, char * str_input, char * c, element_of_list* a);
int numbers_search(int * i, char * str_input, char * c, element_of_list* a);
int ret_tg_operations(element_of_list* a, char *temp);
void ret_math_operations(element_of_list* a, char c);
void numbers(element_of_list* a, char * c);
int checking_input (item_list *str_input);


int polish_notation(item_list *noda, item_list **result);



double polish_arifmetic(item_list **polish_string);
void return_result_oper(double a, double b, int oper, item_list *result_element);
void return_result_tg_oper(item_list *result_element, int oper);
