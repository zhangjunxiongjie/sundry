//������������ʱ�Լ�����ѭ���ﵽ��̬��ʾ��Ч�� 

#include <windows.h>    //�ṩ��ʱ����Sleep ���� 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int type_live=1;
const int type_dead=0;
const int map_size=20;

int map[20][20];

void initGame();//��ʼ�� 
void run();//ÿһ�ֵ�����  
int getLivingNum(int x, int y);//�ж�ĳ�������ܱ��м�������ϸ�� 
void show_map();//�ѵ�ͼ��״̬��ӡ����Ļ�� 

int main()
{
    initGame();
    while(1>0){
		run();
        show_map();
        Sleep(500);    //��ʱ���� 
        system("cls");
    }
    system("pause");
    return 0;
}
void initGame(){//��ʼ�� 
    int i,j;
    srand((unsigned) time(NULL));
    for(i=0;i<map_size;i++){
	for(j=0;j<map_size;j++){
	    map[i][j]=rand()%2;//ÿһ�����ӵ�ϸ������״̬���������
        }
    }
}
void run(){//ÿһ�ֵ����� 
    int i,j,num;
    for(i=0;i<map_size;i++){
	for(j=0;j<map_size;j++){
	    num=getLivingNum(i,j);
	    //�����������һ�ֵ�����״̬
        if(num==3){
			map[i][j]=type_live;
        }
        else if(num!=2){
			map[i][j]=type_dead;
        }
        }
    }
}
//��ȡ��ǰ�����ܱ�8�����ӵĻ��ŵ�ϸ������
int getLivingNum(int x, int y){
    int i,j;
    int num=0;
    for(i=x-1;i<=x+1;i++){
	if(i<0||i>=map_size){//��ֹ�����±�Խ��
	continue;
        }
        for(j=y-1;j<=y+1;j++){
	    if(j<0 || j>=map_size){//��ֹ�����±�Խ��
		continue;
            }
            if(map[i][j]==type_live){
		num++;
            }
        }
    }
    if(map[x][y]==type_live){
		num--;
    }
    return num;
}
void show_map(){//�ѵ�ͼ״̬�������Ļ��
	int i,j;
    for(i=0;i<map_size;i++){
	for(j=0;j<map_size;j++){
	    if(map[i][j]==type_live){
			printf(" *");
        }
        else if(map[i][j]==type_dead){
			printf("  ");
        }
        }
        printf("\n");
    }
}
