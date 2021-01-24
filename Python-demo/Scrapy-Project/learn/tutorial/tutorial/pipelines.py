# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html

import logging
logger = logging.getLogger(__name__)


class TutorialPipeline(object):
    def process_item(self, item, spider):
        if spider.name == "quotes":
            logger.warning("-" * 10)

        return item
