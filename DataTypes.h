#ifndef DATATYPES_H
#define DATATYPES_H
#include <QObject>
#include <QString>

class DataTypes : public QObject
{
    Q_OBJECT
public:
    //explicit DataTypes(QObject *parent = 0);
    void logVariantList(QObject *root);
    void logVariantMap(QObject *root);

private:
    //explicit DataTypes(const DataTypes& rhs) = delete;
    //DataTypes& operator = (const DataTypes& rhs) = delete;
};



#endif // DATATYPES_H
