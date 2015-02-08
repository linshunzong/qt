#include <QCoreApplication>

#include<QDate>
#include<QDateTime>
#include<QTime>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
      //The QDate class provides date functions
      QDate current_date = QDate::currentDate();
      QString date = current_date.toString("yyyy-MM-dd hh:mm:ss ddd");
      qDebug()<<date;
      qDebug()<<current_date.year()<<":"<<current_date.month()<<current_date.day()<<":"<<current_date.weekNumber();
      qDebug()<<current_date.dayOfWeek();

    }

    //获取系统现在的时间并设置显示格式
    {
        //The QDateTime class provides date and time functions
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
        qDebug()<<current_date;
    }

    {   //The QTime class provides clock time functions
        QTime current_time = QTime::currentTime();
        int hour = current_time.hour();
        int minute = current_time.minute();
        int second = current_time.second();
        int msec = current_time.msec();
        qDebug()<<current_time.toString("yyyy-MM-dd hh:mm:ss ddd");
        qDebug()<<hour<<":"<<minute<<":"<<second<<":"<<msec;
    }

    return a.exec();
}
