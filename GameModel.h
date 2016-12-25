#ifndef GAMEMODEL_H
#define GAMEMODEL_H

// ---- 五子棋游戏模型类 ---- //
#include <vector>

// 游戏类型，双人还是AI（目前固定让AI下黑子）
enum GameType
{
    PERSON,
    BOT
};

// 游戏状态
enum GameStatus
{
    PLAYING,
    WIN,
    DEAD
};

// 棋盘尺寸
const int kBoardSizeNum = 15;

class GameModel
{
public:
    GameModel();

public:
    std::vector<std::vector<int>> gameMapVec; // 存储当前游戏棋盘和棋子的情况,空白为0，白子1，黑子-1
    std::vector<std::vector<int>> scoreMapVec; // 存储各个点位的评分情况，作为AI下棋依据
    bool playerFlag; // 标示下棋方
    GameType gameType; // 游戏模式
    GameStatus gameStatus; // 游戏状态

    void startGame(GameType type); // 开始游戏
    void calculateScore(); // 计算评分
    void actionByPerson(int row, int col); // 人执行下棋
    void actionByAI(int &clickRow, int &clickCol); // 机器执行下棋
    void updateGameMap(int row, int col); // 每次落子后更新游戏棋盘
    bool isWin(int row, int col); // 判断游戏是否胜利
    bool isDeadGame(); // 判断是否和棋
};

#endif // GAMEMODEL_H
