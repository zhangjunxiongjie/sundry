# -*- coding: utf-8 -*-
import scrapy


class ZhihuUserSpider(scrapy.Spider):
    name = 'zhihu_user'
    allowed_domains = ['zhihu.com']
    start_urls = ['http://www.zhihu.com/']

    def parse(self, response):
        pass
