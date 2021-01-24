# 实现对文件 Cache 的一些简单处理。
input = open('Cache.txt', 'r', encoding='utf-8')
output = open('Result.txt', 'w', encoding='utf-8')
while 1:
    line = input.readline()
    if line != '\n':

        output.write(line + '\n')

        # begin = 0
        # end = begin
        # p = 0
        # for p in range(len(line)):
        #     if line[p] == '-':
        #         line = line[:p] + ' ' + line[p + 1:]  # 字符串不支持修改，所以使用切片重新创造一个字符串。
        #     if ('a' <= line[p] <= 'z') or ('A' <= line[p] <= 'Z'):
        #         begin = p
        #         end = begin
        #         break
        # for p in range(p, len(line)):
        #     if line[p] == '-':
        #         line = line[:p] + ' ' + line[p + 1:]
        #         # line[p] = ' '
        #     if line[p] == ' ':
        #         end = p
        #     if u'\u4e00' <= line[p] <= u'\u9fff':  # 汉字
        #         break
        #     if line[p] == '(':
        #         end = p
        #         break
        #     if line[p] == '，':
        #         end = p
        #         break
        #
        # result = line[begin:end]
        # # print(result)
        # output.write(result + "\n")

    if not line:
        break

input.close()
output.close()


