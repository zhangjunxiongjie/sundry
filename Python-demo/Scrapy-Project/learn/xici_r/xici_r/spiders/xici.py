# -*- coding: utf-8 -*-
import scrapy
# import os

class XiciSpider(scrapy.Spider):
    name = 'xici'
    allowed_domains = ['www.xicidaili.com']
    start_urls = ['https://www.xicidaili.com/nn//']

    def parse(self, response):

        print(response.meta["proxy"])

        table_list = response.xpath("//table[@id='ip_list']/tr")[1:]

        for ip_target in table_list:
            item = {}
            item["ip"] = ip_target.xpath('./td/text()').extract()[0]
            item["port"] = ip_target.xpath('./td/text()').extract()[1]
            item["address"] = ip_target.xpath('./td/a/text()').extract()
            item["test_date"] = ip_target.xpath('./td/text()').extract()[-1]
            item["agreement"] = ip_target.xpath('./td[6]/text()').extract()[0]
            yield item

        next = response.xpath('//div[@class="pagination"]/a[@class="next_page"]/@href').extract()

        next_url = "https://www.xicidaili.com" + str(next[0])
        print(next_url)

        '''
        if next_url is not None:
            yield scrapy.Request(next_url, callback=self.parse)
        '''