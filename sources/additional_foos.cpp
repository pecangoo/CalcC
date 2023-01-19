

#include "additional_foos.h"
#include <iostream>
#include <string.h>
#include "mainwindow.h"
#include <QMessageBox>

std::string insert_x_value(std::string incoming_str, std::string x_str) {
    /**
     * @brief Функция принимает строку из ввода поля кулькулятора
     * @brief Вставляет значение х в строку, если х есть в строке
     *  result
     */
    std::string result("");
    int k = 0;
    for (int i = 0; i < (int)incoming_str.length(); i++) {
        if (incoming_str[i] == 'x') {
            for (int y = 0; y < (int)x_str.length(); y++ ) {
                result.push_back(x_str[y]);
                k++;
            }
        } else {
            result.push_back(incoming_str[i]);
        }
        k++;
    }
    return result;
}

std::string get_string_error(int res) {
    /**
     *@brief  Функция принимает код ошибки и возвращает строку с описанием ошибки
     * @brief err_string
     */

    std::string err_string;
    switch(res) {
    case 2:
        err_string.append("Неверная лексема после открывающей скобки");
        break;
    case 3:
        err_string.append("После открывающей скобки нет лексемы");
        break;
    case 4:
        err_string.append("Неверная лексема после закрывающей скобки");
        break;
    case 5:
        err_string.append("Закрывающая скобка на первом месте");
        break;
    case 6:
        err_string.append("Неверная лексема после числа");
        break;
    case 7:
        err_string.append("После тригометрической операцией отсутствует скобка");
        break;
    case 8:
        err_string.append("Тригонометрическая операция в конце выражения");
        break;
    case 9:
        err_string.append("еверная лексема после бинарной операции");
        break;
    case 10:
        err_string.append("Бинарная операция либо в начале, либо в конце");
        break;
    case 11:
        err_string.append("Неверная позиция унарной операции");
        break;
    case 12:
        err_string.append("Унарная операция не может стоять в конце выражения");
        break;
    case 13:
        err_string.append("Незакрытые скобки");
        break;
    case 14:
        err_string.append("Пустая строка");
        break;
    case 15:
        err_string.append("Число суммы неккоректно");
        break;
    case 16:
        err_string.append("Число сумма не целое");
        break;
    case 17:
        err_string.append("Пустая строка суммы");
        break;
    case 18:
        err_string.append("Число срока депозита неккоректно");
        break;
    case 19:
        err_string.append("Число депозита не целое");
        break;
    case 20:
        err_string.append("Пустая строка срока депозита");
        break;
    case 21:
        err_string.append("Число процентнов некорректно");
        break;
    case 22:
        err_string.append("Пустая строка процентов депозита");
        break;
    case 23:
        err_string.append("Число суммы пополнения неккоректно");
        break;
    case 24:
        err_string.append("Числа суммы пополнения не целое");
        break;
    case 25:
        err_string.append("Пустая строка суммы пополнения");
        break;
    case 26:
        err_string.append("Число суммы снятия неккоректно");
        break;
    case 27:
        err_string.append("Числа суммы снятия не целое");
        break;
    case 28:
        err_string.append("Пустая строка суммы снятия");
        break;
    }
    return err_string;
}

int check_valid_number_str(std::string incoming_str) {
    /**
     * @brief Функция принимает строку string и проверяет ее на содержание валидного числа
     * @brief Возвращает 0 если число ок, 1 если число не ок
     * @brief ret
     */
    int ret = 0;
    int flag = 0;
    char temp[100] = {0};
    strcpy(temp, incoming_str.c_str());
    char *c = NULL;
    c = &temp[0];
    if (*c == '-'){
        c++;
        ret = -1;
    }// Если минус в начале, пропускаем его.
    while (*c != '\0' &&  ((*c <= '9' && *c >= '0') || *c == '.' || *c == ',')) {
        if (*c == 46 || *c == 44) flag++;
        if (*c == 46) *c = ',';
            if ( (*c == 44) && flag == 2 ) {
                ret = 1;
                break;
            }
        c++;
    }
    if (*c != '\0') ret = 1;
     
    return ret;
}

int check_integer(std::string incoming_str) {
     /**
     *  @brief Функция проверяет строку содержание целого числа
     * @brief ret
     */
    int ret = 0;
    char temp[100] = {0};
    strcpy(temp, incoming_str.c_str());
    double number = 0;
    number  = ::atof(temp);
    if ((int) number != number) ret = 1;
    return ret;
}

