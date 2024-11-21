#include "Conway.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  string title = "Conway's Game of Life";
  Conway game;
  QWidget window;
  window.setWindowTitle(QString::fromStdString(title));
  window.setFixedSize(game.grid->width(), game.grid->height());
  auto layout = new QVBoxLayout(&window);
  layout->addWidget(game.grid);
  window.show();
  game.mainloop();
  return app.exec();
}
