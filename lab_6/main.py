from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.action_chains import ActionChains
from bs4 import BeautifulSoup

import time




import numpy as np
import random
import json
import pickle


options = Options()
options.binary_location = r'C:\Program Files\Mozilla Firefox\firefox.exe'
driver = webdriver.Firefox(executable_path=r'C:\WebDrivers\geckodriver.exe', options=options)

center = [55.0166, 82.9544] # Novosibirsk coordinates
comma = ','
zoom = '16z'
target_point = [55.018772, 82.954974]
i = "i"
trb = 'trb'

url = 'https://votetovid.ru/#' + str(center[0]) + comma + str(center[1]) + comma + zoom + comma + str(target_point[0]) + comma + str(target_point[1]) + i + comma + trb

driver.get(url)

html_ = driver.page_source
soup = BeautifulSoup(html_, 'lxml')
span_txHgt = soup.find_all('span')[0]
height = span_txHgt.text
print(height)