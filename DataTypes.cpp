#include "DataTypes.h"

#include <QColor>
#include <QVariantList>
#include <QVariantMap>
#include <QDate>


void DataTypes::logVariantList(QObject *root)
{
    QColor kermit =  Qt::green;
    QVariantList myList;

    myList << 3.1420 << 30 << kermit << "guitar";

    QMetaObject::invokeMethod(root,
                              "logArray",
                              Q_ARG(QVariant,
                                    QVariant::fromValue(myList)));
}

void DataTypes::logVariantMap(QObject *root)
{
    QVariantMap myMap;
    myMap.insert("New languague", "c++");
    myMap.insert("STD release", QDate(2023,10,10));
    QMetaObject::invokeMethod(root,
                              "logMap",
                              Q_ARG(QVariant,
                                    QVariant::fromValue(myMap)));
}
