#ifndef DISPLAYEDDATA_H
#define DISPLAYEDDATA_H

#include <QObject>
#include <QLabel>
#include <QComboBox>

class DisplayedData : public QObject
{
    Q_OBJECT
public:
    explicit DisplayedData(QObject *parent = nullptr);
    ~DisplayedData();

    void SetDisplayLabel(QLabel* label); // присваивается label в котором отображается значение параметра
    void SetScaleCombobox(QComboBox* comboBox); //присвается всплывающий список в котором выбирается единица измерения
    void RefreshData();
    int getRawData() const;
    void setRawData(int newRawData);



    const QString &getNameParameter() const;
    void setNameParameter(const QString &newNameParameter);

private:
    int rawData; // содержит сырые данные полученные от иммитатора
    QString nameParameter; // содержит наименование отображаемого параметра

signals:
    void sigSaveSettings();

};

#endif // DISPLAYEDDATA_H
