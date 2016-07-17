#pragma once

#include <QtCore>

#include <DriverStation.h>

class ConsoleDS : public QObject {
    Q_OBJECT

public:
    ConsoleDS(int teamNumber, QObject* parent = nullptr);
    virtual ~ConsoleDS() = default;

    void enableDS(bool enable);

public slots:
    void run();

signals:
    void finished();

private:
    DriverStation& m_ds = *DriverStation::getInstance();
};
