# -*- coding: utf-8 -*-
import scrapy
import pymysql


class YgSpider(scrapy.Spider):
    name = 'yg'
    allowed_domains = ['www.win4000.com']
    start_urls = ['http://www.win4000.com/meinvtag4_1.html']



    def parse(self, response):
        xg_list = response.xpath("//div[@class='main']/div/div[3]/div[1]//ul/li")
        item = {}
        for xg in xg_list:
            item["title"] = xg.xpath('./a/p/text()').extract()
            item["url"] = xg.xpath('./a/@href').extract()

            '''
            with open("xg.txt","a+") as f:
                f.write(str(item))
                f.write("\n")
                f.close()
            '''


            # 存储到mysql
            connection = pymysql.connect(
                host='localhost',
                port=3306,
                user='root',
                passwd='125908111',
                db='python',
                charset='utf8'
            )
            cursor = connection.cursor()

            sql = """INSERT INTO meizhuo VALUES("{0}", "{1}", {2});""".format(item["title"][0], item["url"][0], "NULL")
            cursor.execute(sql)
            connection.commit()


            details_url = item["url"]
            # 通过meta参数将数据传入下一个解析函数（对网页进行解析的函数）
            yield scrapy.Request(details_url[0], callback=self.parse_details, meta={"item": item})  # 处理详情页

        cursor.close()
        connection.close()

        next_url = response.xpath('//div[@class="pages"]/div/a/@href').extract()[-1]  # 利用了scrapy默认不重复抓取页面的性质
        
        if next_url is not None:
            yield scrapy.Request(next_url, callback=self.parse)

    def parse_details(self, response):

        # item = response.meta["item"]

        connection = pymysql.connect(   # 链接数据库
            host='localhost',
            port=3306,
            user='root',
            passwd='125908111',
            db='python',
            charset='utf8'
        )
        cursor = connection.cursor()

        little_phooto = response.xpath('//div[@class="scroll-img-cont scroll-img-cont02"]/ul[@id="scroll"]/li')
        photo_title = response.xpath("//meta/@content").extract()[1]

        # 使用mysql查询数据，并使用查询到的数据
        sql = """select id from meizhuo where title="{0}";""".format(photo_title)
        print(photo_title)
        cursor.execute(sql)
        result = cursor.fetchone()
        ID = result[0]

        '''
        with open("xg.txt", "a+") as f:
            f.write(photo_title)
            f.write('\n')
            f.write("----------")
        '''

        for photo_table in little_phooto:
            photo_url = photo_table.xpath("./a/img/@data-original").extract()
            photo_url[0] = photo_url[0][:-12] + ".jpg"

            '''
            with open("xg.txt", "a+") as f:
            # f.write(str(item))
            f.write("\n")
            f.write(photo_url[0])
            f.close()
            '''

            # 存储到mysql

            sql = """INSERT INTO meizhuo_detail VALUES({0}, "{1}", {2});""".format(ID, photo_url[0], "NULL")
            cursor.execute(sql)
            connection.commit()

        cursor.close()
        connection.close()

        '''
        with open("xg.txt", "a+") as f:
            f.write("\n")
            f.write("----------")
            f.write("\n")
            f.close()
        '''
    #       yield scrapy.Request(photo, callback = self.parse_photo)

    # def parse_photo(self, response):
