#include "script.h"

void Script::start()
{
    order();
    system("start.bat");
}

void Script::order()
{
    clear_file();

    import_drivers();

    id_age();
    button_next();

    general();
    button_next();

    first_rating();
    button_next();

    expected_products();
    button_next();

    second_rating();
    button_next();

    third_rating();
    button_next();

    personel_rating();
    button_next();

    checkouts_rating();
    button_next();

    recommendation();
    button_next();

    receipt_details();
    button_next();

    online_shop();
    button_next();

    something_else();
    button_finish();

    close_browser();
}

void Script::save_file(string string_to_save)
{
    fstream file;
    file.open(SCRIPT_PATH,ios::app);
    file << string_to_save;
    file.close();
}

void Script::clear_file()
{
    fstream file;
    file.open(SCRIPT_PATH,ios::out);
    file << "";
    file.close();
}

void Script::import_drivers()
{
    string str  =                   "from selenium import webdriver\n";
           str +=                   "from selenium.webdriver.common.by import By\n";
           str +=                   "import sys\n";
           str +=                   "from time import sleep\n";
           str +=                   "link = \"https://survey2.medallia.eu/?lidl-pl-feedless-fs&country=PL&language=PL-PL&prize_draw=Yes&lidlapp=No&CF=14&TNC=";
           str +=                   store_number;
           str +=                   "\"\nbrowser = webdriver.Chrome()\n";
           str +=                   "browser.get(link)\n\n";

    save_file(str);

}
void Script::id_age()
{
    string str  =                   "sleep(1)\n";
           str +=                   "browser.find_element(By.ID, \"buttonBegin\").click()\n";
           str +=                   "browser.find_element(By.ID, \"spl_rng_q_feedback_lms_please_enter_your_receipt_numb\").send_keys(\"";
           str +=                   receipt_number;
           str +=                   "\")\n";
           str +=                   "browser.find_element(By.CLASS_NAME, \"dropdown_dropdownSelector\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-18---29-lat']\").click()\n";


    save_file(str);
}
void Script::general()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_osat_five_scale_5\").click()\n";

    save_file(str);
}

void Script::first_rating()
{

    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_overall_product_availability_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_availability_fruit_and_vegetables_fivestars_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_availability_bakery_fivestars_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_availability_fresh_meat_poultry_fish_fivestars_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_availability_chilled_food_fivestars_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_availability_frozen_food_fivestars_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_availability_other_fivestars_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_availability_weekly_promotional_products_fivestars_5\").click()\n";

    save_file(str);
}


void Script::expected_products()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_ql_pl_do_you_think_products_missing_2\").click()\n";


    save_file(str);
}

void Script::second_rating()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_overall_freshness_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_freshness_fruit_and_vegetables_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_freshness_flowers_plants_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_freshness_bakery_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_freshness_meat_poultry_fish_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_freshness_chilled_food_five_scale_5\").click()\n";

    save_file(str);
}

void Script::third_rating()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_overall_cleanliness_presentation_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_cleanliness_car_park_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_cleanliness_shopping_trolleys_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_cleanliness_aisles_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_cleanliness_fruit_vegetables_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_cleanliness_bakery_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_cleanliness_fresh_meat_poultry_fish_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_cleanliness_weekly_promotional_products_five_scale_5\").click()\n";

    save_file(str);
}

void Script::personel_rating()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_friendliness_of_staff_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_question_to_staff_yn_1\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_staff_availability_yn_1\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_staff_ability_to_help_yn_1\").click()\n";
           str +=                   "sleep(1)\n";

    save_file(str);
}

void Script::checkouts_rating()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_service_at_checkout_five_scale_5\").click()\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_waiting_time_five_scale_5\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_receipt_correct_yn_1\").click()\n";

    save_file(str);
}

void Script::recommendation()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_nps_scale_10\").click()\n";

    save_file(str);
}

void Script::receipt_details()
{
    int temp_value = stoi(receipt_value);
    string t = receipt_time;
    t.erase(2);
    int temp_time = stoi(t);

    string str  =                   "browser.find_element(By.CLASS_NAME, \"medallicons_medallicons\").click()\n";
           str +=                   "sleep(1)\n";
           if     (temp_value < 20)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-0,00-zł---20,00-zł']\").click()\n";
           else if(temp_value < 40)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-20,01-zł---40,00-zł']\").click()\n";
           else if(temp_value < 60)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-40,01-zł---60,00-zł']\").click()\n";
           else if(temp_value < 80)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-60,01-zł---80,00-zł']\").click()\n";
           else if(temp_value < 200)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-80,01-zł---200,00-zł']\").click()\n";
           else
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-powyżej-200,00-zł']\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.ID, \"cal_q_lidl_date_of_purchase_date_\").send_keys(\"";
           str +=                   receipt_date;
           str +=                   "\")\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.XPATH, \"//*[contains(text(), 'Wybierz')]\").click()\n";
           str +=                   "sleep(1)\n";
           if (temp_time < 10)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-przed-godziną-10:00']\").click()\n";
           else if(temp_time < 12)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-10:00---11:59']\").click()\n";
           else if(temp_time < 14)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-12:00---13:59']\").click()\n";
           else if(temp_time < 16)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-14:00---15:59']\").click()\n";
           else if(temp_time < 18)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-16:00---17:59']\").click()\n";
           else if(temp_time < 20)
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-18:00---19:59']\").click()\n";
           else
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-po-godzinie-20:00']\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.XPATH, \"//*[contains(text(), 'Wybierz')]\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.XPATH, \"//li[@data-test-name='option-codziennie']\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_gender_enum_3\").click()\n";


    save_file(str);
}

void Script::online_shop()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_ql_pl_do_you_use_our_online_store_1\").click()\n";
           str +=                   "sleep(1)\n";
           str +=                   "browser.find_element(By.ID, \"onf_q_lidl_ql_pl_do_you_use_the_lidl_plus_app_1\").click()\n";


    save_file(str);
}

void Script::something_else()
{
    string str  =                   "browser.find_element(By.ID, \"onf_q_lidl_ql_pl_would_you_like_2\").click()\n";

    save_file(str);
}

void Script::button_next()
{
   string str  =                   "sleep(1)\n";
          str +=                   "browser.find_element(By.ID, \"buttonNext\").click()\n";
          str +=                   "sleep(1)\n";

    save_file(str);
}

void Script::button_finish()
{
    string str  =                   "sleep(1)\n";
           str +=                   "browser.find_element(By.ID, \"buttonFinish\").click()\n";
           str +=                   "sleep(1)\n";


    save_file(str);
}

void Script::close_browser()
{
    string str  =                   "browser.close()\n";
           str +=                   "sys.exit()";

    save_file(str);
}

void Script::set_store_number(string store_number)
{
    this->store_number = store_number;
}

void Script::set_receipt_number(string receipt_number)
{
    this->receipt_number = receipt_number;
}

void Script::set_receipt_value(string receipt_value)
{
    this->receipt_value = receipt_value;
}

void Script::set_receipt_time(string receipt_time)
{
    this->receipt_time = receipt_time;
}

void Script::set_receipt_date(string receipt_date)
{
    this->receipt_date = receipt_date;
}
