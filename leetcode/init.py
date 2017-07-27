#! /usr/bin/env python
# coding=utf-8




import urllib2
import re
from bs4 import BeautifulSoup
import json

header = {
    'referer': 'https://leetcode.com/problemset/algorithms/',
    'user-agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537\
                .36 (KHTML, like Gecko) Chrome/55.0.2883.75 Safari/537.36',
    'host': 'leetcode.com',
    'cookie': 'LEETCODE_SESSION=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6IkdlbmVyYWxTYW5kIiwidXNlcl9zbHVnIjoiZ2VuZXJhbHNhbmQiLCJfYXV0aF91c2VyX2lkIjoiNTMyNTk0IiwidGltZXN0YW1wIjoiMjAxNy0wNi0wMSAwMzoxMDoxNC40NDQ0MDQrMDA6MDAiLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJkamFuZ28uY29udHJpYi5hdXRoLmJhY2tlbmRzLk1vZGVsQmFja2VuZCIsImlkIjo1MzI1OTQsIl9zZXNzaW9uX2V4cGlyeSI6MTIwOTYwMCwiX2F1dGhfdXNlcl9oYXNoIjoiZWZmMzc4NTYxNzUxZjE4MTU0YjBlOTY3YjI2ZTBjZTI5Y2MyYzRiOSIsImVtYWlsIjoiR2VuZXJhbFNhbmRtYW5AMTYzLmNvbSJ9.s5WPyuKDJpkEAVNWL0T6um2sNPTYWrrBrlSl5MNuPmE; OUTFOX_SEARCH_USER_ID_NCOO=1040168174.529293; __atuvc=2%7C20%2C0%7C21%2C1%7C22%2C12%7C23%2C3%7C24; __atuvs=593cf99088001a95002; csrftoken=AiTc6aov9S3LYDooJjVXXwsnfyUDEV4hKZuRHT4RHZQVri0tvcdd5hgtvwoAOhlT; _ga=GA1.2.450060489.1494932433; _gid=GA1.2.233126529.1496999381'}
url = 'https://leetcode.com/tag/breadth-first-search/'
request = urllib2.Request(url, headers=header)
response = urllib2.urlopen(request)
page = response.read()
soup = BeautifulSoup(page, 'html.parser')
table = soup.select('tbody')
soup = BeautifulSoup(str(table[0]), 'html.parser')
tables = soup.select('tr')


# # print len(tables)
# print tables[0]
# # print '------'
# print tables[2]

def function(number, name):
    def strS(number):
        if len(number) == 3:
            return number
        if len(number) == 2:
            return '0' + number
        if len(number) == 1:
            return '00' + number

    def strN(name):
        names = []
        names = name.split(' ')
        return names

    file = ''
    file = file + strS(number) + '_'
    names = strN(name)
    for name in names:
        file += name
    file += "__.cc"

    return file


import shutil

for table in tables:
    soup = BeautifulSoup(str(table), 'html.parser')
    i = soup.select('i')
    if len(i) == 0:
        soup = BeautifulSoup(str(table), 'html.parser')
        tds = soup.select('td')
        number = tds[1].text.lstrip('\n').lstrip(' ').rstrip(' ').rstrip('\n')
        soup = BeautifulSoup(str(table), 'html.parser')
        a = soup.select('a')
        name = a[0].text

        filename = function(number, name)
        shutil.copy("../template.cc", filename)
