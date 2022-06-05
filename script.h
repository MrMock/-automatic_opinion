#ifndef SCRIPT_H
#define SCRIPT_H

#define SCRIPT_PATH "script.py"

#include <QMainWindow>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Script
{
public:
    void set_store_number(string store_number);
    void set_receipt_number(string receipt_number);
    void set_receipt_value(string receipt_value);
    void set_receipt_time(string receipt_time);
    void set_receipt_date(string receipt_date);
    void start();

private:

    string store_number;
    string receipt_number;
    string receipt_value;
    string receipt_time;
    string receipt_date;

    void save_file(string sting_to_save);
    void clear_file();

    void import_drivers();
    void id_age();
    void general();
    void first_rating();
    void expected_products();
    void second_rating();
    void third_rating();
    void personel_rating();
    void checkouts_rating();
    void recommendation();
    void receipt_details();
    void online_shop();
    void something_else();

    void button_next();
    void button_finish();
    void close_browser();

    void order();

};

#endif // SCRIPT_H
