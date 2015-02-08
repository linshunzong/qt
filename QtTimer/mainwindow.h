#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void timerEvent(QTimerEvent* e);
private:
    bool isTimerActive();
private slots:
    void on_kill_clicked();
    void on_startBtn_clicked();

    void on_QTimer_clicked();

    void timerOut();

    void on_signalshot_clicked();
    void timerOut1();
private:
    Ui::MainWindow* ui;
    int             m_timerId;
    long long       m_count;
    bool            m_bActice;
    QTimer*         m_timer;
};

#endif // MAINWINDOW_H
