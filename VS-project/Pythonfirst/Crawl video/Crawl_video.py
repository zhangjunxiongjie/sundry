#Crawl video
#爬取https://m.feilaotv.com/lunli/ URL的电影图片信息（以电影名作为每张图片的存储名称）
#出现的问题：不能完整提取到所有电影名和其对应的图片地址有部分被过滤掉了
#可能的原因：使用的对图片地址和电影名的筛选方法即正则表达式可能有问题，或者其他的筛选部分

import requests
from bs4 import BeautifulSoup
import re

def grab(url):   #抓取网页信息
    try:
        te=requests.get(url,timeout=30)
        te.raise_for_status() 
        te.encoding= te.apparent_encoding 
        return te.text
    except:
        return " "

def analysis(r,ra):         #对网页进行信息提取，提取电影名称和图片地址,xii是一个字典类型储存电影名对应的图片地址
    html=BeautifulSoup(r, 'html.parser') 
   # print(html)
    message=html.find_all('img')

    for i in message:
       try:
           alt = i.attrs['alt']          #检索标签属性href的值
           src = i.attrs['src']          #检索标签属性href的值
           site=(re.findall(r"^https://pic.feilaotv.com/pic/uploadimg/\d{4}-\d\d?/\d{15,19}.jpg$", src)[0])   #用正则表达式提取属性href值中的股票代码部分//“【0】”？？？
           name=(re.findall(r".*", alt)[0])   #用正则表达式提取属性href值中的股票代码部分//“【0】”？？？
           ra[name]=site
       except:
           continue
   


def storage(ra,path):  #传入电影名称和图片地址信息，存储路径
    for name in ra:
        pathzj=path+name+".jpg"
        fp = open(pathzj, 'wb')
        pic=requests.get(ra[name])
        fp.write(pic.content)      #向文件写入图片信息
        fp.close()


def main():
    count=11   #给一个抓取页面数量
    te=""   #存储抓取到的网页页面信息
    xii={}  #存储电影名即对应的封面图片地址
    url="https://m.feilaotv.com/lunli/index"
    get=".html"
    for i in range(1,count+1):
        if i==1 :
            urlr=url+get
        else :
            urlr=url+str(i)+get
        if grab(urlr)==" ":
            continue
        else :
            analysis(grab(urlr),xii)
    path="E:\\pachong\\"
    storage(xii,path)
    print(xii)
    print("{}".format(len(xii)))

main()