# -*- coding: utf-8 -*-
"""
# 爬取豆瓣图书所有科技分类的图书
# scrapy教学笔记：http://www.helloxy123.site/index.html
# scrapy使用文档：https://docs.scrapy.org/en/latest/intro/overview.html
"""

import scrapy
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import CrawlSpider, Rule

class DbbookSpider(CrawlSpider):
    name = 'dbbook'
    allowed_domains = ['book.douban.com']
    start_urls = ['https://book.douban.com/tag/']

    tag = ['科普', '互联网',	'编程',	'科学', '交互设计', '用户体验', '算法', '科技', 'web', '交互', 'UE', '通信', 'UCD', '神经网络', '程序']

    rules = (
        Rule(LinkExtractor(allow=r'Items/'), callback='parse_item', follow=True),
    )

    def parse_item(self, response):
        item = {}
        #item['domain_id'] = response.xpath('//input[@id="sid"]/@value').get()
        #item['name'] = response.xpath('//div[@id="name"]').get()
        #item['description'] = response.xpath('//div[@id="description"]').get()
        return item
