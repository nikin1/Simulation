from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.action_chains import ActionChains
from bs4 import BeautifulSoup

from time import sleep
import math



import numpy as np
import random
import json
import pickle


options = Options()
options.binary_location = r'C:\Program Files\Mozilla Firefox\firefox.exe'
driver = webdriver.Firefox(executable_path=r'C:\WebDrivers\geckodriver.exe', options=options)

center = [55.0747, 82.9269] # Novosibirsk coordinates
comma = ','
zoom = '16z'
target_point = [55.056152, 82.881203, 55.034515, 82.991753]


#55.056152        82.881203 - first point

#55.034515        82.991753 - last point
#lat              long
#вертикально      горизонтально

# * (55.056152, 82.881203)
#
#
#              *(55.034515, 82.991753)
# расстояние 20 м
delta = 0.0001 # 0.00018018018018018018




i = "i"
trb = 'trb'

cnt = 0
max_cnt = 100

lat = target_point[0]
long = target_point[1]
print("START")
while math.fabs(target_point[2] - lat) > delta:   # значит значение уже максимально приблизилось к нужному
    # print("DO")
    while math.fabs(target_point[3] - long) > delta:


        url = 'https://votetovid.ru/#' + str(center[0]) + comma + str(center[1]) + comma + zoom + comma + str(lat) + comma + str(long) + i + comma + trb
        # url = https://votetovid.ru/#55.0167,82.9544,16z,55.018772,82.954974i,trb

        # print("URL: ", url)
        driver.get(url)

        sleep(3)
        html_ = driver.page_source

        soup = BeautifulSoup(html_, 'lxml')
        sleep(3)

        span_txHgt = soup.find("div", class_="leaflet-popup-content").find('span')

        height = span_txHgt.text
        print(lat, long, height)





        cnt += 1
        # print("cnt: ", cnt)
        if cnt == max_cnt:
            break
        long += delta
    

    if cnt == max_cnt:
        break

    lat -= delta



print("END")

# print(span_txHgt)

# print(url)


