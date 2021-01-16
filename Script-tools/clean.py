# 用于清理 VS 项目文件

import os
import shutil

file_dir = '.\\'
delete_dirs = [] #待删除文件夹
delete_files = [] #待删除文件
delete_dirs_recursion = [] #直接递归删除整个文件夹
for root, dirs, files in os.walk(file_dir):
    #print('root_dir:', root)  # 当前目录路径

    # print('files:', files)  # 当前路径下所有非目录子文件
    for file in files:
        if ((file[-4:] != '.cpp') and (file[-2:] != '.h') and
            (file[-3:] != '.py') and (file[-2:] != '.c') and
            (file[-4:] != '.txt') and (file[-4:] != '.ico') ):
            if root == '.\\':
                #os.remove(root + file)
                delete_files.append(root + file)
            else:
                #os.remove(root + '\\' + file)
                delete_files.append(root + '\\' + file)

    if ((root[-3:] == '.vs') or (root[-5:] == 'Debug')):
        delete_dirs_recursion.append(root) # 递归删除整个文件夹

"""                
    #print('sub_dirs:', dirs)  # 当前路径下所有子目录
    for dir in dirs:
        if ((dir == '.vs') or (dir == 'Debug')):
            if root == '.\\':
                #os.rmdir(root + dir)
                delete_dirs.append(root + dir)
            else:
                #os.rmdir(root + '\\' + dir)
                delete_dirs.append(root + '\\' + dir)
        elif len(files) == 0:
            if root == '.\\':
                #os.rmdir(root + dir)
                delete_dirs.append(root + dir)
            else:
                #os.rmdir(root + '\\' + dir)
                delete_dirs.append(root + '\\' + dir)
"""
# 先删除可以直接删除的整个文件夹
for dir in reversed(delete_dirs_recursion): # 倒序删除避免文件夹非空
    shutil.rmtree(dir)
    print(dir)
# 然后删除判定无用的文件
for file in delete_files:
    os.remove(file)
    print(file)

'''
for root, dirs, files in os.walk(file_dir):
    #print('sub_dirs:', dirs)  # 当前路径下所有子目录
    for dir in dirs:
        if ((dir == '.vs') or (dir == 'Debug')):
            if root == '.\\':
                #os.rmdir(root + dir)
                delete_dirs.append(root + dir)
            else:
                #os.rmdir(root + '\\' + dir)
                delete_dirs.append(root + '\\' + dir)
        elif len(files) == 0:
            if root == '.\\':
                #os.rmdir(root + dir)
                delete_dirs.append(root + dir)
            else:
                #os.rmdir(root + '\\' + dir)
                delete_dirs.append(root + '\\' + dir)
'''

# 保证所有空文件夹得到清除
while True: 
    delete_dirs.clear()
    for root, dirs, files in os.walk(file_dir):
        work_path = root
        if not os.listdir(work_path):
            delete_dirs.append(work_path)

    for dir in reversed(delete_dirs): # 倒序删除避免文件夹非空
        os.rmdir(dir)
        print(dir)
    # 当没有文件夹需要删除时退出
    if len(delete_dirs) == 0:
        break


#    for file in files:
#        print(file)
#        print(root + '/' + file) # 打印文件路径



