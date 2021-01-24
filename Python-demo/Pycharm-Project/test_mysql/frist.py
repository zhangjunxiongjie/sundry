import pymysql  # 导入 pymysql

 #打开数据库连接
db = pymysql.connect(host="localhost", user="root",password="125908111", db="python", port=3306)

#使用cursor()方法创建一个游标对象
cursor = db.cursor()

#使用execute()方法执行SQL语句
cursor.execute("SELECT * FROM userinfo")

#使用fetall()获取全部数据
data = cursor.fetchall()

#打印获取到的数据
print(data)

#关闭游标和数据库的连接
cursor.close()
db.close()
