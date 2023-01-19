#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include "mainwindow.h"
#include <math.h>
#include "additional_foos.h"
#include <QMessageBox>

extern "C"{
    #include "run_core.h"
}


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

   // std::cout<<"Вывод"<<std::endl;
    ui->setupUi(this);
    //QString qstring_input;
    //qstring_input.fromStdU16String(this->text_string);
    //std::cout << "15: " << text_string << std::endl;
    //ui->textBrowser->setText(this->text_string);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::foo_input(std::string value) {
    /**
     * @brief str
     * Принимает аргумент с главного окна
     * Настраиев LineEdit в окне графика
     */
    QString str;
    text_string = value;
    ui->line_text_graf->setText(QString::fromUtf8(value));
}


void Dialog::build_graf(unsigned int zoom) {
    /**
     * @param zoom
     * Строит график в виджете графика
     * На вход приходит А 
    */
    ui->label_zoom->setText(QString::fromUtf8(std::to_string(zoom) + "x"));
    QString text = ui->line_text_graf->text();//  >text_graf.text() text();

    std::string text_str = text.toStdString();
    char char_str[1024] = {0};
    strcpy(char_str, text_str.c_str());
    //text_str = insert_x_value(text_str);


    if (check_value(char_str) == 1) {
        QMessageBox::critical(this, "Проверка выражения",  "Ошибка ввода");
    } else {
        // Временное решение
        double ox = 1 * zoom;
        double oy = 1 * zoom;
        int len_step = 10*(int)(zoom);
        if (ui->checkBox_accursy->checkState() == 0) {
            if (len_step > 100) len_step = 100;
        } else {
            if (len_step > 500) len_step = 50000;
        }

        double step = ox*2/60/len_step;
        QVector<double> x(65*len_step), y(65*len_step); //
        double o_now = -ox;
        for (int k = 0 ; k < 60*len_step+20; k++) {
       
            x[k] = o_now;

            double  result_y = 0;
            char char_str[1024] = {0};
            strcpy(char_str, insert_x_value(text_str, std::to_string(x[k])).c_str());
            run_calc(char_str, &result_y);
            y[k] = result_y;
            
            if (fabs(o_now) < 10e-6) {
                x[k] = 0;
            } else {
                x[k] = o_now;
            }


             //y[k] = tan(x[k]);
             std::cout << k << ". " <<x[k] << " : " << y[k] << std::endl;
             o_now += step;
        }


       // exit(0);
        // создаем график и добавляем данные:
        ui->widget->clearGraphs();
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x, y);
        // задаем имена осей координат
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        // задаем размеры осей
        ui->widget->xAxis->setRange((-ox), ox); // Область определения?
        ui->widget->yAxis->setRange((-oy), oy); // Диапозон значений
      

        if (ui->checkBox_point->isChecked() == 1) {
            ui->widget->graph(0)->setPen(QColor(Qt::black));//задаем цвет точки
            ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии
            ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
        }
        ui->widget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
        ui->widget->replot();
    }
}



void Dialog::on_but_zoom_out_clicked()
{

    /** 
     * @brief Уменьшеат мастштаб.
     *  @brief Минимальное значение 1000000
    */
    if (zoom < 1000000) {
        zoom = zoom * 2;
        build_graf(zoom);
    }
    std::cout << "78 " << zoom <<  std::endl;
}


void Dialog::on_but_zoom_in_clicked()
{
    /**
     * @brief  Увеличивает мастштаб.
     * @brief  Максимальное значение 1.
    */

    if (zoom > 1 ) {
        zoom = zoom/2;
        build_graf(zoom);
    }
}


void Dialog::on_but_build_graf_clicked() {

    build_graf(zoom);
}


void Dialog::on_but_check_clicked() {
    /**
     * @brief проверяет введенное выражение для графика
     */
    QString text = ui->line_text_graf->text();//  >text_graf.text() text();
    std::string x_str = "1";
    std::string text_str = text.toStdString();
    text_str = insert_x_value(text_str, x_str);
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


