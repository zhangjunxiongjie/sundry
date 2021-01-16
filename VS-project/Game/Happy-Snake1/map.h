#ifndef MAP_H
#define MAP_H
// 地图及辅助可视化类
#include <vector>
#include "basexy.h"
#include "share.h"

class Map
{
public:
	Map(Share& s);

	void MapDraw(); // 地图绘制
	// 这里地图绘制和信息绘制分开是为了可以绘制不同地图，而信息绘制不用改变
	void InfoDraw(); // 信息绘制
	void Draw();

	void Refresh(); // 每吃到一个食物进行得分刷新。

	void ESCChoice(); // 按键退出选择。！！！按键检测

private:
	std::vector<BaseXY> initmap;//保存初始地图
	/*Map类可自定义多种地图，只需将表示地图的各个点保存在相应的map中，并在Snake类中增加相应判断撞墙函数即可
	std::vector<Point> map1;
	std::vector<Point> map2;
	*/

	Share& share;
};

#endif
