#生成词云
import jieba
import wordcloud
from scipy.misc import imread
mask=imread("china.jpg")
f=open("词云.txt","rb")
t=f.read()
f.close()
ls=jieba.lcut(t)
txt=" ".join(ls)
w=wordcloud.WordCloud(font_path="msyh.ttc",mask=mask,\
                      width=1000,height=700,\
                      background_color="white",)
w.generate(txt)
w.to_file("grword.jpg")
