#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller // 游戏类
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
	int speed; // 蛇移动的速度
	int key; // 游戏模式
	int score; // 当前得分
};
#endif // CONTROLLER_H
