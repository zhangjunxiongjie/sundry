# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html

import re  # 正则模块
import pymysql


class YangguangRPipeline(object):
    def process_item(self, item, spider):  # 对提取到的数据做最后的处理

        item["content"] = self.process_content(item["content"])

        '''
        connection = pymysql.connect(
            host='localhost',
            port=3306,
            user='root',
            passwd='125908111',
            db='test',
            charset='utf8'
        )
        cursor = connection.cursor()
        #  for record in item:
        sql = """INSERT INTO ygwz VALUES("{0}", "{1}", "{2}", "{3}", "{4}", {5});""".format(item["title"],
                                                                                            item["href"],
                                                                                            item["publish_date"],
                                                                                            item["content_img"],
                                                                                            item["content"],
                                                                                            "NULL")
        print(sql)
        cursor.execute(sql)
        connection.commit()
        cursor.close()
        connection.close()
        '''

        with open("ygwz.txt", "a+") as f:
            f.write(str(item).replace(u'\u261e', u''))
            f.write("\n")
            f.write("----------")
            f.write("\n")
            f.close()

        # print(item)


        return item  # 这里返回一个item是为了便于后续process_item方法的处理，即当存在多个处理方法时可使用这个返回值在方法间传递数据

    def process_content(self, content):
        content = [re.sub(r"\xa0|\s", "", i) for i in content]  # 使用正则模块的方法sub，使用""替换匹配到的字符串
        content = [i for i in content if len(i) > 0]  # 去除空字符串
        content = content[:-6]  # 去除最后三个字符串
        return content
