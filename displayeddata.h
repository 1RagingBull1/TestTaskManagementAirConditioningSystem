#ifndef DISPLAYEDDATA_H
#define DISPLAYEDDATA_H

#include <QObject>
#include <QLabel>
#include <QComboBox>


class DisplayedData : public QObject
{
    Q_OBJECT
public:
    DisplayedData(QString sNameParameter, QComboBox* sComboBox, QLabel* sLabel, QObject *parent = nullptr);
    ~DisplayedData();

    int getRawData() const;
    void setRawData(int newRawData);



    void setVecCoefScale(QVector<float> *newVecCoefScale);


private:
    int rawData = 0; // содержит сырые данные полученные от иммитатора
    QString nameParameter; // содержит наименование отображаемого параметра
    QComboBox* scaleComboBox;
    QLabel* displaylabel;
    QVector<float>* vecCoefScale;
public slots:
    void SlotRefreshData(int indx);
signals:


};


class TempertureData : public DisplayedData
{

};


#endif // DISPLAYEDDATA_H
