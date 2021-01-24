# -*- coding: utf-8 -*-
import scrapy


class XiciIpSpider(scrapy.Spider):
    name = 'xici_ip'  #爬虫名
    allowed_domains = ['itcast.cn'] #允许爬虫爬取的范围，此处为所爬取网站的根目录
    start_urls = ['http://www.itcast.cn/channel/teacher.shtml'] #最开始请求的url地址


    #处理start_url地址对应的响应

    def parse(self, response):
        #retl = response.xpath("//div[@class='tea_con']//h3/text()").extract()
        #print(retl)

        li_list = response.xpath("//div[@class='tea_con']//li")

        print(li_list)

        for li in li_list:
            item = {}
            item["name"] = li.xpath(".//h3/text()").extract_first()
            item["title"] = li.xpath(".//h4/text()").extract_first()

            #这里对迭代器的返回值是由要求的并不能够返回一个列表
            yield item   #将此方法变为一个迭代器，使数据能够流入pipeline组件，这里变量名字并不固定可以任意