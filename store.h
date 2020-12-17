#ifndef STORE_H
#define STORE_H
#include<QPixmap>
#include<QPainter>
#include<QPaintEvent>
#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QSpinBox>
#include<QMessageBox>
class Store : public QWidget
{
    Q_OBJECT
public:
    explicit Store(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    int  number1=0;
    int  number2=0;
    int  number3=0;
    int s=0;
    int reMoney;
private:
    QPushButton *ButtonA;
    QPushButton *ButtonB;
    QPushButton *Buttonc;
    QPushButton *ButtonD;

    QSpinBox *spinBox1;
      QSpinBox *spinBox2;
        QSpinBox *spinBox3;



    QLabel *labelA;
    QLabel *labelB;
    QLabel *labelC;
signals:
    void mySignalB();
     void mySignalC();
     void mySignalD();
     void mySignalE();
public slots:
    void sendSlotB();
    void sendSlotC();
     void sendSlotD();
      void sendSlotE();

    void getValue1();
    void getValue2();
    void getValue3();
    void showValue2(int);
};

#endif // STORE_H
