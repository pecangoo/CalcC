

#include "list.h"

/// @file Данный файл является библиотекой для работы со списками. Аналог пайтоновской подхода
void corrector_numbering_lists(item_list ** item) {
    //  Корректирует нумерацию списка, когда элементы добавлены/удалены
    int number = 0;
    while ((*item)-> next) {
        (*item)->number = number;
        (*item) = (*item)->next;
        number++;
    }
    (*item)->number = number;
}

void insert_element_to_list(item_list **item,  element_of_list element, int item_position) {
    /**
        * Добавляет элемент в список в указанное место
    */
    if (item_position >= 0)
        item_position++;  // Так как начинается с нуля. А ноль это единичка.
    int current_item_position = 0;
    item_list * ret = NULL;
    if (*item) {
        ret = *item;
        current_item_position++;
    }

    while (*item) {
        if (current_item_position == item_position && item_position != -1)
            break;
        if ((*item)->next)
            *item = (*item)->next;
        else
            break;
        current_item_position++;
    }
    item_list *new = NULL;
    new =  init_element_of_list(element);
    new->number = current_item_position;
    if (new && *item) {  // Если элемент не первый
        if (item_position == -1 || !(*item)->next) {  // Если конечная позиция
            (*item)->next = new;
            new->before = (*item);
            *item = ret;
        } else if ((*item)->before == NULL) {  // если позиция первая
            (*item)->before = new;
            new->next = (*item);
            *item = new;
            ret = new;
        } else {  // Во всех остальный случаях
            (*item)->before->next = new;
            new->before = (*item)->before;
            new->next = (*item);
            (*item) = ret;
        }
    } else {  // Если первый элемент, то не важно какая позиция
        *item = new;
        ret = *item;
    }
    corrector_numbering_lists(&ret);  // Корректирует нумерацию списка
}

void remove_element_from_list(item_list ** item, int item_position) {
    /**
     * Удаляет элемент из списка по порядковому номеру 
    */
    if (item_position >= 0)
            item_position++;  // Так как начинается с нуля. А ноль это единичка.
    int current_item_position = 0;
    item_list * ret = NULL;
    if (*item) {
        ret = *item;
        current_item_position++;
    }

    while (*item) {
        if (current_item_position == item_position && item_position != -1)
            break;
        if ((*item)->next)
            *item = (*item)->next;
        else
            break;
        current_item_position++;
    }

    if (*item) {  // Если элемент существует
        if (!((*item)->before) && !((*item)->next)) {  // Еcли элемент единственный
            ret = NULL;
        } else if (item_position == -1 || !(*item)->next) {  //  Если конечная позиция
            (*item)->before->next = NULL;
        } else if ((*item)->before == NULL) {  // если позиция первая
            (*item)->next->before = NULL;
            ret = (*item)->next;
        } else {  // Во всех остальный случаях
            (*item)->before->next = (*item)->next;
            (*item)->next->before = (*item)->before;
        }
            free(*item);
            (*item) = ret;
            if (*item)
                corrector_numbering_lists(&ret);  // Корректирует нумерацию списка
    } else {  // Если элемент не существует, тогда ошибка удаления
        // Список пустой, ошибка
    }
}

void clear_list(item_list **item) {
    /**
     * Чистит список
     */
    item_list* p = NULL;
    p = (*item);
    while ((*item)->next) {
        p = (*item)->next;
        free(*item);
        (*item) = p;
    }
    free(*item);
}

item_list * take_element_from_list(item_list ** item, int item_position) {
    /** Достает ссылку на элемент указанного порядкого номера
     *  Дает NULL если элемента по указанного номеру не существует
     *  Должен возвращать NULL если указанная позиция превосходит длину списка
     *  Возвращает NULL c ошибкой, если список пустой. 
     *  Ссылку на заголовок не должен менять
     */

    item_list * current_element = (*item);  // Рабочий указать
    if (item_position >= 0)
        item_position++;  // Так как начинается с нуля. А ноль это единичка.

    int current_item_position = 0;
    if (current_element) {
        current_item_position++;
    }

    while (current_element) {
        if (current_item_position == item_position && item_position != -1)
            break;
        if ((current_element)->next)
            current_element = (current_element)->next;
        else
            break;
        current_item_position++;
    }
    if (current_item_position < item_position) {
        return NULL;
    }
    if (!current_element) {  // Если элемент не существует
        return NULL;
    }
    return current_element;
}

item_list * init_element_of_list(element_of_list value) {
    /**
    * Создает запись в стаке, и заполняет его входящим элементом
    * Возвращает указатель на созданный элемент
    */
    item_list *new_element = malloc(sizeof(item_list));
    //  printf("Poiner malloc: %p\n", new_element);
    if (new_element) {
        new_element->value = value;
        new_element->next = NULL;
        new_element->before = NULL;
    }
    return new_element;
}

item_list * return_last_element_of_list(item_list  * element) {
    /**
     * возвращает последний элемент из списка
     */
    item_list *p  = element;
    if (p && p ->next) {
       // printf("191; element %p\n", p);
        while (p->next) {
            // printf("192; element %p  next: %p\n ", p, p->next);
            p = p->next;
        }
    }
    return p;
}

int get_current_pos(item_list ** item, item_list *pointer) {
    /**
     * Возвращает текущую позицию из списка
     */ 
    item_list * item_current_pos = *item;
    int current_pos = 0;
    while (1) {
        if (item_current_pos == pointer)
            break;
        current_pos++;
        item_current_pos = item_current_pos->next;
        if (!item_current_pos)
            return -1;
    }
    return current_pos;
}
