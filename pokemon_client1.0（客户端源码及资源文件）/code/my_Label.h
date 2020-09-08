#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>

class my_Label : public QLabel
{

    Q_OBJECT
public:
    explicit my_Label(QWidget *parent = 0);
    // 构造函数声明
protected:
    virtual void mouseReleaseEvent(QMouseEvent * ev);
    // 声明鼠标左键点击事件
signals:
    void clicked(void);
    // 声明鼠标左击中信号

};


#endif // MYLABEL_H
