#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLabel;

class Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QRect jindu READ jindu WRITE setJindu )
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QRect jindu();
    void setJindu(QRect &jindu);
private:
    QLabel* m_label;
};

#endif // WIDGET_H
