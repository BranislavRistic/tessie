#include "TECDisplay.h"
#include "ui_TECDisplay.h"

using namespace std;

// -------------------------------------------------------------------------------
TECDisplay::TECDisplay(QWidget *parent):  QWidget(parent), ui(new Ui::TECDisplay), fTECDisplayItec(0) {
  ui->setupUi(this);

  QString qTitle = QString("TEC ") + QString::number(fTECDisplayItec);
  ui->TECDisplayTitle->setText(qTitle);
}

// -------------------------------------------------------------------------------
TECDisplay::~TECDisplay() {
  delete ui;
}


// -------------------------------------------------------------------------------
void TECDisplay::setTitle(int itec) {
  fTECDisplayItec = itec;
  QString qTitle = QString("TEC ") + QString::number(fTECDisplayItec);
  ui->TECDisplayTitle->setText(qTitle);
}

// -------------------------------------------------------------------------------
void TECDisplay::setHardware(driveHardware *x) {
  fThread = x;
}

// ----------------------------------------------------------------------
void TECDisplay::updateHardwareDisplay() {
  if (isVisible()) {
    // cout << "TECDisplay::updateHardwareDisplay() fThread = " << fThread << endl;
    ui->value_00->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Mode")));
    ui->value_01->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "ControlVoltage_Set"), 'f', 2));
    ui->value_02->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "PID_kp"), 'f', 2));
    ui->value_03->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "PID_ki"), 'f', 2));
    ui->value_04->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "PID_kd"), 'f', 2));
    ui->value_05->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Temp_Set"), 'f', 2));
    ui->value_06->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "PID_Max"), 'f', 2));
    ui->value_07->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "PID_Min"), 'f', 2));
    ui->value_08->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Temp_W"), 'f', 2));
    ui->value_09->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Temp_M"), 'f', 2));
    ui->value_10->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Temp_Diff"), 'f', 2));
    ui->value_11->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Peltier_U"), 'f', 2));
    ui->value_12->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Peltier_I"), 'f', 2));
    ui->value_13->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Peltier_R"), 'f', 2));
    ui->value_14->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Peltier_P"), 'f', 2));
    ui->value_15->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Supply_U"), 'f', 2));
    ui->value_16->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Supply_I"), 'f', 2));
    ui->value_17->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "Supply_P"), 'f', 2));
    ui->value_18->setText(QString::number(fThread->getTECRegister(fTECDisplayItec, "PowerState"), 'f', 2));

  } else {
      // cout << "TECDisplay::updateHardwareDisplay() not visible}" << endl;
  }
}
