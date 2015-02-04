#include <QCoreApplication>
#include<QDebug>

#include"myclass.h"


/**
 * @brief  属性使用
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //静态属性
    //1.通过类本身来设置
    MyClass* myclass = new MyClass();
    myclass->setPriority(MyClass::VeryHigh);
    qDebug()<<myclass->toString();

   //2.通过QObject来设置
    //测试1
    QObject* object = myclass;
    object->setProperty("priority","VeryHigh");//枚举类型在MyClass中声明并被使用Q_ENUMS()注册到元数据对象系统中。这使得枚举值可以在调用setProperty()时做为字符串使用。如果枚举类型是在其它类中声明的，那么我们就需要用枚举的全名（如OtherClass::Priority)，并且这个其它类也必须从QObject中派生并且也要注册枚举类型。
    qDebug()<<object->property("priority");
   //测试2
    object->setProperty("priority",MyClass::VeryLow);
    qDebug()<<object->property("priority");

    //动态属性
    object->setProperty("addRuntimeProperty","hello china");
    qDebug()<<object->property("addRuntimeProperty");

    return a.exec();
}
