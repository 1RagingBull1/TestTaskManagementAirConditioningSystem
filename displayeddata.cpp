#include "displayeddata.h"


DisplayedData::DisplayedData(QComboBox *sComboBox, QLabel *sLabel, QObject *parent):QObject(parent)
{

    scaleComboBox   = sComboBox;
    displaylabel    = sLabel;

        connect(scaleComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SlotRefreshData(int)));

}

DisplayedData::~DisplayedData()
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

//void DisplayedData::SlotRefreshData(int indx)
//{
//  RefreshData(indx);
//}



TempertureData::TempertureData(QComboBox *sComboBox, QLabel *sLabel, QObject *parent): DisplayedData(sComboBox,sLabel, parent)
{
    nameParameter   = "temperature";
    rawData = 10;
}

TempertureData::~TempertureData()
{

}

void TempertureData::SlotRefreshData(int indx)
{
    QString str;
    switch (indx) {
    case 0:
        str.setNum(rawData);
        break;

    case 1:
        str.setNum((rawData * 9/5) + 32);
        break;

    case 2:
        str.setNum(rawData + 273.15);
        break;

    }
    displaylabel->setText(str);
}
