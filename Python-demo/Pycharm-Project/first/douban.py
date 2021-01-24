# 对豆瓣电影（https://movie.douban.com/top250?start=0）top250的电影进行爬取收集电影海报信息
# 对异常的判断及处理


import requests
import re
from bs4 import BeautifulSoup


def Requested_page(url):  # 请求页面信息
    try:
        ted = requests.get(url)
        ted.raise_for_status()  #
        ted.encoding = ted.apparent_encoding  # 推测页面编码并更改对其解码方式
        return ted.text
    except:
        return None


def Requested_picture(url):  # 请求图片信息并保存
    try:
        ted = requests.get(url)
        ted.raise_for_status()
        ted.encoding = ted.apparent_encoding
        return ted.content
    except:
        return None


def Parsing_page(text):  # 对页面进行解析提取电影名及图片地址
    textr = BeautifulSoup(text, 'lxml')
    textf = textr.find('ol')

    grt = {}  # 存储电影名及图片url的字典

    for it in textf.find_all('img'):
        result = re.search(r'alt="(.*)" class="" src="(.*)s_ratio_poster(.*)" ', str(it))
        reurl = result.group(2) + 'l' + result.group(3)
        rename = result.group(1)
        grt[rename] = reurl
    return grt


def Combination_operation(group, path):  # 传入解析得到的电影名及电影海报地址//字典形式存储以电影名为键以图片网址为值，请求图片信息并保存
    for it in group:
        pat = it + '.jpg'
        pathr = path + pat
        print(pat, end=" ")  # end参数可以使两个print在同一行输出
        html = Requested_picture(group[it])
        if html == None:
            print("图片请求失败！")
        else:
            f = open(pathr, 'wb')
            f.write(html)
            f.close()
            print("保存成功！")


def Main():
    HTML = 'https://movie.douban.com/top250?start='
    Path = 'E:\\爬虫数据库\\豆瓣电影\\'
    for i in range(0, 251, 25):
        HTMLr = HTML + str(i)
        Details = Requested_page(HTMLr)
        if Details == None:
            print(str(i) + "页面请求失败！")
        else:
            Group = Parsing_page(Details)
            Combination_operation(Group, Path)


Main()
