import random

import requests
from bs4 import BeautifulSoup
import json
import csv
from time import sleep







center = [55.0166, 82.9544] # Novosibirsk coordinates
comma = ','
zoom = '16z'
target_point = [55.018772, 82.954974]
i = "i"
trb = 'trb'

url = 'https://votetovid.ru/#' + str(center[0]) + comma + str(center[1]) + comma + zoom + comma + str(target_point[0]) + comma + str(target_point[1]) + i + comma + trb

print(url)

headers = {
    "Accept": "*/*",
    "User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:101.0) Gecko/20100101 Firefox/101.0"
}




# ---- STEP 1 -----
req = requests.get(url, headers=headers)

src = req.text

# print(src)

#save cod page

with open("index.html", "w") as file:
    file.write(src)


# ---- STEP 2 ----
with open("index.html") as file:
    src = file.read()


soup = BeautifulSoup(src, "lxml")

span_txHgt = soup.find("div", class_="leaflet-popup-content")

print(span_txHgt)

# ("span", "data-key"="txHgt")

# height = span_txHgt.text

# print(height)