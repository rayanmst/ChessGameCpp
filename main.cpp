#include "ChessGame.h"
#include "Board.h"
#include <QApplication>

ChessGame* g;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g = new ChessGame();
    g->show();
    g->drawChessBoard();
    g->start();

    return a.exec();
}
