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

bool GameModel::isWin(int row, int col)
{
    // 横竖斜四种大情况，每种情况都根据当前落子往后遍历5个棋子，有一种符合就算赢
    // 水平方向(往左校验)
    if (col - 4 > 0)
    {
        bool equalFlag = true;
        for (int i = 4; i > 0; i--)
            if (gameMapVec[row][col - i] != gameMapVec[row][col])
            {
                equalFlag = false;
                break;
            }
        if (equalFlag)
            return true;
    }
    // 竖直方向(往上校验)
    if (row - 4 > 0)
    {
        bool equalFlag = true;
        for (int j = 4; i > 0; i--)
            if (gameMapVec[row - i][col] != gameMapVec[row][col])
            {
                equalFlag = false;
                break;
            }
        if (equalFlag)
            return true;
    }
    // 左斜方向
    if (row + 4 < )
    // 右斜方向

    return false;
}

bool GameModel::isDeadGame()
{

}

