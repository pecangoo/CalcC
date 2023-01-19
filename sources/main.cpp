#include "mainwindow.h"

#include <QApplication>

extern "C"{
    #include "list.h"
    #include "in_polish.h"
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
/*
void test1() {
    element_of_list one ;
    one.num = 1;
    element_of_list two ;
    two.num = 2;
    element_of_list three ;
    three.num = 3;
    element_of_list four;
    four.num = 4;

    item_list *list_1_head = NULL;

    insert_element_to_list(&list_1_head, one, END);
    printf("Pointer 1 %p\n", list_1_head);
    insert_element_to_list(&list_1_head, two, END);
    printf("Pointer 2 %p\n", list_1_head);
    insert_element_to_list(&list_1_head, three, END);
    printf("Pointer 3 %p\n", list_1_head);
    insert_element_to_list(&list_1_head, four, END);
    printf("Pointer 4 %p\n", list_1_head);

    test_show_struct_polish(list_1_head);
    clear_list(&list_1_head);
}
*/