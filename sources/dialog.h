#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

private:
    std::string text_string;
    unsigned int zoom = 1;

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

public slots:
   void foo_input(std::string value);
   void build_graf(unsigned int zoom);

public slots:
    void on_but_zoom_out_clicked();
    void on_but_zoom_in_clicked();
    void on_but_build_graf_clicked();

private slots:
    void on_but_check_clicked();
};



#endif // DIALOG_H
