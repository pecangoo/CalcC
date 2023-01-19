#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>
#include <QMessageBox>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_but_1_clicked();
    void on_but_2_clicked();
    void on_but_3_clicked();
    void on_but_4_clicked();
    void on_but_5_clicked();
    void on_but_6_clicked();
    void on_but_7_clicked();
    void on_but_8_clicked();
    void on_but_9_clicked();
    void on_but_0_clicked();
    void on_but_sum_clicked();
    void on_but_sub_clicked();
    void on_but_div_clicked();
    void on_but_mul_clicked();
    void on_but_eq_clicked();
    //void on_but_pow_clicked();
    void on_but_pl_min_clicked();
    void on_but_cos_clicked();
    void on_but_sin_clicked();
    void on_but_tan_clicked();
    void on_but_atan_clicked();
    void on_but_acos_clicked();
    void on_but_asin_clicked();
    void on_but_sqrt_clicked();
    void on_but_check_clicked();
    void on_but_log_clicked();
    void on_but_ln_clicked();
    void on_but_graf_clicked();
    void on_but_x_clicked();
    void on_but_bro_clicked();
    void on_but_brc_clicked();
    void on_but_mod_clicked();
    void on_but_pow_clicked();
    void SetTextLine(std::string text_l);

   // std::string insert_x_value(std::string incoming_str);

    //int checking_depos_values(std::string str_sum,  std::string str_temp, std::string str_percent, std::string str_add, std::string str_get);
    int checking_credit_values(std::string str_credit_sum, std::string str_credit_term, std::string str_percent_value);
    int checking_depos_values(std::string str_sum, std::string str_temp,
                              std::string str_percent, std::string str_add,
                              std::string str_get, QString str1, QString str2);
    void on_but_check_2_clicked();
    void on_but_calc_credit_clicked();


    void on_but_dep_clicked();

    void on_comboBox_period_pays_2_currentIndexChanged(int index);

    void on_radioButton_add_clicked();

    void on_radioButton_pay_clicked();
    int next_stop_date(QDate *c_date, QString q_type);
    void on_comboBox_period_pays_3_currentIndexChanged(int index);

    void on_pushButton_11_clicked();


    void on_but_C_clicked();

    void on_but_ctg_clicked();

    void on_but_actg_clicked();

    void on_but_pi_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
