#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recorder.h"
#include "user.h"
#include "adduserwindow.h"
#include "userwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(UserWindow *uw, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void proceed();
	void onRecordingStopped(qint64 bytes);
    void on_AddUserButton_clicked();
    void on_EditUserButton_clicked();
    void on_ImportUsersDataButton_clicked();
    void on_ExportUsersDataButton_clicked();

private:
    Ui::MainWindow *ui;
    UserWindow *userWindow;
    bool recordOnRun;
    Recorder recorder;
    AddUserWindow *auw;

    void initialiseDeviceList();
    void insertUserToList(User * const user);
};

#endif // MAINWINDOW_H
