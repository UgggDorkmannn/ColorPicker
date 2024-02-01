#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVariant>
#include <QLabel>
#include <QStyledItemDelegate>
#include <QAbstractListModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QStringList mNameList;
    QList<QLabel*> mShowList;
};

#endif // WIDGET_H
