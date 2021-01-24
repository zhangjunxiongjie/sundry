# -*- coding: utf-8 -*-

# Define here the models for your spider middleware
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/spider-middleware.html
"""
始终无法实现随机代理即使代理经过测试能够通过交给download模块依然等待良久仍无结果，甚是无奈！
另严格的代理测试仅少有通过，问题稍多
主要的问题是：代理的测试以及通过测试的代理依然不能很好地使用。
这写问题先暂且搁置在此
"""

from scrapy import signals
import random  # python随机数模块
import requests  # 用于判断代理ip是否可用
import json
import telnetlib


class XiciRSpiderMiddleware(object):
    # Not all methods need to be defined. If a method is not defined,
    # scrapy acts as if the spider middleware does not modify the
    # passed objects.

    @classmethod
    def from_crawler(cls, crawler):
        # This method is used by Scrapy to create your spiders.
        s = cls()
        crawler.signals.connect(s.spider_opened, signal=signals.spider_opened)
        return s

    def process_spider_input(self, response, spider):
        # Called for each response that goes through the spider
        # middleware and into the spider.

        # Should return None or raise an exception.
        return None

    def process_spider_output(self, response, result, spider):
        # Called with the results returned from the Spider, after
        # it has processed the response.

        # Must return an iterable of Request, dict or Item objects.
        for i in result:
            yield i

    def process_spider_exception(self, response, exception, spider):
        # Called when a spider or process_spider_input() method
        # (from other spider middleware) raises an exception.

        # Should return either None or an iterable of Response, dict
        # or Item objects.
        pass

    def process_start_requests(self, start_requests, spider):
        # Called with the start requests of the spider, and works
        # similarly to the process_spider_output() method, except
        # that it doesn’t have a response associated.

        # Must return only requests (not items).
        for r in start_requests:
            yield r

    def spider_opened(self, spider):
        spider.logger.info('Spider opened: %s' % spider.name)


class XiciRDownloaderMiddleware(object):
    # Not all methods need to be defined. If a method is not defined,
    # scrapy acts as if the downloader middleware does not modify the
    # passed objects.

    @classmethod
    def from_crawler(cls, crawler):
        # This method is used by Scrapy to create your spiders.
        s = cls()
        crawler.signals.connect(s.spider_opened, signal=signals.spider_opened)
        return s

    def porxy(self):    # 生成可用的随机代理
        proxy_url = 'https://raw.githubusercontent.com/fate0/proxylist/master/proxy.list'
        response = requests.get(proxy_url)
        proxies_list = response.text.split('\n')  # 以'\n'字符为分界对字符串进行切割
        while True:
            proxy_str = random.choice(proxies_list)
            proxy_json = json.loads(proxy_str)
            host = proxy_json['host']
            port = proxy_json['port']
            type = proxy_json['type']
            proxy = type + '://' + host + ':' + str(port)
            print(proxy)
            try:
                requests.adapters.DEFAULT_RETRIES = 3
                headers = {
                    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.142 Safari/537.36"}
                res = requests.get(url="http://icanhazip.com/", timeout=8, proxies={host: proxy},
                                   headers=headers)
                proxyIP = res.text
                if proxyIP[:-1] == host:
                    print("代理IP:'" + proxyIP + "'有效！")
                    return proxy
                else:
                    return proxy
                    with open("ip.txt", "a+") as f:
                        f.write("{0} --- {1} -- 代理IP无效！！\n".format(proxyIP[:-1], host))
                    # print("{0} --- {1} -- 代理IP无效！！".format(proxyIP[:-1], host))
            except:
                print("{0}代理IP无效！！！".format(host))


    def process_request(self, request, spider):
        # self.porxy()
        request.meta['proxy'] = self.porxy()   # 设置随机代理

        # Called for each request that goes through the downloader
        # middleware.

        # Must either:
        # - return None: continue processing this request
        # - or return a Response object
        # - or return a Request object
        # - or raise IgnoreRequest: process_exception() methods of
        #   installed downloader middleware will be called
        return None

    def process_response(self, request, response, spider):
        # Called with the response returned from the downloader.

        # Must either;
        # - return a Response object
        # - return a Request object
        # - or raise IgnoreRequest
        return response

    def process_exception(self, request, exception, spider):
        # Called when a download handler or a process_request()
        # (from other downloader middleware) raises an exception.

        # Must either:
        # - return None: continue processing this exception
        # - return a Response object: stops process_exception() chain
        # - return a Request object: stops process_exception() chain
        pass

    def spider_opened(self, spider):
        spider.logger.info('Spider opened: %s' % spider.name)
