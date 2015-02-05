#include "myclass.h"

MyClass::MyClass(QObject *parent) :
    QObject(parent)
{
}

void MyClass::setPriority(MyClass::Priority priority)
{
    this->m_priority = priority;
}

MyClass::Priority MyClass::priority() const
{
    return this->m_priority;
}

QString MyClass::version() const
{
    return this->m_version;
}

void MyClass::setVersion(QString version)
{
    this->m_version = version;
}

QString MyClass::toString()
{
    int p = this->m_priority;
    QString ret;
    return  ret.sprintf("%d",p);
}
