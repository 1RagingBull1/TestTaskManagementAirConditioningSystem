#include "displayeddata.h"

DisplayedData::DisplayedData(QObject *parent)
    : QObject{parent}
{

}

int DisplayedData::getRawData() const
{
    return rawData;
}

void DisplayedData::setRawData(int newRawData)
{
    rawData = newRawData;
}

const QString &DisplayedData::getNameParameter() const
{
    return nameParameter;
}

void DisplayedData::setNameParameter(const QString &newNameParameter)
{
    nameParameter = newNameParameter;
}
