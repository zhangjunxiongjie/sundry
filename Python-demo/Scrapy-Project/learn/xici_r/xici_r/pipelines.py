# -*- coding: utf-8 -*-
# 使用mysql数据库存储数据
# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
import pymysql


class XiciRPipeline(object):

    def open_spider(self, spider):  # 在爬虫开启的时候仅执行一次
        spider.connection = pymysql.connect(    # 连接数据库
            host='localhost',
            port=3306,
            user='root',
            passwd='125908111',
            db='python',
            charset='utf8'
        )
        spider.cursor = spider.connection.cursor()  # 定义一个游标

    def close_spider(self, spider):  # 在爬虫关闭的时候仅执行一次

        spider.cursor.close()   # 关闭游标
        spider.connection.close()  # 关闭数据库连接

    def process_item(self, item, spider):

        sql = """INSERT INTO daili_2 VALUES("{0}", "{1}", {2}, "{3}", {4}, "{5}");""".format(item["ip"], item["port"], self.plus_address(item), item["test_date"], "NULL", item["agreement"])
        print(sql)
        spider.cursor.execute(sql)
        spider.connection.commit()

        return item

    def plus_address(self, item):
        if len(item["address"]) == 0:
            return "NULL"
        else:
            return '"{0}"'.format(item["address"][0])

