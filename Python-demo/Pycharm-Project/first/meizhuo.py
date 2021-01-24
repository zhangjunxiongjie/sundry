"""在美桌网的美女专题抓取每组美女的图片"""
'''http://www.win4000.com/zt/meinv.html'''
'''引用了multiprocessing模块中的pool子块以创建进程池加快图片爬去的速度'''
'''开启多线程失败！！！'''

import requests
import re
from bs4 import BeautifulSoup


# import pymssql     #连接数据库并向数据库写数据的模块


def get_reques_yemian(url):
    try:
        ted = requests.get(url)
        ted.raise_for_status()
        ted.encoding = ted.apparent_encoding
        return ted.text
    except:
        return None


def get_reques_tupian(url):
    try:
        ted = requests.get(url)
        ted.raise_for_status()
        ted.encoding = ted.apparent_encoding
        return ted.content
    except:
        return None


def tada_suoyin(htmlr):
    suoyinz = []
    htmle = BeautifulSoup(htmlr, "html.parser")
    htmlr = (htmle.find_all('ul'))[2]
    for htmle in htmlr.find_all('li'):
        suoyin = {}
        suoyin['pm'] = htmle.find('p').string
        suoyin['wz'] = (htmle.find('a')).attrs['href']
        suoyinz.append(suoyin)
    for i in range(24):
        tada_zutu(suoyinz[i])


def tada_zutu(suoyin):
    html = get_reques_yemian(suoyin['wz'])
    htmle = BeautifulSoup(html, 'lxml')
    htmlr = (htmle.find_all('ul'))[3]
    tupian = []
    for i in htmlr.find_all('img'):
        result = re.search(r'data-original="(.*)_120_80.jpg"', str(i))
        tupian.append(result.group(1) + '.jpg')
    tupian.append(' ')
    suoyin['tpwz'] = tupian
    store_zutu(suoyin)


def store_zutu(zutuzd):
    path = 'E:\\Reptile Database\\美桌网\\'
    count = 0
    for i in zutuzd['tpwz']:
        if i == ' ':
            break
        pathr = path + (zutuzd['pm']) + str(count) + '.jpg'
        print(i)
        html = get_reques_tupian(i)
        count += 1
        f = open(pathr, 'wb')
        f.write(html)
        f.close()

        zutumin = (zutuzd['pm']) + str(count - 1)

        #        back_val = mssql.execute("INSERT INTO dbo.meizhuo('tupianmin', 'tupian') VALUES(zutumin, html)")
        '''此处的SQL语句有点问题,但是程序对数据库操作的基本逻辑搞清楚了即通过莫，模块连接数据库再通过其提供的执行sql方法执行SQL语句
        达到对数据库数据操作的目的'''

        #        if None == back_val:
        print(zutumin + '下载完成')


def main(i):
    urlr = "http://www.win4000.com/zt/meinv_"
    middle = ".html"
    html = get_reques_yemian(urlr + str(i) + middle)
    tada_suoyin(html)


'''
global ms
ms = pymssql.connect('DESKTOP-2G3KR50', 'sa', '125908111', 'reptile')
mssql = ms.cursor(as_dict=True)
if mssql:
    print('连接成功！')
else:
    print('连接失败！')
'''
for t in range(1, 6):
    main(t)
"""    
ms.commit()
ms.close()
"""
