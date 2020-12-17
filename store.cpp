#include "store.h"
#include<QSpinBox>
#include<QSlider>
#include<QDebug>
#include<QPalette>
Store::Store(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(650,600);
    this->setWindowTitle("魔法商店");

    spinBox1 = new QSpinBox(this);                       //创建SpinBox
    spinBox1->setParent(this);
    QSlider *slider1 = new QSlider(Qt::Horizontal);          //创建一个水平方向的 QSlider
    spinBox1->setRange(0, 10);                              //设置spinBox的值范围
    slider1->setRange(0, 10);                               //设置slider的值范围
    spinBox1->setGeometry(115,360,90,20);
    QObject::connect(spinBox1, SIGNAL(valueChanged(int)),
                     slider1, SLOT(setValue(int)));           //spinBox的值发生变化时，slider值也跟着变化
    QObject::connect(slider1, SIGNAL(valueChanged(int)),
                     spinBox1, SLOT(setValue(int)));          //slider的值发生变化时，spinBox值也跟着变化
    spinBox1->setValue(10);                                  //设定spinBox的初始值




    spinBox2 = new QSpinBox(this);                       //创建SpinBox
    spinBox2->setParent(this);
    QSlider *slider2= new QSlider(Qt::Horizontal);          //创建一个水平方向的 QSlider
    spinBox2->setRange(0, 10);                              //设置spinBox的值范围
    slider2->setRange(0, 10);                               //设置slider的值范围
    spinBox2->setGeometry(265,360,90,20);
    QObject::connect(spinBox2, SIGNAL(valueChanged(int)),
                     slider2, SLOT(setValue(int)));           //spinBox的值发生变化时，slider值也跟着变化
    QObject::connect(slider2, SIGNAL(valueChanged(int)),
                     spinBox2, SLOT(setValue(int)));          //slider的值发生变化时，spinBox值也跟着变化
    spinBox2->setValue(10);                                  //设定spinBox的初始值



    spinBox3 = new QSpinBox(this);                       //创建SpinBox
    spinBox3->setParent(this);
    QSlider *slider3 = new QSlider(Qt::Horizontal);          //创建一个水平方向的 QSlider
    spinBox3->setRange(0, 10);                              //设置spinBox的值范围
    slider3->setRange(0, 10);                               //设置slider的值范围
    spinBox3->setGeometry(415,360,90,20);



    QObject::connect(spinBox3, SIGNAL(valueChanged(int)),
                     slider3, SLOT(setValue(int)));           //spinBox的值发生变化时，slider值也跟着变化
    QObject::connect(slider3, SIGNAL(valueChanged(int)),
                     spinBox3, SLOT(setValue(int)));          //slider的值发生变化时，spinBox值也跟着变化
    spinBox3->setValue(10);                                  //设定spinBox的初始值



    ButtonA=new QPushButton(this);
    ButtonA->setParent(this);
    ButtonA->setText("");
    ButtonA->setGeometry(570,410,30,30);
    ButtonA->setStyleSheet("border:none;");
    QPalette pal7(this->palette());
    connect(ButtonA,&QPushButton::clicked,this,&Store::sendSlotB);
    //确认购买1
    ButtonB=new QPushButton(this);
    ButtonB->setParent(this);
    ButtonB->setText("");
    ButtonB->setGeometry(130,390,60,30);
    ButtonB->setStyleSheet("border:none;");
    QPalette pal10(this->palette());
    ButtonB->setIcon(QIcon(":/myImages/Images/my30.jpg"));
    ButtonB->setIconSize(QSize(60,30));
    connect(ButtonB,&QPushButton::released,this,&Store::getValue1);
    connect(ButtonB,&QPushButton::released,this,&Store::sendSlotC);
    //确认购买2
    Buttonc=new QPushButton(this);
    Buttonc->setParent(this);
    Buttonc->setText(" ");
    Buttonc->setGeometry(275,390,60,30);
    Buttonc->setStyleSheet("border:none;");
    QPalette pal11(this->palette());
    Buttonc->setIcon(QIcon(":/myImages/Images/my30.jpg"));
    Buttonc->setIconSize(QSize(60,30));
    connect(Buttonc,&QPushButton::released,this,&Store::getValue2);
    connect(Buttonc,&QPushButton::released,this,&Store::sendSlotD);
    //确认购买3
    ButtonD=new QPushButton(this);
    ButtonD->setParent(this);
    ButtonD->setText("");
    ButtonD->setGeometry(425,390,60,30);
    ButtonD->setStyleSheet("border:none;");
    QPalette pal12(this->palette());
    ButtonD->setIcon(QIcon(":/myImages/Images/my30.jpg"));
    ButtonD->setIconSize(QSize(60,30));
    connect(ButtonD,&QPushButton::released,this,&Store::getValue3);
    connect(ButtonD,&QPushButton::released,this,&Store::sendSlotE);

    labelA =new QLabel(this);
    labelA->setParent(this);
    labelA->setPixmap(QPixmap(":/myImages/Images/flower1.1.jpg"));
    labelA->setScaledContents(true);

    labelA->setGeometry(110,250,100,100);
    labelA->show();

    labelB =new QLabel(this);

    labelB->setParent(this);
    labelB->setPixmap(QPixmap(":/myImages/Images/flower2.1.jpg"));
    labelB->setScaledContents(true);

    labelB->setGeometry(260,250,100,100);
    labelB->show();
    labelC =new QLabel(this);

    labelC->setParent(this);
    labelC->setPixmap(QPixmap(":/myImages/Images/flower3.1.jpg"));
    labelC->setScaledContents(true);

    labelC->setGeometry(410,250,100,100);
    labelC->show();

}
void Store::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix4;
    pix4.load(":/myImages/Images/my28.jpg");


    //绘图操作
    painter.drawPixmap(0,0,this->width(),this->height(),pix4);


}
void Store::sendSlotB()
{

    emit mySignalB();


}
void Store::showValue2(int value)
{
   s=value;
}


void Store::getValue1()
{
    number1=spinBox1->value();
}
void Store::getValue2()
{
    number2=spinBox2->value();
}
void Store::getValue3()
{
    number3=spinBox3->value();
}
void Store::sendSlotC()
{

    reMoney=s-number1*50;
    if(reMoney>=0)
    {
    emit mySignalC();
        QMessageBox::information(NULL,tr("亲爱的小主人"),tr("您的订单处理成功"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this,tr("亲爱的小主人"),tr("没有更多的钱啦！"),QMessageBox::Yes);
    }
}

void Store::sendSlotD()
{
    reMoney=s-number2*50;
    if(reMoney>=0)
    {
    emit mySignalD();
        QMessageBox::information(NULL,tr("亲爱的小主人"),tr("您的订单处理成功"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this,tr("亲爱的小主人"),tr("没有更多的钱啦！"),QMessageBox::Yes);
    }
}

void Store::sendSlotE()
{
    reMoney=s-number3*50;
    if(reMoney>=0)
    {
    emit mySignalE();
        QMessageBox::information(NULL,tr("亲爱的小主人"),tr("您的订单处理成功"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this,tr("亲爱的小主人"),tr("没有更多的钱啦！"),QMessageBox::Yes);
    }
}

