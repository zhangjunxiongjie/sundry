# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class YangguangRItem(scrapy.Item):
    # define the fields for your item here like:
    title = scrapy.Field()   # 使数据能够在多个parse之间流动
    href = scrapy.Field()
    publish_date = scrapy.Field()
    content_img = scrapy.Field()
    content = scrapy.Field()

    pass
