#ifndef SERVICEFINDER_H
#define SERVICEFINDER_H

#include <QObject>
class ServiceFinder : public QObject
{
    Q_OBJECT
public:
    explicit ServiceFinder(QObject *parent = 0);

signals:

public slots:
private:
    int check_duration;
};

#endif // SERVICEFINDER_H
