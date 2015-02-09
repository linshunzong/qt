#include <QApplication>
#include<QPushButton>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QSequentialAnimationGroup>
#include<QStateMachine>
#include<QSignalTransition>



#include"widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton* pushbutton = new QPushButton("Animation button");
    pushbutton->show();
    QPropertyAnimation* animation = new QPropertyAnimation(pushbutton,"geometry");
    animation->setDuration(10000);
    /**
     * ����һ��
     *��ʼֵ�����ֵ֮�������Բ�ֵ
     */
    //
#if 1
    animation->setStartValue(QRect(0,0,100,30));
    animation->setEndValue(QRect(450,450,100,30));
    //��������
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
#endif

 #if 0
    /**
     * ��������
     * ��ֵ�ܻ���ǰ80%��·���ƶ���(250,250)����20%�ƶ���(0,0)
     */
    animation->setKeyValueAt(0,QRect(0,0,100,30));
    animation->setKeyValueAt(0.8,QRect(250,250,100,30));
    animation->setKeyValueAt(1,QRect(0,0,100,30));
    animation->start();
#endif
    /**
     *  ��������
     *�Զ������� jindu ���ڶ���λ�øı��ÿһ���������Ե�set������ע���Զ������Եķ���ֵһ��ҪΪQRect
     **/
    Widget* w = new Widget();
    w->show();
    QPropertyAnimation* animation1 = new QPropertyAnimation(w,"jindu");
    animation1->setDuration(10000);
    animation1->setKeyValueAt(0,QRect(0,0,100,30));
    animation1->setKeyValueAt(1,QRect(250,250,100,30));
    animation1->start();

    /**
      *��������
      */
    /**
     * ����һ�����ж���
     */
#if 0
    QPushButton* bonnie = new QPushButton("Bonnie");
    bonnie->show();
    QPushButton* clyde = new QPushButton("Clyde");
    clyde->show();
    QPropertyAnimation* anim1 = new QPropertyAnimation(bonnie,"geometry");
    anim1->setDuration(10000);
    anim1->setStartValue(QRect(0,0,130,130));
    anim1->setEndValue(QRect(380,250,150,50));
    QPropertyAnimation* anim2 = new QPropertyAnimation(clyde,"geometry");
    anim2->setDuration(8000);
    anim2->setStartValue(QRect(0,0,130,130));
    anim2->setEndValue(QRect(480,150,80,20));
    QParallelAnimationGroup* group = new QParallelAnimationGroup;
    group->addAnimation(anim1);
    group->addAnimation(anim2);
    group->start();
#endif
    /**
     * �����������ж���
     */
    QPushButton* bonnie = new QPushButton("Bonnie");
    bonnie->show();
    QPushButton* clyde = new QPushButton("Clyde");
    clyde->show();
    QPropertyAnimation* anim1 = new QPropertyAnimation(bonnie,"geometry");
    anim1->setDuration(10000);
    anim1->setStartValue(QRect(0,0,130,130));
    anim1->setEndValue(QRect(380,250,150,50));
    QPropertyAnimation* anim2 = new QPropertyAnimation(clyde,"geometry");
    anim2->setDuration(8000);
    anim2->setStartValue(QRect(0,0,130,130));
    anim2->setEndValue(QRect(480,150,80,20));
    QSequentialAnimationGroup* group = new QSequentialAnimationGroup;
    group->addAnimation(anim1);
    group->addAnimation(anim2);
    group->start();

    {  /**
         * ״̬��
         */
        QPushButton *button = new QPushButton("Animated ButtonPPPPPP");
        button->show();

        //����һ��״̬��
        QStateMachine *machine = new QStateMachine;

        //״̬1
        QState *state1 = new QState(machine);
        state1->assignProperty(button, "geometry", QRect(0, 0, 100, 30));

        //״̬��ʼ��
        machine->setInitialState(state1);

        //״̬2
        QState *state2 = new QState(machine);
        state2->assignProperty(button, "geometry", QRect(250, 250, 100, 30));

        //��������
        QSignalTransition *transition1 = state1->addTransition(button,SIGNAL(clicked()), state2);
        transition1->addAnimation(new QPropertyAnimation(button, "geometry"));

        QSignalTransition *transition2 = state2->addTransition(button,SIGNAL(clicked()), state1);
        transition2->addAnimation(new QPropertyAnimation(button, "geometry"));machine->start();
   }


    return a.exec();
}
