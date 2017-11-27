#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tools.h"
#include "fileworker.h"
#include "chatworker.h"
#include "hintwidget.h"

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    enum WidgetState{Initial,Add,Remove};

    fileWorker * file;
    chatWorker * chat;

private:
    Ui::MainWindow *ui;
    hintWidget * hint;

    void setLocalUserEnable(bool status);
    void setLocalFileEnable(bool status);
    void setLanguage(void);
    void setTheme(void);
    void setWidgetState(WidgetState state);
    void getHelp(void);

    const qint8 DEFAULT_MESSAGE_FONT_SIZE = 14;
    const QString DEFAULT_FILE_IP = "127.0.0.1";
    const quint16 DEFAULT_FILE_PORT = 6109;

private slots:

    void showMessage(chatWorker::message_t type,QString hint,QString content);
    void updateProgressBar(fileWorker::update_t type, qint64 number);
    void updateOnlineUsers(QSet<QString> set);

    void click_btnSendMessage();
    void click_btnLogout();
    void click_btnLogin();

    void click_btnChooseFile();
    void click_btnListen();
    void click_btnSendFile();

    void updateFinalIP(QListWidgetItem*);
    void on_aboutButton_clicked();
};

#endif // MAINWINDOW_H
