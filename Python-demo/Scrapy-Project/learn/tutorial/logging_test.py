# coding = utf-8

# logging模块的基本使用

import logging  # python的日志模块

# 对输出的日志格式进行配置
logger = logging.getLogger(__name__)
LOG_FORMAT = "%(asctime)s %(name)s %(levelname)s %(pathname)s %(message)s "  # 配置输出日志格式
DATE_FORMAT = '%Y-%m-%d  %H:%M:%S %a '  # 配置输出时间的格式，注意月份和天数不要搞乱了
logging.basicConfig(
    level=logging.DEBUG,
    format=LOG_FORMAT,
    datefmt=DATE_FORMAT,
    filename=r".\test.log"  # 有了filename参数就不会直接输出显示到控制台，而是直接写入文件
)

logger.debug("msg1")
logger.info("msg2")
logger.warning("msg3")
logger.error("msg4")
logger.critical("msg5")
