#ifndef MAP_H
#define MAP_H
// ��ͼ���������ӻ���
#include <vector>
#include "basexy.h"
#include "share.h"

class Map
{
public:
	Map(Share& s);

	void MapDraw(); // ��ͼ����
	// �����ͼ���ƺ���Ϣ���Ʒֿ���Ϊ�˿��Ի��Ʋ�ͬ��ͼ������Ϣ���Ʋ��øı�
	void InfoDraw(); // ��Ϣ����
	void Draw();

	void Refresh(); // ÿ�Ե�һ��ʳ����е÷�ˢ�¡�

	void ESCChoice(); // �����˳�ѡ�񡣣������������

private:
	std::vector<BaseXY> initmap;//�����ʼ��ͼ
	/*Map����Զ�����ֵ�ͼ��ֻ�轫��ʾ��ͼ�ĸ����㱣������Ӧ��map�У�����Snake����������Ӧ�ж�ײǽ��������
	std::vector<Point> map1;
	std::vector<Point> map2;
	*/

	Share& share;
};

#endif
