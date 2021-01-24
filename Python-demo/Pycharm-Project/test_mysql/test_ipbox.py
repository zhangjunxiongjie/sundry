import json
import telnetlib
import requests
import random

proxy_url = 'https://raw.githubusercontent.com/fate0/proxylist/master/proxy.list'

import pymysql  # 导入 pymysql

# 打开数据库连接
# db = pymysql.connect(host="localhost", user="root", password="125908111", db="python", port=3306)

# 使用cursor()方法创建一个游标对象
# cursor = db.cursor()

# proxyList = []

def verify(ip, port, type):
    proxies = {}
    try:
        telnet = telnetlib.Telnet(ip, port=port, timeout=3)
    except:
        print('unconnected')
    else:
        # print('connected successfully')
        # proxyList.append((ip + ':' + str(port),type))
        proxies['type'] = type
        proxies['host'] = ip
        proxies['port'] = port
        # proxiesJson = json.dumps(proxies)
        print('type:{0}, host:{1}, port:{2}'.format(proxies['type'], proxies['host'], proxies['port']))
        # sql = "INSERT INTO daili_3 VALUES('{0}', '{1}', '{2}', {3});".format(ip, port, type, "NULL")
        # print(sql)
        # cursor.execute(sql)
        # db.commit()

        '''
        with open('verified_proxies.json', 'a+') as f:
            f.write(proxiesJson + '\n')
        print("已写入：%s" % proxies)
        '''

def getProxy(proxy_url):
    response = requests.get(proxy_url)
    proxies_list = response.text.split('\n')  # 以'\n'字符为分界对字符串进行切割
    for proxy_str in proxies_list:
        proxy_json = json.loads(proxy_str)
        host = proxy_json['host']
        port = proxy_json['port']
        type = proxy_json['type']
        verify(host, port, type)

    # 关闭游标和数据库的连接
    # cursor.close()
    # db.close()


if __name__ == '__main__':
    getProxy(proxy_url)
