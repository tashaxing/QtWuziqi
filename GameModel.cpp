#include "GameModel.h"

GameModel::GameModel()
{

}

void GameModel::startGame(GameType gameType)
{
    // 初始棋盘
    for (int i = 0; i < kBoardSizeNum; i++)
    {
        std::vector<int> lineBoard;
        for (int j = 0; j < kBoardSizeNum; j++)
            lineBoard.push_back(0);
        gameMapVec.push_back(lineBoard);
    }

    // 己方下为true,对方下位false
    playerFlag = true;
}

void GameModel::updateGameMap(int row, int col)
{
    if (playerFlag)
        gameMapVec[row][col] = 1;
    else
        gameMapVec[row][col] = -1;
    // 换手
    playerFlag = !playerFlag;
}

bool GameModel::isWin(int x, int y)
{
    // 横竖斜四种大情况，每种情况都根据当前落子往后遍历5个棋子，有一种符合就算赢
    // 水平方向



    // 竖直方向

    // 左斜方向

    // 右斜方向
}

bool GameModel::isDeadGame()
{

}

