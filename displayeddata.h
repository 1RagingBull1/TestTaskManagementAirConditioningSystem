#ifndef DISPLAYEDDATA_H
#define DISPLAYEDDATA_H

#include <QObject>
#include <QLabel>
#include <QComboBox>


class DisplayedData : public QObject
{
    Q_OBJECT
public:
    DisplayedData(QComboBox* sComboBox, QLabel* sLabel, QObject *parent = nullptr);
    ~DisplayedData();

    int getRawData() const;
    void setRawData(int newRawData);



protected:
    QString nameParameter; // содержит наименование отображаемого параметра
    int rawData = 0; // содержит сырые данные полученные от иммитатора
    QComboBox* scaleComboBox;
    QLabel* displaylabel;

private:
//    virtual void RefreshData(int indx) = 0;
public slots:
    virtual void  SlotRefreshData(int indx) = 0;
signals:


};


class TempertureData : public DisplayedData
{
        Q_OBJECT
public:
    TempertureData(QComboBox* sComboBox, QLabel* sLabel, QObject *parent = nullptr);
    ~TempertureData();


    // DisplayedData interface
public slots:
    void SlotRefreshData(int indx) override;
};


#endif // DISPLAYEDDATA_H
