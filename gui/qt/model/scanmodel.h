#ifndef _SCANMODEL_H_
#define _SCANMODEL_H_

#include "value.h"
#include "utils/uhuru.h"
#include "scanreportmodel.h"

#include <QObject>
#include <QThread>
#include <QDateTime>

class ScanModel : public QObject {
  Q_OBJECT

public:
  explicit ScanModel(const QString &path) : _path(path), _startDate(QDateTime::currentDateTime()), _completed(false) {}
  ~ScanModel() {}

  const QString &path() { return _path; }
  const QDateTime &startDate() { return _startDate; }
  const bool completed() { return _completed; }
  

  void scan();

  Value *scannedCount() { return &_scannedCount; }
  Value *malwareCount() { return &_malwareCount; }
  Value *suspiciousCount() { return &_suspiciousCount; }
  Value *unhandledCount() { return &_unhandledCount; }
  Value *cleanCount() { return &_cleanCount; }
  Value *progress() { return &_progress; }

  ScanReportModel *report() { return &_reportModel; }

  void callback(enum uhuru_file_status status, const char *path, const char *report);

signals:
  void scanning(const QString &path);
  void scanComplete();

private slots:
  void scanThreadFinished();

private:
  QString _path;
  QDateTime _startDate;
  bool _completed;

  Value _scannedCount;
  Value _malwareCount;
  Value _suspiciousCount;
  Value _unhandledCount;
  Value _cleanCount;
  Value _progress;

  ScanReportModel _reportModel;
};

class ScanModelThread: public QThread {
  Q_OBJECT

public:
  ScanModelThread(ScanModel *model) : _model(model) {}

protected:
  void run();

private:
  ScanModel *_model;
};

#endif
