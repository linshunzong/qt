#include "widget.h"

#include<QLabel>
#include<QDebug>
#include<QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_label = new QLabel();
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_label);

    this->setLayout(layout);
}

Widget::~Widget()
{

}

QRect Widget::jindu()
{
    return this->geometry();
}

void Widget::setJindu(QRect &jindu)
{
    qDebug()<<jindu;

    static long long i = 0;
    QString text=QString("%1").arg(++i);
    m_label->setText(text);

    this->setGeometry(jindu);
}
