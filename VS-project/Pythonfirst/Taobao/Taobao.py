#CrowTaobaoPrice.py
#淘宝页面爬取
#
import requests    #引入发送请求爬取页面的模块
import re           #引入正则表达式库以提取网页中有用的信息
#正则表达式是字符串的搜索/查找/检索并提取符合内容的方法，是字符串信息提取检索的终极方法 
#而bs4中的BeautifulSoup模块只是针对网页内容利用网页标签提取内容的一个方法因为网页内容获取下来是以字符串方式存储所以
#BeautifulSoup模块能够解析（提取网页内容）的网页正则表达式均力所能及。
#利用好正则表达式可以很好的对请求到的网页内容进行信息提取和对字符串进行处理

def getHTMLText(url):
    try:
        kev={'user-agent':'Mozilla/5.0'}    #增加此参数可以使requests的get方法模拟浏览器访问页面以破解部分浏览器对爬虫的拒绝访问
        r = requests.get(url, timeout=30,headers=kev)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""
     
def parsePage(ilt, html):
    try:
        plt = re.findall(r'\"view_price\"\:\"[\d\.]*\"',html)   #用正则表达式提取商品价格信息
        tlt = re.findall(r'\"raw_title\"\:\".*?\"',html)    #用正则表达式提取商品名称信息
        for i in range(len(plt)):
            price = eval(plt[i].split(':')[1])   #提取单个商品价格中以冒号分隔的第二个元素
            title = eval(tlt[i].split(':')[1])  #将键值对中的值提取出来
            ilt.append([price , title])   #价格和名称组成一个列表类型放入lit这个列表中
    except:
        print("")
 
def printGoodsList(ilt):
    tplt = "{:4}\t{:8}\t{:16}"
    print(tplt.format("序号", "价格", "商品名称"))
    count = 0
    for g in ilt:
        count = count + 1
        print(tplt.format(count, g[0], g[1]))
         
def main():
    goods = '书包'
    depth = 3
    start_url = 'https://s.taobao.com/search?q=' + goods
    infoList = []
    for i in range(depth):
        try:
            url = start_url + '&s=' + str(44*i)
            html = getHTMLText(url)
            parsePage(infoList, html)
        except:
            continue    
    printGoodsList(infoList)

main()
