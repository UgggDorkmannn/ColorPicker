#include "ColorListModel.h"
#include <QPainter>
void ColorItemDele::paint(QPainter *painter, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const{
    painter->save();
    painter->setRenderHints(QPainter::Antialiasing);
    bool hovering = false;
    bool selected = false;
    auto state = option.state;
    if(state & QStyle::State_Selected) selected = true;
    if(state & QStyle::State_MouseOver) hovering = true;

    QRect rct = option.rect;

    QString colorName = index.data().toString();
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(colorName));



    int offx = rct.x();
    int offy = rct.y();
    int x = rct.width();
    int y = rct.height();

    int textx = x * 0.66;
    if(hovering || selected) textx = x/2;

    //draw rect
    painter->drawRoundedRect(rct.adjusted(2,2,textx-x,-2),4,4);

    QFont font;
    font.setPixelSize(16);
    painter->setFont(font);
    QFontMetrics m(font);
    int h = m.height();
    //draw text
    painter->setPen(QColor("black"));
    painter->drawText(offx + textx + 4,y/2+h/2 * 0.8 +offy,colorName);

    painter->restore();
}
ColorListModel::ColorListModel()
{
    mColorList = QColor::colorNames();
}
int ColorListModel::rowCount(const QModelIndex &parent) const{
    return mColorList.size();
}
Qt::ItemFlags   ColorListModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
QVariant ColorListModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()) return QVariant();
    int row = index.row();
    if(role==Qt::DisplayRole)
        return mColorList[row];
    return QVariant();
    //if(role == Qt::DisplayRole)
}
bool ColorListModel::setData(const QModelIndex &index, const QVariant &value, int role){


    return true;
}
