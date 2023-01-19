
#ifndef ADDITIONAL_FOOS_H
#define ADDITIONAL_FOOS_H
#include <string>
//#include "mainwindow.h"

std::string insert_x_value(std::string incoming_str, std::string x_str);
int check_valid_number_str(std::string incoming_str);
int check_integer(std::string incoming_str);
int recieve_number_days(int n, int m);
std::string get_string_error(int res);
#endif // ADDITIONAL_FOOS_H
