"""在美桌网的美女专题抓取每组美女的图片"""
'''http://www.win4000.com/zt/meinv.html'''
'''引用了multiprocessing模块中的pool子块以创建进程池加快图片爬去的速度'''
'''开启多线程失败！！！'''

import requests
import re
from bs4 import BeautifulSoup


def get_reques_yemian(url):
    try:
        ted=requests.get(url)
        ted.raise_for_status()
        ted.encoding=ted.apparent_encoding
        return ted.text
    except:
        return None


def get_reques_tupian(url):
    try:
        ted=requests.get(url)
        ted.raise_for_status()
        ted.encoding=ted.apparent_encoding
        return ted.content
    except:
        return None


def tada_suoyin(htmlr):
    suoyinz=[]
    htmle=BeautifulSoup(htmlr,"html.parser")
    htmlr=(htmle.find_all('ul'))[2]
    for htmle in htmlr.find_all('li'):
        suoyin = {}
        suoyin['pm']=htmle.find('p').string
        suoyin['wz'] = (htmle.find('a')).attrs['href']
        suoyinz.append(suoyin)
    for i in range(24):
        tada_zutu(suoyinz[i])



def tada_zutu(suoyin):
    html=get_reques_yemian(suoyin['wz'])
    htmle=BeautifulSoup(html,'lxml')
    htmlr=(htmle.find_all('ul'))[3]
    tupian=[]
    for i in htmlr.find_all('img'):
        result=re.search(r'data-original="(.*)_120_80.jpg"',str(i))
        tupian.append(result.group(1)+'.jpg')
    tupian.append(' ')
    suoyin['tpwz']=tupian
    store_zutu(suoyin)

def store_zutu(zutuzd):
    path='E:\\爬虫数据库\\美桌网\\'
    count=0
    for i in zutuzd['tpwz']:
        if i==' ':
            break
        pathr=path+(zutuzd['pm'])+str(count)+'.jpg'
        print(i)
        html=get_reques_tupian(i)       #图片信息的二进制存储于html
        count+=1
        f=open(pathr,'wb')
        f.write(html)
        f.close()
        print((zutuzd['pm'])+str(count-1)+'下载完成')

def main(i):
    urlr="http://www.win4000.com/zt/meinv_"
    middle=".html"
    html=get_reques_yemian(urlr+str(i)+middle)
    tada_suoyin(html)


for t in range(1,6):
    main(t)


