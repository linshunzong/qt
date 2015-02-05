#include <QApplication>  
#include <QLabel>  
#include"Hello.h"
 int main(int argc,char *argv[])  
 
    {  
 
        QApplication app(argc,argv);  
 
        Hello* hello = new Hello();
        QLabel *label = new QLabel(hello->toString());
 
        label->show();  
 
        return app.exec();  
 
    }  
