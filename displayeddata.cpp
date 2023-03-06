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

void DisplayedData::RefreshDisplayedData()
{
    QString str;
    str.setNum(getRawData());
    displaylabel->setText(str);
}

TempertureData::TempertureData(QComboBox *sComboBox, QLabel *sLabel, QObject *parent): DisplayedData(sComboBox,sLabel, parent)
{
    nameParameter   = "temperature";
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

PressureData::PressureData(QComboBox *sComboBox, QLabel *sLabel, QObject *parent): DisplayedData(sComboBox,sLabel, parent)
{
        nameParameter   = "pressure";



}

PressureData::~PressureData()
{

}

void PressureData::SlotRefreshData(int indx)
{
    QString str;
    switch (indx) {
    case 0:
        str.setNum(rawData);
        break;

    case 1:
        str.setNum(rawData * 133.3);
        break;
    }
    displaylabel->setText(str);
}



HumidityData::HumidityData(QComboBox *sComboBox, QLabel *sLabel, QObject *parent): DisplayedData(sComboBox,sLabel, parent)
{
        nameParameter   = "HumidityData";



}

HumidityData::~HumidityData()
{

}

void HumidityData::SlotRefreshData(int indx)
{
    QString str;
    switch (indx) {
    case 0:
        str.setNum(rawData);
        break;

    case 1:
        str.setNum(rawData * 133.3);
        break;
    }
    displaylabel->setText(str);
}
