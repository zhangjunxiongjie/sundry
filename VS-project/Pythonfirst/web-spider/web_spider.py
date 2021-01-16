#CrawUnivRankingA.py
#定向网络爬虫，爬取大学排名信息并对信息进行提取

import requests   #引入向URL发送请求并爬取页面的库
from bs4 import BeautifulSoup  #引入一个解析网页内容的模块
import bs4   #
 
def getHTMLText(url):       #发送请求并获取内容
    try:                                #捕获异常
        r = requests.get(url, timeout=30)    #timeout参数给定响应时间
        r.raise_for_status()      #判断发送请求获取内容是否成功，不成功则发出异常
        r.encoding = r.apparent_encoding            #更改读取网页的编码，采用经过库文件分析的编码而非原网页给出的不确定编码
        return r.text              #返回网页解码的完整内容
    except:
        return ""
 
def fillUnivList(ulist, html):    #对完整的网页内容进行信息提取
    soup = BeautifulSoup(html, "html.parser")     #对网页内容进行网页源码还原，“html.parser”是还原方式，有四种还原方式，对应三种网页标记方式
    for tr in soup.find('tbody').children:     #查找其中的‘tbody’标签的子节点并对其进行遍历
        if isinstance(tr, bs4.element.Tag):    #判断其子节点是否是“bs4.element.Tag”类型（bs4中的标签类型）是则继续
            tds = tr('td')     #在其子节点中查找td标签并返回给tds，返回多个内容tds是一种组合数据类型
            ulist.append([tds[0].string, tds[1].string,tds[2].string,tds[3].string])    #把前几个tds标签中的字符串加到uilst列表中
 
#def printUnivList(ulist, num):   输出时对齐出现问题原因在于中西文字符占用字符空间不同，输出中文字符时未占满部分默认使用了西文空格字符填充
#   print("{:^10}\t{:^20}\t{:^10}\t{:^10}".format("排名","学校名称","地区","总分"))  #中英文混合输出时两者占用字符空间不同都会导致对齐不工整的问题
#   for i in range(num):    解决中英文字符混合输出对齐不工整的问题可以使用以下方法即：输出中文时用中文空格字符（chr（12288））填充，输出英文字符或者数字时用英文字符填充
#       u=ulist[i]
#       print("{:^10}\t{:^20}\t{:^10}\t{:^10}".format(u[0],u[1],u[2],u[3]))

def printUnivList(ulist, num):   #使用中文空格字符填充未占满部分可以解决这个问题
    tplt="{0:^10}\t{1:{4}^10}\t{2:^10}\t{3:^5}"     #设置槽字符串，其中第二个大括号中的大括号表示把第四个参数作为其填充部分
    print(tplt.format("排名","学校名称","地区","总分",chr(12288)))    
    for i in range(num):   #遍历前num个大学并输出
        u=ulist[i]
        print(tplt.format(u[0],u[1],u[2],u[3],chr(12288)))   
  

def main():
    uinfo = []     #存取每个大学的信息，单个大学的信息存取在一个列表中，与所有大学信息形成二维数据
    url = 'http://www.zuihaodaxue.cn/zuihaodaxuepaiming2018.html'   #爬取URL
    html = getHTMLText(url)
    if html=='':
        print("获取页面失败！！！")
        return 0
    fillUnivList(uinfo, html)
    printUnivList(uinfo, 20) # 20 univs
main()