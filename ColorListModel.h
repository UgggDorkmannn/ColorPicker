#ifndef COLORLISTMODEL_H
#define COLORLISTMODEL_H

#include <QWidget>
#include <QAbstractListModel>
#include <QStyledItemDelegate>

class ColorItemDele:public QStyledItemDelegate{
protected:
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override{

        return QSize(120,40);
    }

public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

};

class ColorListModel:public QAbstractListModel
{
public:
    ColorListModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    virtual Qt::ItemFlags     flags(const QModelIndex &index) const override;
private:
    QStringList mColorList;

};

#endif // COLORLISTMODEL_H
