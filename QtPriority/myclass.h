#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Priority priority READ priority WRITE setPriority)
    Q_ENUMS(Priority)
public:
    enum Priority{High,Low,VeryHigh,VeryLow};
    explicit MyClass(QObject *parent = 0);
    void setPriority(Priority priority);
    Priority priority() const;
public:
    QString toString();
signals:

public slots:

private:
    Priority m_priority;

};

#endif // MYCLASS_H
