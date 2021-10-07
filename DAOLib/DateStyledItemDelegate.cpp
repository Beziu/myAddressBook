#include "DateStyledItemDelegate.h"

DateStyledItemDelegate::DateStyledItemDelegate(QWidget* parent, QString dateFormat) : QStyledItemDelegate (parent)
{
    this->dateFormat = dateFormat;

}

QString DateStyledItemDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
   // Sprawdza czy wartosc jest data zdolna do konwersji
   if (value.canConvert<QDate>())
      return locale.toString(value.toDate(), dateFormat);
   else
      return value.toString();
}

