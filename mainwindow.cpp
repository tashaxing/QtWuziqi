#include <QPainter>
#include <QMouseEvent>
#include <math.h>
#include "mainwindow.h"

// -------全局遍历-------//
const int kBoardMargin = 20; // 棋盘边缘空隙
const int kRadius = 15; // 棋子半径
const int kBlockSize = 40; // 格子的大小
const int kPosDelta = 10; // 鼠标点击的模糊距离上限

// -------------------- //

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置棋盘大小
    setFixedSize(kBoardMargin * 2 + kBlockSize * kBoardSizeNum, kBoardMargin * 2 + kBlockSize * kBoardSizeNum);
//    setStyleSheet("background-color:yellow;");

    // 初始化游戏模型
    game = new GameModel;
}

MainWindow::~MainWindow()
{
    if (game)
    {
        delete game;
        game = nullptr;
    }
}

void MainWindow::initGame()
{   
    game->startGame(PERSON);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 绘制棋盘
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿
//    QPen pen; // 调整线条宽度
//    pen.setWidth(2);
//    painter.setPen(pen);
    for (int i = 0; i < kBoardSizeNum + 1; i++)
    {
        painter.drawLine(kBoardMargin + kBlockSize * i, kBoardMargin, kBoardMargin + kBlockSize * i, size().height() - kBoardMargin);
        painter.drawLine(kBoardMargin, kBoardMargin + kBlockSize * i, size().width() - kBoardMargin, kBoardMargin + kBlockSize * i);
    }

    // 绘制棋子
//    QBrush brush;
//    brush.setStyle(Qt::SolidPattern);
//    for (int i = 0; i < kBoardSizeNum; i++)
//        for (int j = 0; j < kBoardSizeNum; j++)
//        {
//            if (game->gameMapVec[i][j] == 1)
//            {
//                brush.setColor(Qt::white);
//                painter.setBrush(brush);
//                painter.drawEllipse(kBoardMargin + kBlockSize * j, kBoardMargin + kBlockSize * i, kRadius, kRadius);
//            }
//            else if (game->gameMapVec[i][j] == -1)
//            {
//                brush.setColor(Qt::black);
//                painter.setBrush(brush);
//                painter.drawEllipse(kBoardMargin + kBlockSize * j, kBoardMargin + kBlockSize * i, kRadius, kRadius);
//            }
//        }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
//    int x = event->x();
//    int y = event->y();

//    if (x >= kBoardMargin &&
//            x < size().width() - kBoardMargin &&
//            y >= kBoardMargin &&
//            y < size().height()- kBoardMargin)
//    {
//        // 获取最近的左上角的点
//        int col = x / kBlockSize;
//        int row = y / kBlockSize;

//        int leftTopPosX = kBoardMargin + kBoardMargin * col;
//        int leftTopPosY = kBoardMargin + kBoardMargin * row;

//        // 根据距离算出合适的点击位置,一共四个点，根据半径距离选最近的
//        int minLen = kPosDelta;
//        int clickPosRow, clickPosCol;
//        int len;
//        len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));
//        if (len < minLen)
//        {
//            minLen = len;
//            clickPosRow = row;
//            clickPosCol = col;
//        }
//        len = sqrt((x - leftTopPosX - kBlockSize) * (x - leftTopPosX - kBlockSize) + (y - leftTopPosY) * (y - leftTopPosY));
//        if (len < minLen)
//        {
//            minLen = len;
//            clickPosRow = row;
//            clickPosCol = col + 1;
//        }
//        len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY - kBlockSize) * (y - leftTopPosY - kBlockSize));
//        if (len < minLen)
//        {
//            minLen = len;
//            clickPosRow = row + 1;
//            clickPosCol = col;
//        }
//        len = sqrt((x - leftTopPosX - kBlockSize) * (x - leftTopPosX - kBlockSize) + (y - leftTopPosY - kBlockSize) * (y - leftTopPosY - kBlockSize));
//        if (len < minLen)
//        {
//            minLen = len;
//            clickPosRow = row + 1;
//            clickPosCol = col + 1;
//        }

//        game->updateGameMap(clickPosRow, clickPosCol);

//        // 重绘
//        update();
//    }
}


