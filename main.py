from selenium import webdriver
from selenium.webdriver.common.by import By
from time import sleep

#rounding up!!!
receipt_id = 168812
receipt_amount = 113
receipt_time = 11
receipt_date = "06042022"
store_number = "1083"
link = "https://survey2.medallia.eu/?lidl-pl-feedless-fs&country=PL&language=PL-PL&prize_draw=Yes&lidlapp=No&CF=14&TNC=" + store_number

browser = webdriver.Chrome()
browser.get(link)
#cookie
browser.find_element(By.ID, "buttonBegin").click()
sleep(1)
#receipt id and age
browser.find_element(By.ID, "spl_rng_q_feedback_lms_please_enter_your_receipt_numb").send_keys(receipt_id)
browser.find_element(By.CLASS_NAME, "dropdown_dropdownSelector").click()
sleep(1)
browser.find_element(By.XPATH, "//li[@data-test-name='option-18---29-lat']").click()
browser.find_element(By.ID, "buttonNext").click()
sleep(1)
#first assessment
browser.find_element(By.ID, "onf_q_lidl_osat_five_scale_5").click()
browser.find_element(By.ID, "buttonNext").click()
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_overall_product_availability_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_availability_fruit_and_vegetables_fivestars_5").click()
browser.find_element(By.ID, "onf_q_lidl_availability_bakery_fivestars_5").click()
browser.find_element(By.ID, "onf_q_lidl_availability_fresh_meat_poultry_fish_fivestars_5").click()
browser.find_element(By.ID, "onf_q_lidl_availability_chilled_food_fivestars_5").click()
browser.find_element(By.ID, "onf_q_lidl_availability_frozen_food_fivestars_5").click()
browser.find_element(By.ID, "onf_q_lidl_availability_other_fivestars_5").click()
browser.find_element(By.ID, "onf_q_lidl_availability_weekly_promotional_products_fivestars_5").click()
browser.find_element(By.ID, "buttonNext").click()
sleep(1)
#products
browser.find_element(By.ID, "onf_q_lidl_ql_pl_do_you_think_products_missing_2").click()
browser.find_element(By.ID, "buttonNext").click()
#second assessment
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_overall_freshness_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_freshness_fruit_and_vegetables_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_freshness_flowers_plants_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_freshness_bakery_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_freshness_meat_poultry_fish_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_freshness_chilled_food_five_scale_5").click()
browser.find_element(By.ID, "buttonNext").click()
#third assessment
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_overall_cleanliness_presentation_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_cleanliness_car_park_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_cleanliness_shopping_trolleys_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_cleanliness_aisles_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_cleanliness_fruit_vegetables_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_cleanliness_bakery_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_cleanliness_fresh_meat_poultry_fish_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_cleanliness_weekly_promotional_products_five_scale_5").click()
browser.find_element(By.ID, "buttonNext").click()
#personnel & questions
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_friendliness_of_staff_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_question_to_staff_yn_1").click()
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_staff_availability_yn_1").click()
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_staff_ability_to_help_yn_1").click()
sleep(1)
browser.find_element(By.ID, "buttonNext").click()
#checkouts
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_service_at_checkout_five_scale_5").click()
browser.find_element(By.ID, "onf_q_lidl_waiting_time_five_scale_5").click()
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_receipt_correct_yn_1").click()
sleep(1)
browser.find_element(By.ID, "buttonNext").click()
#recommendation
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_nps_scale_10").click()
browser.find_element(By.ID, "buttonNext").click()
#receipt details
sleep(1)
browser.find_element(By.CLASS_NAME, "medallicons_medallicons").click()
sleep(1)
if receipt_amount < 20:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-0,00-zł---20,00-zł']").click()
elif receipt_amount < 40:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-20,01-zł---40,00-zł']").click()
elif receipt_amount < 60:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-40,01-zł---60,00-zł']").click()
elif receipt_amount < 80:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-60,01-zł---80,00-zł']").click()
elif receipt_amount < 200:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-80,01-zł---200,00-zł']").click()
else:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-powyżej-200,00-zł']").click()
browser.find_element(By.ID, "cal_q_lidl_date_of_purchase_date_").send_keys(receipt_date)
browser.find_element(By.XPATH, "//*[contains(text(), 'Wybierz')]").click()
sleep(1)
if receipt_time < 10:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-przed-godziną-10:00']").click()
elif receipt_time < 12:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-10:00---11:59']").click()
elif receipt_time < 14:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-12:00---13:59']").click()
elif receipt_time < 16:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-14:00---15:59']").click()
elif receipt_time < 18:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-16:00---17:59']").click()
elif receipt_time < 20:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-18:00---19:59']").click()
else:
    browser.find_element(By.XPATH, "//li[@data-test-name='option-po-godzinie-20:00']").click()
browser.find_element(By.XPATH, "//*[contains(text(), 'Wybierz')]").click()
browser.find_element(By.XPATH, "//li[@data-test-name='option-codziennie']").click()
browser.find_element(By.ID, "onf_q_lidl_gender_enum_3").click()
browser.find_element(By.ID, "buttonNext").click()
#online & lidlplus
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_ql_pl_do_you_use_our_online_store_1").click()
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_ql_pl_do_you_use_the_lidl_plus_app_1").click()
sleep(1)
browser.find_element(By.ID, "buttonNext").click()
#something else
sleep(1)
browser.find_element(By.ID, "onf_q_lidl_ql_pl_would_you_like_2").click()
sleep(1)
browser.find_element(By.ID, "buttonFinish").click()
sleep(2)
browser.close()
