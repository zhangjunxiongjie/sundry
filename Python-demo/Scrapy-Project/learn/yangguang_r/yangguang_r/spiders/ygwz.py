# -*- coding: utf-8 -*-

# 学习使用item组件

import scrapy
# from yangguang_r.items import YangguangRItem    # 引入item模块


class YgwzSpider(scrapy.Spider):
    name = 'ygwz'
    allowed_domains = ['wz.sun0769.com']
    start_urls = ['http://wz.sun0769.com/index.php/question/questionType?type=4&page=0']  # 起始爬取地址

    def parse(self, response):

        tr_list = response.xpath("//div[@class='greyframe']/table[2]/tr/td/table/tr")  # 取出一个列表

        for tr in tr_list:
            item = {}   # 这里直接将item传给request方法的meta参数效果并没有太大区别，同样可以，唯一不同的可能就是数据类型不通
            # 下面这种方法在写入文件时每一行（键值）都要换行而上面这个则不会转化为字符串后直接在一行输出
            # item = YangguangRItem()  # 定义一个item实例，使这一个方法处理得到的数据能够通过scrapy的request方法的meta参数流入下一个处理方法（解析函数）

            item["title"] = tr.xpath("./td[2]/a[@class='news14']/@title").extract_first()
            item["href"] = tr.xpath("./td[2]/a[@class='news14']/@href").extract_first()
            item["publish_date"] = tr.xpath("./td[last()]/text()").extract_first()

            yield scrapy.Request(item["href"], callback=self.parse_detail, meta={"item": item})   # 定义一个生成器使爬虫能够继续获取页面处理详情页


        # 获取下一页的链接处理下一页的数据
        next_url = response.xpath("//a[text()='>']/@href").extract_first()  # 得到下一页url，此处使用了一个过滤语句即过滤出标签内容为'>'字符的a标签
        if next_url is not None:
            yield scrapy.Request(next_url, callback=self.parse)


    def parse_detail(self, response):  # 处理详情页
        item = response.meta["item"]
        item["content"] = response.xpath("//td[@class='txt16_3']//text()").extract()  # 获取详情内容，这里使用.extract()方法可以获取匹配表欠下的所有内容，如果只获取第一个内容应该使用.extract_first()

        item["content_img"] = response.xpath("//td[@class='txt16_3']//img/@src").extract()  # 获取详情页的图片链接
        item["content_img"] = ["http://wz.sun0769.com" + i for i in item["content_img"]]  # 对图片连接进行处理
        yield item       # 通过生成器将数据传入pipeline
