/** ��ʱ��ʹ�÷�����
  *1.ʹ��QObject�Դ��Ķ�ʱ�������� startTimer�������¼�ΪtimerEvent
  *2.ʹ��QTimer��ʱ����
  *3.ʹ��QTimer::singleShot()��̬�������÷���ֻ�ᴥ��һ��
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
 * ����һ�� ������ʱ��
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
 * ����һ�� �رն�ʱ��
 * @brief MainWindow::on_kill_clicked
 */
void MainWindow::on_kill_clicked()
{
      this->killTimer(m_timerId);
      m_bActice = false;
}

/**
 * �������� ����/�رն�ʱ��
 * @brief MainWindow::on_QTimer_clicked
 */
void MainWindow::on_QTimer_clicked()
{
    if(NULL == m_timer){
        m_timer = new QTimer(this);
        connect(m_timer,SIGNAL(timeout()),this,SLOT(timerOut()));
    }
    if(!m_timer->isActive()){
        m_timer->start(1000); //����
    }else{
          m_timer->stop(); //�ر�
    }
}

void MainWindow::timerOut()
{
    static int n = 0;
    qDebug()<<"tiimer out..."<<n++;
}

/**
 * ������:������ʱ��
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
