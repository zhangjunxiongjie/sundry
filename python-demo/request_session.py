import requests

# 通过如下方法可以之间进行登录并保存cookie
url ="http://www.renren.com/PLogin.do"
headers = {
            "User-Agent":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36",
            "email":"",
            "password":""
           }
session = requests.session()
response = session.post(url,headers = headers)
with open("renren.html","a+") as f:
    f.write(response.text)
    f.close()
