# format directory name.

import os
import shutil

fileDir = './'
renameDirsSrc = [] #
renameDirsDst = [] #
renameFilesSrc = [] #
renameFilesDst = [] 
#file
for root, dirs, files in os.walk(fileDir):
    for file in files:
        flag = False
        tempFile = ''
        # print(file)
        for i in range(len(file)):
            if (file[i] == '-'):
                tempFile += '_'
                flag = True
            else:
                tempFile += file[i]
        if flag:
            srcPath = root + '/' + file
            dstPath = root + '/' + tempFile
            print(srcPath + ':' + dstPath)
            os.rename(srcPath, dstPath)

#cord
for root, dirs, files in os.walk(fileDir):
    for dir in dirs:
        flag = False
        tempDir = ''
        for i in range(len(dir)):
            if (dir[i] == '_'):
                tempDir += '-'
                flag = True
            else:
                tempDir += dir[i]
        if flag:
            if root == './':
                srcPath = root + dir
                dstPath = root + tempDir
            else:
                srcPath = root + '/' + dir
                dstPath = root + '/' + tempDir
            
            #print(srcPath + ':' + dstPath)    
            renameDirsSrc.append(srcPath)
            renameDirsDst.append(dstPath)
            #os.rename()
#rename
if len(renameDirsSrc) == len(renameDirsDst):
    for ri in reversed(range(len(renameDirsSrc))):
        print(renameDirsSrc[ri] + ':' + renameDirsDst[ri])
        os.rename(renameDirsSrc[ri], renameDirsDst[ri])

               
