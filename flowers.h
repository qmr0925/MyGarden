#ifndef FLOWERS_H
#define FLOWERS_H
#include<QTimer>
#include <QWidget>
//#include"window2.h"
#include"flowers.h"
class flowers : public QWidget
{
    Q_OBJECT
public:
    explicit flowers(QWidget *parent = 0);
    //只有田地有植物才能浇水施肥
    //第一亩田的植物的生长值,每施一次肥增长百分之二十，当出现浇水按钮，施肥按钮隐藏，当生长值达到百分之百，饥渴度小于0.3则出现收获按钮
     double growth1=0;
    //第二亩田的植物的生长值
    //int growth2=0;
    //第三亩田的植物的生长值
    //int growth3=0;

    //第四亩田的植物的生长值
    //int growth4=0;

    //第一亩田的植物的渴值，每秒增高0.003；高于百分之30需浇水，每浇水一次降低百分之二十
    double thirsty1=0;
    bool notThirsty=false;
    bool notHurry=false;
    bool seed=false;
    //表示收获是否成功
    bool harvested=false;
    int varity;




signals:

public slots:
    void thirsty1Add();
    void growth1Add();

};

#endif // FLOWERS_H
