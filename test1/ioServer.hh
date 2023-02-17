#ifndef RPCSERVER_H
#define RPCSERVER_H

#include <QtCore/QObject>

#include "tMosq.hh"

// ----------------------------------------------------------------------
class ioServer: public QObject {
  Q_OBJECT

public:
  ioServer(std::string name = "ctrlTessie");
  ~ioServer();
  void startServer();

public slots:
  void doRun();
  void sentToServer(QString msg);

signals:
  void signalSendFromServer(QString msg);

private:
  std::string    fName;
  tMosq         *fCtrlTessie;
};

#endif // RPCSERVER_H
