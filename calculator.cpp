#include "calculator.h"
#include "ui_calculator.h"
#include<QDebug>
double firstnum;
bool userIsTypingSecondNum=false ;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_sign,SIGNAL(released()),this,SLOT(unary_operator_pressed()));
    connect(ui->pushButton_modulus,SIGNAL(released()),this,SLOT(unary_operator_pressed()));

    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operator_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operator_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operator_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operator_pressed()));
    ui->pushButton_add->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::digit_pressed(){
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;
    double labelNumber;
    if((ui->pushButton_add->isChecked()||ui->pushButton_minus->isChecked()||ui->pushButton_multiply->isChecked()||ui->pushButton_divide->isChecked())&&(!userIsTypingSecondNum))
    {labelNumber = button->text().toDouble();
    userIsTypingSecondNum=true;
    newLabel = QString::number(labelNumber,'g',15);}
    else
    {if (ui->label->text().contains('.')&&button->text()=="0")
        { newLabel = ui->label->text()+button->text();  }
    else
       { labelNumber= (ui->label->text()+button->text()).toDouble();
    newLabel = QString::number(labelNumber,'g',15);}}




    ui->label->setText(newLabel);
}

void Calculator::on_pushButton_decimal_released()
{   QString s = ui->label->text();
    if (!s.contains('.',Qt::CaseInsensitive))
    ui->label->setText(ui->label->text()+'.');
}
void Calculator::unary_operator_pressed()
{
    QPushButton* button = (QPushButton*)sender();
    double labelNumber;
    QString s;
    if(button->text()=="+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber=labelNumber*-1;
        s = QString::number(labelNumber,'g',15);
        ui->label->setText(s);
    }
    if(button->text()=="%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber=labelNumber*0.01;
        s = QString::number(labelNumber,'g',15);
        ui->label->setText(s);
    }


}


void Calculator::on_B_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    userIsTypingSecondNum = false;
    ui->label->setText("0");
}

void Calculator::on_pushButton_equal_released()
{
    double labelNumber, secondnum;
    QString s;
    secondnum = ui->label->text().toDouble();
    if(ui->pushButton_add->isChecked())
    {labelNumber=firstnum+secondnum;
    s = QString::number(labelNumber,'g',15);
    ui->label->setText(s);
    ui->pushButton_add->setChecked(false);}
    else if(ui->pushButton_minus->isChecked())
    {labelNumber=firstnum-secondnum;
        s = QString::number(labelNumber,'g',15);
        ui->label->setText(s);
        ui->pushButton_minus->setChecked(false);}
    else if(ui->pushButton_multiply->isChecked())
    {labelNumber=firstnum*secondnum;
        s = QString::number(labelNumber,'g',15);
        ui->label->setText(s);
        ui->pushButton_multiply->setChecked(false);}
    else if(ui->pushButton_divide->isChecked())
    {
        labelNumber=firstnum+secondnum;
            s = QString::number(labelNumber,'g',15);
            ui->label->setText(s);
            ui->pushButton_divide->setChecked(false);
    }
    userIsTypingSecondNum = false;
}
void Calculator::binary_operator_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    firstnum = ui->label->text().toDouble();
    button->setChecked(true);

}
