#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller // ��Ϸ��
{
public:
	Controller() : speed(200), key(1), score(0) {}

	void Start();

	void Select();

	void DrawGame();

	int PlayGame();

	void UpdateScore(const int&);

	void RewriteScore();

	int Menu();

	void Game();

	int GameOver();

private:
	int speed; // ���ƶ����ٶ�
	int key; // ��Ϸģʽ
	int score; // ��ǰ�÷�
};
#endif // CONTROLLER_H
