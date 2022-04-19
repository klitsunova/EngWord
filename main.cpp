#include <QApplication>

#include "Controllers/MainWindow/main_window.h"

void SetConfiguration() {
  QCoreApplication::setOrganizationName("Klitsunova");
  QCoreApplication::setApplicationName("Duolingo");
}

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  SetConfiguration();
  MainWindow main_window;
  main_window.show();
  return QApplication::exec();
}
