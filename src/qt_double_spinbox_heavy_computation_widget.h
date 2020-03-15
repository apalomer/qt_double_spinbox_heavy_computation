#ifndef QT_DOUBLE_SPINBOX_HEAVY_COMPUTATION_WIDGET_H
#define QT_DOUBLE_SPINBOX_HEAVY_COMPUTATION_WIDGET_H

#include <QWidget>

#ifdef _WIN32
#ifdef QTDOULESPINBOXHEAVYCOMPUTATION
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#else
#define EXPORT
#endif

namespace Ui
{
class EXPORT DoubleSpinboxHeavyComputation;
}

class DoubleSpinboxHeavyComputation : public QWidget
{
  Q_OBJECT

public:
  explicit DoubleSpinboxHeavyComputation(QWidget *parent = nullptr);
  ~DoubleSpinboxHeavyComputation();

signals:

  void computationDone();

private slots:
  void on_checkBox_clicked();

private slots:
  void startHeavyComputationInThread();

  void heavyComputation();

  void doubleSpinBoxValueChanged(double value);

private:
  Ui::DoubleSpinboxHeavyComputation *ui;
  int n_ = 0;
};

#endif  // QT_DOUBLE_SPINBOX_HEAVY_COMPUTATION_WIDGET_H
