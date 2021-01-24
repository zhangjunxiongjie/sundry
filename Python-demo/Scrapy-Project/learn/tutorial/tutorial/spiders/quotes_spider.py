import scrapy
import logging

# 使输出日志能够标识出出错模块的位置
logger = logging.getLogger(__name__)  # 生成一个实例，传入当前模块文件名


class QuotesSpider(scrapy.Spider):
    name = "quotes"

    allowed_domains = ['itcast.cn']
    start_urls = ['http://www.itcast.cn/']

    def parse(self, response):
        for i in range(10):
            item = {"come_from": "itcast"}

            logger.warning(item)  # 日志模块

            yield item
