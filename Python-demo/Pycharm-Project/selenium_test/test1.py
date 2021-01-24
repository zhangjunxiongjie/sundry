# coding=gbk     # 给程序设定编码
"""
暂时放弃qq空间爬取项目遇到的问题：
1. 使用selenium对浏览器进行控制拿到网页真实html过程中要等待！！！QQ空间本身JavaScript请求就比较多，大多都是XHR异步请求，要想获得完整真实的html就必须等待
而且等待的时间一点都不短，这个无关乎网络，因为QQ空间的异步请求实在太多，当然可以采取多线程多进程的方法，但是我还不会！
2. 加载到主页后有一个弹窗！必须要点击一下，才能真正的进入（操作）主页，可是这个按钮不知道咋回事点击不了？或者说根本找不到。另外也可能是要执行一个JavaScript程序
3. 即使进入相册获取到完整的图片依然不容易，比如通过相册并不能直接获取到完整的图片只能得到缩略图的url而且似乎两者的url毫无关联，其次部分相册内容并不是图片而是是视屏，
然后就是图片页的加载也要执行若干个JavaScript程序才能将一页的完整图片加载出来，另外转至下一页也必须要执行JavaScript程序！！！烦躁
理一下：登录之后加载要爬取的主页url然后执行JavaScript程序关闭一个弹窗，然后点击相册按钮（要查找，这里对于不同人的主页其相册按钮的查找方式不同，另外可以通过执行一个JavaScript程序实现，但是是否通用未知）
进入相册页面就要点击各个相册的进行抓取（首先部分相册设置了密码需要处理弹窗，其次即使进入相册页还要分析照片的url以方便得到完整图片的URL），然后翻页同样要执行JavaScript，直到翻到最后一页然后可以通过点击
最上面的相册回到相册主页，然后点击下一个相册。（由图片页的图片地址得到完整图片地址的问题已经解决，其实就是一个参数变了）
最主要的问题有：太慢，需要执行JavaScript（主页弹窗，图片页下滑（下滑过程还得设置等待，因为得加载图片），以及图片页翻页）。
http://b126.photo.store.qq.com/psb?/V11lFE0m0PAKY4/9iIk6mylvKLf8nK7s.c1iDQm7HO17UKlruIRfWIVuTY!/b/dDC5IUthIgAAnull&bo=IANYAgAAAAABA10!&rf=photolist&t=5
http://b126.photo.store.qq.com/psb?/V11lFE0m0PAKY4/9iIk6mylvKLf8nK7s.c1iDQm7HO17UKlruIRfWIVuTY!/m/dDC5IUthIgAAnull&bo=IANYAgAAAAABA10!&rf=photolist&t=5

JavaScript的执行以及等待加载时间过长依然是一个问题。
"""

from selenium import webdriver
import time
# from bs4 import BeautifulSoup


def login_request(url, browser):  # 登录获取cookie

    browser.get(url)   # 请求登录的url
    button = browser.find_element_by_id("img_out_3435191864")   # 查找登录按钮（此处将本地qq挂载上这里查找快速登录按钮）
    button.click()      # 点击按钮
    time.sleep(5)        # 等待加载

    '''
    with open("qq.html", "w", encoding="utf-8") as f:
        f.write(browser.page_source)
        f.close()
    '''


def page_request(url, browser):    # 获取主页页面
    browser.get(url)      # 请求空间主页的html，要注意的是，这一步之前必须要进行登录获取cookie，这里才能请求到实际的网页
    time.sleep(5)
    with open("qq.html", "w", encoding="utf-8") as f:
        f.write(browser.page_source)
        f.close()

    return browser.page_source


def main():

    # 登录使用的URL
    # 分析qq空间登录网页可以得到这个真正的登录入口，每&符号隔开一个参数
    login_url = u'https://xui.ptlogin2.qq.com/cgi-bin/xlogin?proxy_url=https%3A//qzs.qq.com/qzone/v6/portal/proxy.html&daid=5&&hide_title_bar=1&low_login=0&qlogin_auto_login=1&no_verifyimg=1&link_target=blank&appid=549000912&style=22&target=self&s_url=https%3A%2F%2Fqzs.qzone.qq.com%2Fqzone%2Fv5%2Floginsucc.html%3Fpara%3Dizone&pt_qr_app=%E6%89%8B%E6%9C%BAQQ%E7%A9%BA%E9%97%B4&pt_qr_link=http%3A//z.qzone.com/download.html&self_regurl=https%3A//qzs.qq.com/qzone/v6/reg/index.html&pt_qr_help_link=http%3A//z.qzone.com/download.html&pt_no_auth=1'

    # 要请求的空间主页的url列表
    page_url = ["https://user.qzone.qq.com/136221675"]

    # 定义一个浏览器实例
    browser = webdriver.Chrome()
    # 进行登录获取cookie
    login_request(login_url, browser)
    # 对要请求的空间主页url列表进行请求解析
    for url in page_url:
        page_source = page_request(url, browser)   # 请求主页

        button = browser.find_element_by_class_name("m")  # 查找按钮
        button.click()

        time.sleep(10)

        button = browser.find_element_by_id("QM_Profile_Photo_A")  # 寻找按钮
        button.click()  # 点击按钮

        time.sleep(5)

        with open("qq1.html", "w", encoding="utf-8") as f:
            f.write(browser.page_source)
            f.close()

    browser.close()   # 关闭标签页
    browser.quit()  # 关闭浏览器


if __name__ == '__main__':
    main()
