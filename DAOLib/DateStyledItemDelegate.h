#ifndef DATESTYLEDITEMDELEGATE_H
#define DATESTYLEDITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QDate>
#include <QDateTime>

// Musi pochodzić z QStyledItemDelegate

class DateStyledItemDelegate : public QStyledItemDelegate
{

    Q_OBJECT

public:
    DateStyledItemDelegate(QWidget* parent = nullptr, QString dateFormat = "dd.MM.yyyy");

    QString displayText(const QVariant& value, const QLocale& locale) const override;

private:
    QString dateFormat;

};

#endif // DATESTYLEDITEMDELEGATE_H
