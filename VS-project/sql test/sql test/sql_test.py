import pymssql #引入pymssql模块


def conn():
    
    connect = pymssql.connect('DESKTOP-2G3KR50', 'sa', '125908111', 'reptile')
 #   connect = pymssql.connect('localhost', 'sa', '125908111', 'reptile') #服务器名,账户,密码,数据库名
 #   connect = pymssql.connect(host="localhost",user="sa",password="125908111",database="reptile",charset="utf8")
    if connect:
        print("连接成功!")
    return connect


if __name__ == '__main__':
    conn = conn()