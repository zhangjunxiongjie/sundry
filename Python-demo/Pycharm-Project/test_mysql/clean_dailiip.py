# 建立ip代理池测试

import pymysql
import random
import requests

import pymysql  # 导入 pymysql

# 打开数据库连接
db = pymysql.connect(host="localhost", user="root", password="125908111", db="python", port=3306)

# 使用cursor()方法创建一个游标对象
cursor = db.cursor()

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.142 Safari/537.36"}

requests.adapters.DEFAULT_RETRIES = 3

for i in range(101, 6000):

    sql = "select * from daili_2".format(i)
    cursor.execute(sql)  # 使用execute()方法执行SQL语句
    find_result = cursor.fetchone()  # 取得一条数据

    poxy = find_result[-1].lower() + "://" + find_result[0] + ":" + str(find_result[1])
    print(poxy)

    # res = requests.get(url="http://icanhazip.com/", proxies={find_result[-1].lower(): poxy}, headers=headers)
    # print(res.text)

    try:
        res = requests.get(url="http://icanhazip.com/", timeout=8, proxies={find_result[-1].lower(): poxy}, headers=headers)
        proxyIP = res.text
        if proxyIP[:-1] == find_result[0]:
            print("代理IP:'" + proxyIP + "'有效！")
        else:
            sql = "delete from daili_2 where ip='{}';".format(find_result[0])
            cursor.execute(sql)
            db.commit()
            print("{0} + {1} + 代理IP无效！！".format(proxyIP[:-1], find_result[0]))
    except:
        sql = "delete from daili_2 where ip='{}';".format(find_result[0])
        cursor.execute(sql)
        db.commit()
        print("代理IP无效！！！")

# 关闭游标和数据库的连接
cursor.close()
db.close()
