from selenium.webdriver import Firefox
from selenium.webdriver.firefox.options import Options


def main():
    options = Options()
    options.add_argument('-headless')
    driver = Firefox(executable_path='./geckodriver', firefox_options=options)
    driver.get("https://www.qiushibaike.com/8hr/page/1/")
    print(driver.page_source)
    driver.close()


if __name__ == '__main__':
    
    main()
