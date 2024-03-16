#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setUiDefaultState();
    ~MainWindow();

private slots:
    void on_comboBox_activated(int index);
    void on_pushButtonEdit_clicked(bool checked);
    void on_pushButtonLaunch_clicked(bool checked);
    void on_pushButtonPause_clicked(bool checked);
    void on_pushButtonLoad_clicked();
    void on_pushButtonSave_clicked();
    void on_autoRobotIcon_clicked();
    void on_RCRobotIcon_clicked();
    void on_obstacleIcon_clicked();
    void updateRobotMoveSpeed(double value);
    void updateRobotAngularSpeed(double value);
    void updateCollisionDetectionDistance(double value);
private:
    Ui::MainWindow *ui;
    QString _fileToOpen;
    QString _fileToSave;
    bool _editingEnabled;
    bool _isLaunched;
    bool _isPaused;
    bool _turnRight;
    double _robotMoveSpeed;
    double _robotAngularSpeed;
    double _collisionDetectionDistance;

};
#endif // MAINWINDOW_H
