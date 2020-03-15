#include "qt_double_spinbox_heavy_computation_widget.h"
#include "ui_qt_double_spinbox_heavy_computation_widget.h"

#include <chrono>
#include <thread>

#include <QDoubleSpinBox>
#include <QProgressDialog>
#include <QtConcurrent/QtConcurrent>

DoubleSpinboxHeavyComputation::DoubleSpinboxHeavyComputation(QWidget *parent)
  : QWidget(parent), ui(new Ui::DoubleSpinboxHeavyComputation)
{
  ui->setupUi(this);
  on_checkBox_clicked();
  connect(ui->doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &DoubleSpinboxHeavyComputation::doubleSpinBoxValueChanged);
}

DoubleSpinboxHeavyComputation::~DoubleSpinboxHeavyComputation()
{
  delete ui;
}

void DoubleSpinboxHeavyComputation::startHeavyComputationInThread()
{
  QProgressDialog *progress = new QProgressDialog("Computing", "", 0, 0, this);
  progress->setWindowTitle(windowTitle());
  progress->setWindowFlags((progress->windowFlags() | Qt::CustomizeWindowHint) &
                           ~Qt::WindowCloseButtonHint);  // Hide close button
  progress->setWindowModality(Qt::WindowModal);
  progress->setCancelButton(nullptr);
  progress->setMaximum(0);
  progress->show();
  connect(this, &DoubleSpinboxHeavyComputation::computationDone, progress, &QProgressDialog::close);
  connect(this, &DoubleSpinboxHeavyComputation::computationDone, progress, &QProgressDialog::deleteLater);
  QFuture<void> f1 = QtConcurrent::run(this, &DoubleSpinboxHeavyComputation::heavyComputation);
}

void DoubleSpinboxHeavyComputation::heavyComputation()
{
  std::this_thread::sleep_for(std::chrono::seconds(2));
  emit computationDone();
}

void DoubleSpinboxHeavyComputation::on_checkBox_clicked()
{
  if (ui->checkBox->isChecked())
  {
    connect(ui->doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
            &DoubleSpinboxHeavyComputation::startHeavyComputationInThread);
  }
  else
  {
    disconnect(ui->doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
               &DoubleSpinboxHeavyComputation::startHeavyComputationInThread);
  }
}

void DoubleSpinboxHeavyComputation::doubleSpinBoxValueChanged(double value)
{
  qDebug() << "value " << ++n_ << ": " << value;
}
