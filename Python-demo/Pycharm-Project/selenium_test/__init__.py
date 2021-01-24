"""
中文文档：https://selenium-python-zh.readthedocs.io/en/latest/
selenium基本使用
"""

from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Firefox()   # 创建一个Firefox WebDriver的实例
driver.get("http://www.python.org")   # driver.get 方法将打开URL中填写的地址，WebDriver 将等待， 直到页面完全加载完毕（其实是等到”onload” 方法执行完毕）
assert "Python" in driver.title
elem = driver.find_element_by_name("q")   # 查找一个元素
elem.clear()            # 先清除input输入框中的任何预填充的文本（例如：”Search”）,从而避免我们的搜索结果受影响
elem.send_keys("pycon")
elem.send_keys(Keys.RETURN)
assert "No results found." not in driver.page_source
driver.close()  # 关闭浏览器窗口，你还可以使用quit方法代替close方法， quit将关闭整个浏览器，而_close——只会关闭一个标签页， 如果你只打开了一个标签页，大多数浏览器的默认行为是关闭浏览器。


'''
from selenium import webdriver
import time

browser = webdriver. Chrome()
browser.get('https://www.taobao.com')            # 请求网页
input = browser.find_element_by_id('q')         # 查找id = ‘q’的元素
input.send_keys('Phone')                  # 键入‘Phone’
time.sleep(1)                              # 延时
input.clear()                               # 清除元素的内容
input.send_keys('Pad')                    # 键入‘Pad’
button = browser.find_element_by_class_name('btn-search')   # 查找class = ‘btn-search’的元素
button. click()          # 点击按钮

'''
"""
import time
from selenium import webdriver  # 导入 webdriver 包

driver = webdriver.Firefox()  # 初始化一个火狐浏览器实例：driver

driver.get('https://www.baidu.com')  # 通过get的方式，打开百度的网址
driver.execute_script('window.open()')  # 执行脚本命令，打开一个新窗口
time.sleep(3)  # 进程挂起的时间 这里为程序运行等待3秒钟
driver.switch_to.window(driver.window_handles[1])  # 切换到新窗口
driver.get('https://www.baidu.com')  # 在新窗口打开百度的界面
time.sleep(3)  # 进程挂起的时间 这里为程序运行等待3秒钟
driver.switch_to.window(driver.window_handles[0])  # 创建一个句柄，进入第一个窗口
driver.get('https://www.zhihu.com')  # 在第一个窗口打开知乎的界面
time.sleep(3)  # 进程挂起的时间 这里为程序运行等待3秒钟

print(driver.page_source)         # 输出网页源码

driver.close()  # 关闭浏览器
driver.quit()    # 退出浏览器

"""
