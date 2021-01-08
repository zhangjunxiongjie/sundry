#CrawBaiduStocksB.py
#在http://quote.eastmoney.com/stocklist.html站提取上交和深交的股票代码
#在https://gupiao.baidu.com/stock/站提取每个代码对应的完整股票信息
#

import requests
from bs4 import BeautifulSoup
import traceback
import re
 
def getHTMLText(url, code="utf-8"):             #向网页发送请求并获取网页内容
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = code    #因为此程序是一个定向程序并不爬取很多编码各不相同的网页故不再利用库函数对网页内容进行分析以获取其编码形式
        return r.text       #以提高爬取速度
    except:
        return ""
 
def getStockList(lst, stockURL):     #获取股票代码信息
    html = getHTMLText(stockURL, "GB2312")              #调用getHTMLText函数获取网页页面信息
    soup = BeautifulSoup(html, 'html.parser')            #用解码模块对网页内容进行解码
    a = soup.find_all('a')              #查找其中的a标签的字符串存储于列表a中（使用到了bs4中的BeautifulSoup模块的一些对象操作方法）
    for i in a:
        try:
            href = i.attrs['href']          #检索标签属性href的值
            lst.append(re.findall(r"[s][hz]\d{6}", href)[0])   #用正则表达式提取属性href值中的股票代码部分//“【0】”？？？
        except:
            continue
 
def getStockInfo(lst, stockURL, fpath):             #获取股票名称等完整信息，获得参数：股票代码信息，获取股票完整信息的url，存取信息的路径
    count = 0   
    for stock in lst:               #对股票代码信息进行遍历，每次通过获得的股票代码在url中搜索股票代码对应的完整信息
        url = stockURL + stock + ".html"                   #
        html = getHTMLText(url)                     #获取股票代码对应的股票网页信息
        try:
            if html=="":                        #如果获取到的网页信息为空则跳过本次
                continue
            infoDict = {}   #创建一个字典类型
            soup = BeautifulSoup(html, 'html.parser')           #对网页内容进行解码
            stockInfo = soup.find('div',attrs={'class':'stock-bets'})  #查找解码后网页中的div标签中属性class为stock-bets的项
 
            name = stockInfo.find_all(attrs={'class':'bets-name'})[0]   #获取股票名称
            infoDict.update({'股票名称': name.text.split()[0]})   #加入到股票完整信息字典中，每一项对应一个股票属性
             
            keyList = stockInfo.find_all('dt')    #dt标签中放着股票的属性
            valueList = stockInfo.find_all('dd')        #dd标签中放着股票的属性值，以列表显示返回
            for i in range(len(keyList)):
                key = keyList[i].text          #
                val = valueList[i].text     #
                infoDict[key] = val         #将每一个属性和其对应的值加入到股票完整信息字典中
             
            with open(fpath, 'a', encoding='utf-8') as f:   #以写模式utf-8编码模式打开文件，并对文件起别名
                f.write( str(infoDict) + '\n' )     #将字典中对应的完整的股票信息存储到文件中
                count = count + 1
                print("\r当前进度: {:.2f}%".format(count*100/len(lst)),end="")
        except:
            count = count + 1
            print("\r当前进度: {:.2f}%".format(count*100/len(lst)),end="")
            continue
 
def main():
    stock_list_url = 'http://quote.eastmoney.com/stocklist.html'
    stock_info_url = 'https://gupiao.baidu.com/stock/'
    output_file = 'D:/BaiduStockInfo.txt'
    slist=[]
    getStockList(slist, stock_list_url)
    getStockInfo(slist, stock_info_url, output_file)
 
main()
