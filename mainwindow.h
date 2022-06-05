#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define RECEIPTS_PATH "receipts.txt"

#include <QMainWindow>
#include <fstream>
#include <vector>
#include "script.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_save_button_clicked();

    void on_store_number_returnPressed();

    void on_receipt_number_returnPressed();

    void on_receipt_value_returnPressed();

    void on_receipt_time_editingFinished();

    void on_receipt_date_editingFinished();

    void on_pushButton_2_clicked();

protected:
    Ui::MainWindow *ui;
    vector<QString> QS_store_number;
    vector<QString> QS_receipt_number;
    vector<QString> QS_receipt_value;
    vector<QString> QS_receipt_time;
    vector<QString> QS_receipt_date;
private:
    void save_receipt();
    void load_receipt();
    void show_saved_receipt();
    bool is_started;
};
#endif // MAINWINDOW_H
