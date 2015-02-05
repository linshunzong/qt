#include <QCoreApplication>
#include<QDebug>

#include"myclass.h"


/**
 * @brief  ���Բ���
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //��̬����
    //1.ͨ���౾��������
    MyClass* myclass = new MyClass();
    myclass->setPriority(MyClass::VeryHigh);
    qDebug()<<myclass->toString();

    myclass->setVersion("v0.0.1");
    qDebug()<<myclass->version();


   //2.ͨ��QObject������
    //����1
    QObject* object = myclass;
    object->setProperty("priority","VeryHigh");//ö��������MyClass����������ʹ��Q_ENUMS()ע�ᵽԪ���ݶ���ϵͳ�С���ʹ��ö��ֵ�����ڵ���setProperty()ʱ��Ϊ�ַ���ʹ�á����ö�����������������������ģ���ô���Ǿ���Ҫ��ö�ٵ�ȫ������OtherClass::Priority)���������������Ҳ�����QObject����������ҲҪע��ö�����͡�
    qDebug()<<object->property("priority");

    qDebug()<<object->property("version").toString();
    object->setProperty("version","v0.0.2");
    qDebug()<<object->property("version").toString();

   //����2
    object->setProperty("priority",MyClass::VeryLow);
    qDebug()<<object->property("priority");

    //��̬����
    object->setProperty("addRuntimeProperty","hello china");
    qDebug()<<object->property("addRuntimeProperty");

    return a.exec();
}
