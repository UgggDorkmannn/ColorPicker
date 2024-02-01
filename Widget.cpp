#include "Widget.h"
#include "ui_Widget.h"
#include <QListWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QListView>
#include "ColorListModel.h"
#include <QSplitter>
#include "ScrollBar.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("ColorPicker");
    resize(1200,700);
    QPalette pa;
    pa.setColor(QPalette::Window,QColor("white"));
    setPalette(pa);
    setAutoFillBackground(true);
    setContentsMargins(0,0,0,0);

    QHBoxLayout * mainLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(0,0,0,0);

    QGridLayout * showLayout = new QGridLayout;
    showLayout->setContentsMargins(0,0,0,0);
    for(int i = 0;i < 5;++i){
        for(int j = 0;j < 5;++j){
            QLabel * lab = new QLabel;
            lab->setWordWrap(true);
            lab->setTextInteractionFlags(Qt::TextSelectableByMouse);
            lab->setAutoFillBackground(true);
            mShowList.push_back(lab);
            showLayout->addWidget(lab,i,j);
        }
    }

    QListView * mColorList = new QListView;

    mColorList->setStyleSheet("border:none;");
    mColorList->setVerticalScrollBar(new VScrollBar());
    mColorList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setLayout(mainLayout);

    mColorList->setFixedWidth(400);
    ColorListModel * cm = new ColorListModel;
    ColorItemDele * cd = new ColorItemDele;
    mColorList->setModel(cm);
    mColorList->setItemDelegate(cd);
    mainLayout->addWidget(mColorList);
    mainLayout->addLayout(showLayout);
    connect(mColorList,&QListView::clicked,this,[=](const QModelIndex &index){
        if(index.isValid()){
            QString color = index.data().toString();
            QColor c(color);
            int cnt = mShowList.size();
            qreal a = 1.0 / cnt;
            QPalette pa;
            for(int i = 0;i< cnt;++i){
                qreal alpha = 1-i*a;
                c.setAlphaF(alpha);
                auto * lab = mShowList[i];
                if(lab == nullptr) continue;
                pa.setColor(QPalette::Window,c);
                lab->setPalette(pa);

                QString hex = QString::asprintf("%02X%02X%02X%02X",c.alpha(),c.red(),c.green(),c.blue());
                lab->setText(QString::number(alpha) + "\n" + hex);
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
