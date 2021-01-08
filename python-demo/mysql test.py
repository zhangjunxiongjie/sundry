# 数据库测试
import pymysql

# 打开数据库连接
db = pymysql.connect(host='localhost', port=3306, user='root', passwd='125908111', db='python', charset='utf8')

# 使用cursor()方法获取操作游标
cursor = db.cursor()

# SQL 查询语句
sql = "select id from meizhuo where title='zhang';"
try:
    # 执行SQL语句
    cursor.execute(sql)
    # print(cursor.rownumber)
    result = cursor.fetchone()
    while result is not None:
        print(result[0], cursor.rownumber)
        result = cursor.fetchone()
    '''
    result = cursor.fetchone()
    print(result, cursor.rownumber)
    result = cursor.fetchone()
    print(result, cursor.rownumber)
    '''
except:
    print("Error: unable to fetch data")

# 关闭数据库连接
db.close()

'''
import pymysql

connection = pymysql.connect(
                                host='localhost',
                                port=3306,
                                user='root',
                                passwd='125908111',
                                db='python',
                                charset='utf8'
                            )

cursor = connection.cursor()

josn = cursor.execute('select * from meizhuo;')
for data in josn:
    print(data)
cursor.close()
connection.close()
'''
