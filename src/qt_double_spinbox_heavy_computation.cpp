#include <QApplication>
#include "qt_double_spinbox_heavy_computation_widget.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  DoubleSpinboxHeavyComputation* widget = new DoubleSpinboxHeavyComputation;
  widget->show();
  return app.exec();
}
