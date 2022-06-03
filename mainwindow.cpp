#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    show_saved_receipt();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_save_button_clicked()
{
    if(ui->store_number->displayText() != "" && ui->store_number->displayText().length() == 4)
        if(ui->receipt_number->displayText() != "")
            if(ui->receipt_value->displayText() != "")
            {
                save_receipt();
                ui->receipt_number->clear();
                ui->receipt_value->clear();
                //ui->receipt_number->setSelection(QAbstractItemView::ExtendedSelection);
            }

}

void MainWindow::save_receipt()
{
    string receipt;

    receipt = ui->store_number->displayText().toStdString();
    receipt += "\n";
    receipt += ui->receipt_number->displayText().toStdString();
    receipt += "\n";
    receipt += ui->receipt_value->displayText().toStdString();
    receipt += "\n";
    receipt += ui->receipt_time->time().toString().toStdString();
    receipt += "\n";
    receipt += ui->receipt_date->date().toString().toStdString();
    receipt += "\n";


    fstream file;
    file.open(RECEIPTS_PATH,ios::app);
    file << receipt;
    file.close();
}

void MainWindow::on_store_number_returnPressed()
{
    ui->receipt_number->setFocus();
}


void MainWindow::on_receipt_number_returnPressed()
{
    ui->receipt_value->setFocus();
}


void MainWindow::on_receipt_value_returnPressed()
{
    ui->receipt_time->setFocus();

}


void MainWindow::on_receipt_time_editingFinished()
{
    ui->receipt_date->setFocus();
}


void MainWindow::on_receipt_date_editingFinished()
{
    ui->save_button->click();
    ui->receipt_number->setFocus();
    show_saved_receipt();
}

void MainWindow::load_receipt()
{
    string str;
    fstream file;

    QS_store_number.clear();
    QS_receipt_number.clear();
    QS_receipt_value.clear();
    QS_receipt_time.clear();
    QS_receipt_date.clear();

    file.open(RECEIPTS_PATH);
    if( file.good() )
        {
            while( !file.eof() )
            {
                getline( file, str );
                QS_store_number.push_back(QString::fromStdString(str));

                getline( file, str );
                QS_receipt_number.push_back(QString::fromStdString(str));

                getline( file, str );
                QS_receipt_value.push_back(QString::fromStdString(str));

                getline( file, str );
                QS_receipt_time.push_back(QString::fromStdString(str));

                getline( file, str );
                QS_receipt_date.push_back(QString::fromStdString(str));

            }
            file.close();
        }
}

void MainWindow::show_saved_receipt()
{
    load_receipt();
    QString QS_saved_receipt = QString::number(QS_store_number.size());
    ui->saved_receipt->clear();
    ui->saved_receipt->setText(QS_saved_receipt);

}
