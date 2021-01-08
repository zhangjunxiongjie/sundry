#ifndef TOOLS_H
#define TOOLS_H

void SetCursorPosition(const int x, const int y); //设置光标位置，这个函数有点特殊应该可以放在某一个类里面

// 公用辅助函数

void SetWindowSize(int cols, int lines); //设置窗口大小

void SetColor(int colorID); //设置文本颜色

void SetBackColor(); //设置文本背景色

#endif // TOOLS_H
