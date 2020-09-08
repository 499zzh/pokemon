#include "my_Label.h"

my_Label::my_Label(QWidget *parent):QLabel(parent)
{

}

// 重写鼠标释放时间 mouseReleaseEvent()
void my_Label::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    if(ev->button() == Qt::LeftButton)
    {
        emit clicked();	// 发射信号
    }
}
