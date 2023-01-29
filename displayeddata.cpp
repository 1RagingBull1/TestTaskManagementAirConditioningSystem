#include "displayeddata.h"


DisplayedData::DisplayedData(QString sNameParameter, QComboBox *sComboBox, QLabel *sLabel, QObject *parent)
{
    nameParameter   = sNameParameter;
    scaleComboBox   = sComboBox;
    displaylabel    = sLabel;

    //    connect(scaleComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SlotRefreshData(int)));
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

void DisplayedData::SlotRefreshData(int indx)
{

}
