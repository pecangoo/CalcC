#ifndef LIST_H
#define LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum item_types {
     /**
     * @brief Хранит в себе коды типо операторов
     */
    NUM,
    OPER,
    OPER_U,
    ERR,
};

enum operations {
     /**
     * @brief Хранит в себе коды операторов
     */
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
    /**
     * @brief структура хранит в себе тип и значение операции 
     */
    enum item_types item_type;
    union {
        double num;
        enum operations operation;
    };
    unsigned priority;
} element_of_list;

typedef struct items {
     /**
     * @brief элемент списка структуры лексем
     */
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


#endif
