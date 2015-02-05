#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_ENUMS(Priority)
    Q_PROPERTY(Priority priority READ priority WRITE setPriority)
    Q_PROPERTY(QString version READ version WRITE setVersion)
public:
    enum Priority{High,Low,VeryHigh,VeryLow};
    explicit MyClass(QObject *parent = 0);
    void setPriority(Priority priority);
    Priority priority() const;

    QString version()const;
    void    setVersion(QString version);

public:
    QString toString();
signals:

public slots:

private:
    Priority m_priority;
    QString  m_version;
};

#endif // MYCLASS_H
