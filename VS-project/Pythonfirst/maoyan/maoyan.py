#抓取猫眼网票房top100

import requests
from bs4 import BeautifulSoup
import re

def get_request(url):
    try:
        mid={'user-agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.110 Safari/537.36'}
        qe=requests.get(url,timeout=30,headers=mid)
        qe.raise_for_status()
        qe.encoding=qe.apparent_encoding
        return qe.text 
    except:
        return " "

def analysis_response(html,middle):
    sum=BeautifulSoup(html, 'html.parser')
    te=sum.find_all("dd")
    for it in te:
        fie={}
        fie['排名']=(it.find_all("i"))[0].string
        fie['图片地址']=(str(re.findall(r"http.*\.jpg",str((it.find_all('img'))[1]))))[2:-2]
        fie['电影名']=(it.find_all("p"))[0].string
        fie['主演']=((it.find_all("p"))[1].string)[20:-9]
        fie['评分']=(it.find_all("i"))[1].string+(it.find_all("i"))[2].string
        fie['上映时间']=((it.find_all("p"))[2].string)[5:]
        middle.append(fie)
        
def save_data(path,result):
    f=open(path, 'a+', encoding='utf-8')
    for i in result:
        f.write( str(i) + '\n' )
    f.close()
        
def main():
    urlr="https://maoyan.com/board/4?offset="
    path="E:\\爬虫数据库\\maoyan.txt"
    for i in range(10):
        middle=[]
        url=urlr+str(i*10)
        html=get_request(url)
        if html==' ':
            print("未收到响应！")
            return 0
        analysis_response(html,middle)
        save_data(path,middle)
main()