int recieve_number_days(int n, int m) {
    /**
     *@brief Функция возвращает количество дней в месяце
     * @brief res
     */
    int res = 0;
    if (n==1 || n==3 || n==5 || n==7 || n==8 || n==10 || n==12) res = 31;
    else if (n==2 && (m%4==0 && (m%400==0 || m%100!=0))) res = 29;
    else if (n==4 || n==6 || n==9 || n==11) res = 30;
    else res = 28;
    return res;
}

int MainWindow::checking_credit_values( std::string str_credit_sum,  std::string str_credit_term, std::string str_percent_value) {
    /**
     * @brief Функция принимает строки с полей ввода калькулятора, проверяет валидность введенных данных, и при необходимости показывает тип ошибки
     * @brief ret
     */
    int ret = 0;

    if (::strlen(str_credit_sum.c_str()) != 0) {
        if (check_valid_number_str(str_credit_sum) != 0) {
            QMessageBox::critical(this, "Error", "Неверное значение суммы кредита");
            return 1;
        } else {
            if ( check_integer(str_credit_sum) == 1) {
               QMessageBox::critical(this, "Error", "Дробное значение суммы кредита");
               return 1;
            }
        }
    } else {
        QMessageBox::critical(this, "Error", "Пустая строка с суммой кредита");
        return 1;
    }

    if (::strlen(str_credit_term.c_str()) != 0) {
        if (check_valid_number_str(str_credit_term) != 0) {
                QMessageBox::critical(this, "Error", "Неверное значение срока кредита");
                return 1;
            } else {
                 if ( check_integer(str_credit_term) == 1) {
                    QMessageBox::critical(this, "Error", "Дробное значение срока кредита");
                    return 1;
                 }
             }
    } else {
        QMessageBox::critical(this, "Error", "Пустая строка со сроком кредита");
        return 1;
    }

    if (::strlen(str_percent_value.c_str()) != 0) {
        if (check_valid_number_str(str_percent_value) != 0) {
                QMessageBox::critical(this, "Error", "Неверное значение процентов кредита");
                return 1;
           }
    } else {
        QMessageBox::critical(this, "Error", "Пустая строка с процентом кредита");
        return 1;
    }
  return ret;
}

int MainWindow::checking_depos_values(std::string str_sum,  std::string str_temp, std::string str_percent, std::string str_add, std::string str_get, QString str1, QString str2) {
     /**
     * @brief Функция принимает значения полей с депозитного калькулятора.
     * @brief Проверяет валидность введенных данных
     * @brief Показывает ошибку
     * @brief Возвращает код ошибки
     * @brief ret
     */

    int ret = 0;
    if (::strlen(str_sum.c_str()) != 0) { // Пустая строка?
        if (check_valid_number_str(str_sum) != 0) ret = 15; // Валидно ли число?
        else if ( check_integer(str_sum) == 1)  ret = 16;  // Целое число?
    } else { // Значит строка пустая
        ret = 17;
    }


    if (::strlen(str_temp.c_str()) != 0) { // Пустая строка?
        if (check_valid_number_str(str_temp) != 0) ret = 18; // Валидно ли число?
        else if ( check_integer(str_temp) == 1)  ret = 19;  // Целое число?
    } else { // Значит строка пустая
        ret = 20;
    }


    std::cout << "222: " << str_percent << std::endl;
    if (::strlen(str_percent.c_str()) != 0) { // Пустая строка?
        if (check_valid_number_str(str_percent) != 0) ret = 21; // Валидно ли число?
    } else { // Значит строка пустая
        ret = 22;
    }


    if (str1.toStdString() != "не предусмотрено")  {
        if (::strlen(str_add.c_str()) != 0) { // Пустая строка?
            if (check_valid_number_str(str_add) != 0) ret = 23; // Валидно ли число?
            else if ( check_integer(str_add) == 1)  ret = 24;  // Целое число?
        } else { // Значит строка пустая
            ret = 25;
        }
    }
    if (str2.toStdString() != "не предусмотрено")  {
        if (::strlen(str_get.c_str()) != 0) { // Пустая строка?
            if (check_valid_number_str(str_get) != 0) ret = 26; // Валидно ли число?
            else if ( check_integer(str_get) == 1)  ret = 27;  // Целое число?
        } else { // Значит строка пустая
            ret = 28;
        }
    }
    std::string text_error;
    text_error = get_string_error(ret);
    if (ret != 0)
        QMessageBox::critical(this, "Error", QString::fromStdString(text_error));

  return ret;
}
