# coding=gbk     # �������趨����
"""
��ʱ����qq�ռ���ȡ��Ŀ���������⣺
1. ʹ��selenium����������п����õ���ҳ��ʵhtml������Ҫ�ȴ�������QQ�ռ䱾��JavaScript����ͱȽ϶࣬��඼��XHR�첽����Ҫ����������ʵ��html�ͱ���ȴ�
���ҵȴ���ʱ��һ�㶼���̣�����޹غ����磬��ΪQQ�ռ���첽����ʵ��̫�࣬��Ȼ���Բ�ȡ���̶߳���̵ķ����������һ����ᣡ
2. ���ص���ҳ����һ������������Ҫ���һ�£����������Ľ��루��������ҳ�����������ť��֪��զ���µ�����ˣ�����˵�����Ҳ���������Ҳ������Ҫִ��һ��JavaScript����
3. ��ʹ��������ȡ��������ͼƬ��Ȼ�����ף�����ͨ����Ტ����ֱ�ӻ�ȡ��������ͼƬֻ�ܵõ�����ͼ��url�����ƺ����ߵ�url���޹�������β���������ݲ�����ͼƬ������������
Ȼ�����ͼƬҳ�ļ���ҲҪִ�����ɸ�JavaScript������ܽ�һҳ������ͼƬ���س���������ת����һҳҲ����Ҫִ��JavaScript���򣡣�������
��һ�£���¼֮�����Ҫ��ȡ����ҳurlȻ��ִ��JavaScript����ر�һ��������Ȼ������ᰴť��Ҫ���ң�������ڲ�ͬ�˵���ҳ����ᰴť�Ĳ��ҷ�ʽ��ͬ���������ͨ��ִ��һ��JavaScript����ʵ�֣������Ƿ�ͨ��δ֪��
�������ҳ���Ҫ����������Ľ���ץȡ�����Ȳ������������������Ҫ����������μ�ʹ�������ҳ��Ҫ������Ƭ��url�Է���õ�����ͼƬ��URL����Ȼ��ҳͬ��Ҫִ��JavaScript��ֱ���������һҳȻ�����ͨ�����
����������ص������ҳ��Ȼ������һ����ᡣ����ͼƬҳ��ͼƬ��ַ�õ�����ͼƬ��ַ�������Ѿ��������ʵ����һ���������ˣ�
����Ҫ�������У�̫������Ҫִ��JavaScript����ҳ������ͼƬҳ�»����»����̻������õȴ�����Ϊ�ü���ͼƬ�����Լ�ͼƬҳ��ҳ����
http://b126.photo.store.qq.com/psb?/V11lFE0m0PAKY4/9iIk6mylvKLf8nK7s.c1iDQm7HO17UKlruIRfWIVuTY!/b/dDC5IUthIgAAnull&bo=IANYAgAAAAABA10!&rf=photolist&t=5
http://b126.photo.store.qq.com/psb?/V11lFE0m0PAKY4/9iIk6mylvKLf8nK7s.c1iDQm7HO17UKlruIRfWIVuTY!/m/dDC5IUthIgAAnull&bo=IANYAgAAAAABA10!&rf=photolist&t=5

JavaScript��ִ���Լ��ȴ�����ʱ�������Ȼ��һ�����⡣
"""

from selenium import webdriver
import time
# from bs4 import BeautifulSoup


def login_request(url, browser):  # ��¼��ȡcookie

    browser.get(url)   # �����¼��url
    button = browser.find_element_by_id("img_out_3435191864")   # ���ҵ�¼��ť���˴�������qq������������ҿ��ٵ�¼��ť��
    button.click()      # �����ť
    time.sleep(5)        # �ȴ�����

    '''
    with open("qq.html", "w", encoding="utf-8") as f:
        f.write(browser.page_source)
        f.close()
    '''


def page_request(url, browser):    # ��ȡ��ҳҳ��
    browser.get(url)      # ����ռ���ҳ��html��Ҫע����ǣ���һ��֮ǰ����Ҫ���е�¼��ȡcookie�������������ʵ�ʵ���ҳ
    time.sleep(5)
    with open("qq.html", "w", encoding="utf-8") as f:
        f.write(browser.page_source)
        f.close()

    return browser.page_source


def main():

    # ��¼ʹ�õ�URL
    # ����qq�ռ��¼��ҳ���Եõ���������ĵ�¼��ڣ�ÿ&���Ÿ���һ������
    login_url = u'https://xui.ptlogin2.qq.com/cgi-bin/xlogin?proxy_url=https%3A//qzs.qq.com/qzone/v6/portal/proxy.html&daid=5&&hide_title_bar=1&low_login=0&qlogin_auto_login=1&no_verifyimg=1&link_target=blank&appid=549000912&style=22&target=self&s_url=https%3A%2F%2Fqzs.qzone.qq.com%2Fqzone%2Fv5%2Floginsucc.html%3Fpara%3Dizone&pt_qr_app=%E6%89%8B%E6%9C%BAQQ%E7%A9%BA%E9%97%B4&pt_qr_link=http%3A//z.qzone.com/download.html&self_regurl=https%3A//qzs.qq.com/qzone/v6/reg/index.html&pt_qr_help_link=http%3A//z.qzone.com/download.html&pt_no_auth=1'

    # Ҫ����Ŀռ���ҳ��url�б�
    page_url = ["https://user.qzone.qq.com/136221675"]

    # ����һ�������ʵ��
    browser = webdriver.Chrome()
    # ���е�¼��ȡcookie
    login_request(login_url, browser)
    # ��Ҫ����Ŀռ���ҳurl�б�����������
    for url in page_url:
        page_source = page_request(url, browser)   # ������ҳ

        button = browser.find_element_by_class_name("m")  # ���Ұ�ť
        button.click()

        time.sleep(10)

        button = browser.find_element_by_id("QM_Profile_Photo_A")  # Ѱ�Ұ�ť
        button.click()  # �����ť

        time.sleep(5)

        with open("qq1.html", "w", encoding="utf-8") as f:
            f.write(browser.page_source)
            f.close()

    browser.close()   # �رձ�ǩҳ
    browser.quit()  # �ر������


if __name__ == '__main__':
    main()
