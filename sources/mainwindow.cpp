#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include "dialog.h"
#include <QSlider>
#include "additional_foos.h"


extern "C"{
    #include "list.h"
    #include "in_polish.h"
    #include "parcer.h"
    #include "run_core.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_dep_add_pay->setDisabled(true);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->radioButton_pay->setChecked(true);
    on_comboBox_period_pays_2_currentIndexChanged(1);
    on_comboBox_period_pays_3_currentIndexChanged(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_but_eq_clicked() {
    /**
     * Считает выражение, или выдает ошибку ввода.
     */
    // Берем строку из текста
    // Переводим ее в чар
    // Тут нужна функция для проверки ДО Парсера (или После?)
    // Тест. Выводим структуру
    QString text = ui->line->text();
    std::string text_str = text.toStdString();

   // text_str = insert_x_value(text_str);

    if (check_valid_number_str(ui->lineEdit_4->text().toStdString()) == 1){
          QMessageBox::critical(this, "Ошибка ввода",  "Неверно указан х");
          return;
    }


    text_str = insert_x_value(text_str, ui->lineEdit_4->text().toStdString());
    if (text_str.length() > 255) {
        QMessageBox::critical(this, "Ошибка ввода",  "Выражение слишком длинное. Максимальная длина 255 символов");
        return;
    }
    std::cout << "Result: " << text_str << std::endl;


    char char_str[1024] = {0};
    strcpy(char_str, text_str.c_str());
    //std::cout << char_str << std::endl;

    double result_double = 0;
    std::cout << "RESULT:" << std::endl;
    int res  = 0;

    try {
          res = run_calc(char_str, &result_double);
    } catch (...) {
        QMessageBox::critical(this, "Ошибка ввода",  "Критическая ошибка в ядре подсчета");
        return;
    }

    if (res != 0) {
        //ui->line->setText(QString::fromUtf8("Ошибочный ввод"));
        std::string string_error;
        string_error = get_string_error(res);
        QMessageBox::critical(this, "Ошибка ввода",  QString::fromStdString(string_error));
    } else {
        std::string result_string = std::to_string(result_double);
        QString str_result = QString::fromUtf8(result_string);
        ui->line->setText(str_result);
    }
}


void MainWindow::on_but_graf_clicked() {

    Dialog window;
    std::string string_from_line = ui->line->text().toStdString();
    window.foo_input(string_from_line); // ("Строка передаваемая\n");
    window.setModal(true);
    window.exec();

}

void MainWindow::SetTextLine(std::string text_l) {
    /**
     * @brief Выводит текст кнопки в поле ввода
     */
    QString text = ui->line->text();
    std::string text_str = text.toStdString();
    text_str.append(text_l);
    std::cout << text_str << std::endl;
    text = QString::fromStdString(text_str);
    ui->line->setText(text);
}

void MainWindow::on_but_check_clicked() {
    QString text = ui->line->text();//  >text_graf.text() text();
    std::string text_str = text.toStdString();
    text_str = insert_x_value(text_str, ui->lineEdit_4->text().toStdString());
    std::cout << "Result: " << text_str << std::endl;
    char char_str[1024] = {0};
    strcpy(char_str, text_str.c_str());

        if (check_value(char_str) == 1) {
            std::cout << "Error" << std::endl;
            QMessageBox::critical(this, "Проверка выражения",  "Ошибка ввода");
        } else {
            QMessageBox::information(this, "Проверка выражения",  "Выражение корректно");
        }

}



void MainWindow::on_but_bro_clicked() {
     SetTextLine("(");
}
void MainWindow::on_but_brc_clicked() {
     SetTextLine(")");
}
void MainWindow::on_but_pl_min_clicked() {
    exit(0);
}
void MainWindow::on_but_cos_clicked() {
     SetTextLine("cos(");
}
void MainWindow::on_but_sin_clicked() {
     SetTextLine("sin(");
}
void MainWindow::on_but_tan_clicked() {
     SetTextLine("tan(");
}
void MainWindow::on_but_acos_clicked() {
     SetTextLine("acos(");
}
void MainWindow::on_but_asin_clicked() {
     SetTextLine("asin(");
}
void MainWindow::on_but_atan_clicked() {
     SetTextLine("atan(");
}

void MainWindow::on_but_log_clicked() {
     SetTextLine("log(");
}
void MainWindow::on_but_ln_clicked() {
     SetTextLine("ln(");
}
void MainWindow::on_but_sqrt_clicked() {
     SetTextLine("sqrt(");
}


void MainWindow::on_pushButton_11_clicked() {
     SetTextLine(",");
}

void MainWindow::on_but_x_clicked() {
     SetTextLine("x");
}

void MainWindow::on_but_mod_clicked() {
     SetTextLine("mod");
}
void MainWindow::on_but_pow_clicked() {
     SetTextLine("^");
}

void MainWindow::on_but_1_clicked() {
    SetTextLine("1");
}

void MainWindow::on_but_2_clicked() {
    SetTextLine("2");
}

void MainWindow::on_but_3_clicked() {
     SetTextLine("3");
}

void MainWindow::on_but_4_clicked() {
     SetTextLine("4");
}
void MainWindow::on_but_5_clicked() {
     SetTextLine("5");
}
void MainWindow::on_but_6_clicked() {
     SetTextLine("6");
}
void MainWindow::on_but_7_clicked() {
     SetTextLine("7");
}
void MainWindow::on_but_8_clicked() {
     SetTextLine("8");
}
void MainWindow::on_but_9_clicked() {
     SetTextLine("9");
}
void MainWindow::on_but_0_clicked() {
     SetTextLine("0");
}
void MainWindow::on_but_sum_clicked() {
     SetTextLine("+");
}
void MainWindow::on_but_sub_clicked() {
     SetTextLine("-");
}
void MainWindow::on_but_mul_clicked() {
     SetTextLine("*");
}
void MainWindow::on_but_div_clicked() {
     SetTextLine("/");
}

void MainWindow::on_but_check_2_clicked()
{
    // Кнопка закрытия программы
    exit(0);
}



void MainWindow::on_but_C_clicked()
{
    QString text = ui->line->text();
    std::string text_str = text.toStdString();
    text_str.pop_back();
    std::cout << text_str << std::endl;
    text = QString::fromStdString(text_str);
    ui->line->setText(text);
}


void MainWindow::on_but_ctg_clicked()
{
    SetTextLine("ctg(");
}


void MainWindow::on_but_actg_clicked()
{
    SetTextLine("actg(");
}


void MainWindow::on_but_pi_clicked()
{
     SetTextLine("3.14");
}



void MainWindow::on_but_calc_credit_clicked()
{

    /**
     * Функция для кредитного калькулятора. Делает все, что требуется.
    */

    // Получаем знаачения строк
    std::string str_credit_sum = ui->sumcredit_line->text().toStdString();
    std::string str_credit_term = ui->creditterm_line->text().toStdString();
    std::string str_percent_value =  ui->percent_label->text().toStdString();

    // Чекаем каждую входную строку на логику
    // Прерываем выполнение функции, если ошибка
    if (checking_credit_values(str_credit_sum, str_credit_term, str_percent_value) == 1) return;
    double credit_sum = ::atof(str_credit_sum.c_str());
    double credit_term = ::atof(str_credit_term.c_str());
    double percent_value = ::atof(str_percent_value.c_str());
    double body_credit = credit_sum;

    //double day_boy_summ = 0;
    double total_summ_credit = 0;
    // 0 - аутинентный
    // 1 - диффиренцированный
    int type_calculation = ui->typecreit_comboBox->currentIndex();

    ui->textBrowser->clear();
    if (type_calculation == 1) { // Дифф
        std::string text_result;
        char temp[100] = {};
        sprintf(temp, "  №   Остаток   Процент Погашено  Платеж \n");
        text_result.append(std::string(temp));
        int i = 0;

        // Считает ежедневные выплаты, пока дни не закончатся.
        // Определяем текущую дату.
        // Определяем дату окончания кредитного срока

        QDate current_date = QDate::currentDate();
        while (1) {

            i++;
            double percent = 0,  repaid = 0;
            char temp[100] = {};
            //int days = current_date.daysInYear();
            double x = credit_sum / credit_term + body_credit*percent_value*30/365/100;
            body_credit = body_credit -  credit_sum/credit_term;
            percent = body_credit*(percent_value/100)*current_date.daysInMonth()/365 ;
            repaid = credit_sum - body_credit;
            total_summ_credit += x;
            if (abs(body_credit) < 1e-6) break;

            sprintf(temp, "%3d: %8.1lf %8.1lf %8.1lf %8.1lf\n", i, body_credit, percent, repaid, x);
            text_result.append(std::string(temp));
            current_date = current_date.addMonths(qint64(1));
        }

        ui->textBrowser->append(QString::fromStdString(text_result));

    } else if (type_calculation == 0) {
       std::string text_result;
       char temp[100] = {};
       sprintf(temp, "  №    Платеж\n");
       text_result.append(std::string(temp));

        // Остаток(Body_credit) Процен(Percent)  Погашено(credit_sum - body) Платеж(x)
        //double left_sum = credit_sum;
        double i = percent_value /100/12; // Процентная ставка в месяц
        double K = (i* pow((1+i), credit_term)) / (pow((1+i), credit_term) -1) ;
        double x = K * credit_sum;
        total_summ_credit = x*credit_term;
        int ki = 0;
        for (int xi = 0; xi < credit_term; xi++) {
            ki++;
            sprintf(temp, "%3d: %8.1lf\n", ki, x);
            text_result.append(std::string(temp));
        }
        ui->textBrowser->append(QString::fromStdString(text_result));
        std::cout << total_summ_credit << std::endl;
    }

    //std::cout << total_summ_credit << std::endl;
    QString qstr;
    ui->totalpay_label->setText(qstr.setNum(total_summ_credit));
    ui->overpay_label->setText(qstr.setNum(total_summ_credit - credit_sum));
}


/////////////_______DEPOSIT

void MainWindow::on_but_dep_clicked()
{
   /**
    * После срабатывание по кнопке, считается депозитный калькулятор
    */

    // Добавить переменную с "не предусмотрено": first, second, both или две переменные
    if (checking_depos_values(ui->line_dep_summ_start->text().toStdString(),
                          ui->line_dep_term->text().toStdString(),
                          ui->line_dep_percent->text().toStdString(),
                          ui->line_dep_add_pay->text().toStdString(),
                          ui->line_dep_add_pay_2->text().toStdString(),
                              ui->comboBox_period_pays_2->currentText(),
                              ui->comboBox_period_pays_3->currentText()) != 0)
        return;


    int year = 0, mounth = 0, day = 0;
    QDate current_date = ui->dateEdit->date();
    current_date.getDate(&year, &mounth, &day);
    QDate stopdate_pay_cap = current_date,
            stopdate_add = current_date,
            stopdate_get = current_date;
    QDate final_date;



    // Получаем конечную дату депозита
    int type_date = ui->comboBox_2->currentIndex();  // День/Год/Месяц
    int int_term = int(ui->line_dep_term->text().toFloat()); // Срок


    double summ = ui->line_dep_summ_start->text().toDouble(); // Сумма старта
    double percent = ui->line_dep_percent->text().toDouble()/100; // Процент

    double summ_add = ui->line_dep_add_pay->text().toDouble(); // Сумма регулярного пополнения
    double summ_get = ui->line_dep_add_pay_2->text().toDouble(); // Сумма регулярного снятия


    double current_summ_total = summ; //  Текущая общая сумма
    double plus_summ_per_day = 0; // Сколько бабла приваливает в день
    double current_summ_percent = 0; // Сумма накопленных процентов
    double total_summ_percent = 0;
    double period_summ_percent = 0;
    double nalog = 0;
     // Проверка int_term -  целое, положительное, больше нуля


    if (type_date == 0) final_date = current_date.addDays(qint64(int_term));
    else if (type_date == 1) final_date = current_date.addMonths(qint64(int_term));
    else if (type_date == 2) final_date = current_date.addYears(qint64(int_term));


    ui->comboBox_period_pays->currentText();

    // Функции для получения следующей даты проверок и возможных пополнений
    // Если выплаты, то конец срока.

    next_stop_date(&stopdate_add,  ui->comboBox_period_pays_2->currentText()); // Это про регулярные пополнения
    next_stop_date(&stopdate_get,  ui->comboBox_period_pays_3->currentText()); // Это про регулярные снятия

    if (next_stop_date(&stopdate_pay_cap,  ui->comboBox_period_pays->currentText()) == 9){ // Это про периодичности выплат
        stopdate_pay_cap = final_date;
        std::cout << "359" << std::endl;
    }



    //if (next_stop_date(&stopdate_pay_cap,  ui->comboBox_period_pays->currentText()) == -1)
    //    stopdate_pay_cap = final_date;

     // Задаем первичную ежедневную сумму пополнения
    int days_in_year = current_date.daysInYear();
    plus_summ_per_day = summ * ((1+percent/days_in_year)- 1);


     // № Дата рассчета Начисленно процентов, Уплачено налога/Добавлено ко вкладу, Пополнение вклада,
        // Сумма на конец

     std::string text_result;
     char temp[300] = {};
     char str_or_or[50] = {};
     if (ui->radioButton_add->isChecked() == 1) strcpy(str_or_or, "Добавлено");
     else strcpy(str_or_or, "Выплачено");

     ui->textBrowser_2->clear();
     sprintf(temp, " №  Дата  Начислено Налог %s Пополнение Итого\n", str_or_or) ;
     text_result.append(std::string(temp));

     int counter_messages = 0;


    QDate one_year_date = current_date.addYears(1);
    double year_earn = 0;
    double total_nalog = 0;
int nalog_flag=0;
    while (1) {
        nalog_flag = 1;
        current_date = current_date.addDays(qint64(1));
        /// Надо добавлять выплаты только тогда, когда день выплат!
        //current_summ_total += plus_summ_per_day;
        current_summ_percent += plus_summ_per_day;
        period_summ_percent += plus_summ_per_day;
        year_earn += plus_summ_per_day;
        total_summ_percent += plus_summ_per_day;

        if (stopdate_pay_cap == current_date) {
            // Если капитализация, пересчитываем процент.
            // Если выплата, выплачиаем.

            if (ui->radioButton_add->isChecked()) {
               // Начисляем проценты
               current_summ_total += period_summ_percent;

               counter_messages++;
               //days_in_year = current_date.daysInYear();
               plus_summ_per_day = current_summ_total * ((1+percent/days_in_year)- 1);


                // Инфо для вывода по точке регулярной капитализации
                // current_day, counter_
                current_date.getDate(&year, &mounth, &day);
                //std::cout<< year << " : "<< day << " : " <<mounth << " : ";

                sprintf(temp, "%3.d %d:%02d:%02d %5.0f %5.0f %5.0f %d %8.0f\n", counter_messages, year, day, mounth,
                        ceil(period_summ_percent), nalog, ceil(period_summ_percent), 0, ceil(current_summ_total));
                text_result.append(std::string(temp));
                period_summ_percent = 0;

            } else {

             // Инфо для вывода по точке регулярной выплаты
                current_date.getDate(&year, &mounth, &day);
                sprintf(temp, "%3.d %d:%02d:%02d %5.0f %5.0f %5.0f %d %8.0f\n", counter_messages, year, day, mounth,
                        ceil(current_summ_percent), nalog, ceil(current_summ_percent), 0, ceil(current_summ_total));
                text_result.append(std::string(temp));

                current_summ_percent = 0;
                period_summ_percent = 0;
             }

            next_stop_date(&stopdate_pay_cap,  ui->comboBox_period_pays->currentText());

            }

        // Регулярные пополния
        if (ui->comboBox_period_pays_2->currentText() != "не предусмотрено") {
            if (stopdate_add == current_date) {
                days_in_year = current_date.daysInYear();
                    current_summ_total += summ_add;
                    plus_summ_per_day = current_summ_total * ((1+percent/days_in_year)- 1);
                    next_stop_date(&stopdate_add,  ui->comboBox_period_pays_2->currentText());
                    // Вывод регулярных пополнений
                    current_date.getDate(&year, &mounth, &day);
                    //std::cout<< year << " : "<< day << " : " <<mounth << " : ";
                    sprintf(temp, "%3.d %d:%02d:%02d %d %5.0f %5.0f %8.0f %8.0f\n ", counter_messages, year, day, mounth,
                    0, nalog, ceil(current_summ_percent), ceil(summ_add), ceil(current_summ_total));
                    text_result.append(std::string(temp));
                }
        }
             // Регулярные снятия
        if (ui->comboBox_period_pays_3->currentText() != "не предусмотрено") {
            if (stopdate_get == current_date) {
                days_in_year = current_date.daysInYear();
                    current_summ_total -= summ_get;
                    plus_summ_per_day = current_summ_total * ((1+percent/days_in_year)- 1);
                    next_stop_date(&stopdate_get,  ui->comboBox_period_pays_3->currentText());

                    // вывод регулярный снятий
                    current_date.getDate(&year, &mounth, &day);
                    sprintf(temp, "%3.d %d:%02d:%02d %5.0f %5.0f %5.0f %d %8.0f\n ", counter_messages, year, day, mounth,
                    ceil(current_summ_percent), nalog, summ_get, 0, ceil(current_summ_total));
                    text_result.append(std::string(temp));
                }
        }

        if (current_date == one_year_date && ui->checkBox->isChecked()) {
            // Прошел год, пора платить проценты
            if (year_earn > 42500) {
                // тогда платим проценты
                double year_nalog = (year_earn - 42500) * 0.13;
                sprintf(temp, "%d: Годовой налог: %8.0f\n", current_date.year(), year_nalog);
                text_result.append(std::string(temp));
                total_nalog += year_nalog;
                nalog_flag = 0;
                one_year_date = one_year_date.addYears(qint64(1));
                year_earn = 0;
            } else {

            }
        }

        if (current_date == final_date) break;

    }

    if (nalog_flag == 1 && year_earn > 80000 && ui->checkBox->isChecked()) {
        total_nalog +=  (year_earn - 80000) * 0.13;
    }
    //sprintf(temp, "\n\n Итоговая сумма: %5.0f  Начисленые проценты: %5.0f\n ", current_summ_total, current_summ_percent);
    sprintf(temp, "\n\nИтоговая сумма: %5.0f\nНачислено процентов: %5.0f\nДоход с учетом налогов: %5.0f\nНалог: %5.0f\n", current_summ_total,
            total_summ_percent, total_summ_percent - total_nalog, total_nalog);
    text_result.append(std::string(temp));
    ui->textBrowser_2->setText(QString::fromStdString(text_result));
    std::cout<< "Summ: " << current_summ_total << std::endl;
    std::cout<< "Summ total_percent: " << current_summ_percent << std::endl;
}

//// Что происходит если введено не предусмотрено?
///

int MainWindow::next_stop_date(QDate *c_date, QString q_type) {
    /***
     * эта функция добавляет к  объекту дате QDate колиество дней,
     *  соответствующих настроке депозитного калькулятора
     */

   //Добавляем срок к стоп дате.
    // Возврашает -1, если триггер "в конце срока"
    int ret = 0;

    std::string str_type = q_type.toStdString();
    int type = -1;
    if (str_type == "ежедневно") type = 1;
    else if (str_type == "еженедельно") type = 2;
    else if (str_type == "раз в месяц") type = 3;
    else if (str_type == "раз в 2 месяца") type = 4;
    else if (str_type == "раз в квартал") type = 5;
    else if (str_type == "раз в 4 месяца") type = 6;
    else if (str_type == "раз в полгода") type = 7;
    else if (str_type == "раз в год") type = 8;
    else if (str_type == "в конце срока") type = 9;

    switch (type) {
    case 1:
        //std::cout << "ежедневно" << std::endl;
        *c_date = c_date->addDays(qint64(1)); //
        break;
    case 2:
      //  std::cout << "еженедельно" << std::endl;
         *c_date = c_date->addDays(qint64(7));
        break;
    case 3:
    //    std::cout << "раз в месяц" << std::endl;
           *c_date  = c_date->addMonths(qint64(1));
        break;
    case 4:
     //   std::cout << "раз в 2 месяца" << std::endl;
        *c_date  = c_date->addMonths(qint64(2));
        break;
    case 5:
   //     std::cout << "раз в квартал" << std::endl;
        *c_date  = c_date->addMonths(qint64(3));
        break;
    case 6:
    //    std::cout << "раз в 4 месяца" << std::endl;
       *c_date  = c_date->addMonths(qint64(4));
        break;
    case 7:
   //     std::cout << "раз в полгода" << std::endl;
          *c_date  = c_date->addMonths(qint64(6));
        break;
    case 8:
     //   std::cout << "раз в год" << std::endl;
          *c_date  = c_date->addMonths(qint64(12));
        break;
    case 9:
        std::cout << "в конце срока" << std::endl;
        ret = 9;
        break;
    case -1:
        std::cout << "Ошибка"   << str_type << std::endl;
        ret = -1;
        break;
    }
    return ret;
}

void MainWindow::on_radioButton_add_clicked()
{
    std::cout << ui->radioButton_add->isChecked();
    ui->comboBox_period_pays->clear();
    QStringList text =  (QStringList() << "ежедневно" << "еженедельно" << "раз в месяц"
                         << "раз в 2 месяца" << "раз в квартал" << "раз в 4 месяца"
                         << "раз в полгода" << "раз в год");
    ui->comboBox_period_pays->addItems(text);
    QString label_text = "Периодичность капитализации:";
    ui->label_17->setText(label_text);
}

void MainWindow::on_radioButton_pay_clicked()
{
    std::cout << ui->radioButton_pay->isChecked();
    ui->comboBox_period_pays->clear();
    QStringList text =  (QStringList() << "в конце срока" << "ежедневно" << "еженедельно" << "раз в месяц"
                         << "раз в 2 месяца" << "раз в квартал" << "раз в 4 месяца"
                         << "раз в полгода" << "раз в год");
    ui->comboBox_period_pays->addItems(text);
    QString label_text = "Периодичность выплат:";
    ui->label_17->setText(label_text);

}

void MainWindow::on_comboBox_period_pays_2_currentIndexChanged(int index)
{
    // Эта штука про дополнительные пополнения
    if (ui->comboBox_period_pays_2->currentIndex() != 0) {
        index++;
        ui->line_dep_add_pay->setDisabled(false);
    } else {
         ui->line_dep_add_pay->setDisabled(true);
    }
}


void MainWindow::on_comboBox_period_pays_3_currentIndexChanged(int index)
{
    if (ui->comboBox_period_pays_3->currentIndex() != 0) {
        index++;
        ui->line_dep_add_pay_2->setDisabled(false);
    } else {
         ui->line_dep_add_pay_2->setDisabled(true);
    }
}


