#include "flowers.h"
#include"window2.h"
#include<QPushButton>
#include<QTimer>


flowers::flowers(QWidget *parent) : QWidget(parent)
{
    //每10秒植物的饥渴度增加0.05
    QTimer *timer=new QTimer(this);
    connect (timer,SIGNAL(timeout()),this,SLOT(thirsty1Add()));
    timer->start(1000);
    //每秒植物的生长值增加0.05
    QTimer *timer1=new QTimer(this);
    connect (timer1,SIGNAL(timeout()),this,SLOT(growth1Add()));
    timer1->start(1000);


}





void flowers::thirsty1Add()
{
   thirsty1+=0.008;

}

void flowers::growth1Add()
{
    if(seed==true)
    {
      growth1+=0.01;
    }

}
