#include <QApplication>
#include <QDebug>
#include <QScreen>

#include "genius.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Genius game;
  game.show();
  return a.exec();
}
