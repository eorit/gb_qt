#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

    class Checker : public QObject
{
    Q_OBJECT
public:
    explicit Checker();
    virtual ~Checker();
    Q_INVOKABLE
        void nextRecord();
    Q_INVOKABLE
        void saveRecord(QString, QString, QString);
    Q_INVOKABLE
        int getNTasks();
    Q_INVOKABLE
        void dbconnect();

private:
    QSqlDatabase database;
    QSqlQuery query;
    QSqlRecord rec;
    QString dbName = "tasks";
    int ntasks = 0;

signals:
    void end(bool succed);
    void loadTask(QString task, QString endTask, QString progress);

private slots:
};

#endif // CHECKER_H
