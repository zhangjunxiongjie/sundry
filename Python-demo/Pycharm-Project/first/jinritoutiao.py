# 今日头条小 spider  网页变化导致程序失效。

import requests
import re
from urllib.parse import urlencode

from bs4 import BeautifulSoup

import json

'''爬取今日头条的街拍页面的图片'''
"""获取的页面编码上有点问题！！！"""
'''使用json库解析获取到的页面'''
'''未实现问题有点大！！！'''


def get_reques(off, key):
    data = {
        'offset': off,
        'format': 'json',
        'keyword': key,
        'autoload': 'true',
        'count': '20',
        'cur_tab': 1
    }
    url = 'https://www.toutiao.com/api/search/content/?' + urlencode(data)
    try:
        response = requests.get(url)
        if response.status_code == 200:
            response.encoding = 'unicode'
            return response.text
        return None
    except:
        print('请求错误！')
        return None


def geta_reques(html):
    data = json.loads(html)
    if data and 'data' in data.keys():
        for item in data.get('data'):
            yield item.get('article_url')


def get_reques_yemian(url):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            response.encoding = 'unicode'
            return response.text
        return None
    except:
        print('请求错误！', url)
        return None


def geta_yemian(html):
    soup = BeautifulSoup(html, 'lxml')
    title = soup.select('title')[0].get_text()
    images_pattern = re.compile('var gallery=(.*?);', re.S)
    result = re.search(images_pattern, html)
    if result:
        print(result.group(1))


def main():
    html = get_reques(0, '街拍')

    print(html)

    for url in geta_reques(html):
        print(url)
        html = get_reques_yemian(url)
        print(html)

        if html:
            geta_yemian(html)


main()
