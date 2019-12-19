#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void digit_pressed();
    void on_pushButton_decimal_released();
    void unary_operator_pressed();

    void on_B_clear_released();
    void binary_operator_pressed();
    void on_pushButton_equal_released();
};

#endif // CALCULATOR_H
