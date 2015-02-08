/** 定时器使用方法：
  *1.使用QObject自带的定时器方法： startTimer，关联事件为timerEvent
  *2.使用QTimer定时器类
  *3.使用QTimer::singleShot()静态方法，该方法只会触发一次
  *
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QTimer>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_count(1),
    m_bActice(false),
    m_timer(NULL)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    QString text = QString("%1").arg(m_count++);
    ui->label->setText(text+"%");
    if(m_count == 101){
        on_kill_clicked();
    }
}

bool MainWindow::isTimerActive()
{
    return m_bActice;
}


/**
 * 方法一： 启动定时器
 * @brief MainWindow::on_startBtn_clicked
 *
 */
void MainWindow::on_startBtn_clicked()
{
    if(!isTimerActive()){
          m_timerId =  this->startTimer(1000);
          m_bActice = true;
          qDebug()<<m_timerId;
    }
}

/**
 * 方法一： 关闭定时器
 * @brief MainWindow::on_kill_clicked
 */
void MainWindow::on_kill_clicked()
{
      this->killTimer(m_timerId);
      m_bActice = false;
}

/**
 * 方法二： 启动/关闭定时器
 * @brief MainWindow::on_QTimer_clicked
 */
void MainWindow::on_QTimer_clicked()
{
    if(NULL == m_timer){
        m_timer = new QTimer(this);
        connect(m_timer,SIGNAL(timeout()),this,SLOT(timerOut()));
    }
    if(!m_timer->isActive()){
        m_timer->start(1000); //启动
    }else{
          m_timer->stop(); //关闭
    }
}

void MainWindow::timerOut()
{
    static int n = 0;
    qDebug()<<"tiimer out..."<<n++;
}

/**
 * 方法三:启动定时器
 * @brief MainWindow::on_signalshot_clicked
 */
void MainWindow::on_signalshot_clicked()
{
    QTimer::singleShot(3000,this,SLOT(timerOut1()));
}

void MainWindow::timerOut1()
{
    static int n = 0;
    qDebug()<<"tiimer out111..."<<n++;
}
