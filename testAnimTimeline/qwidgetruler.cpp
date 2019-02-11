#include "qwidgetruler.h"

#include <QDebug>
#include <QWheelEvent>

QWidgetRuler::QWidgetRuler(QWidget* parent)
    : QWidget(parent)
{
    //    qDebug() << "QWidgetRuler created";
    //    emit onChangePrecision(0);
    //    setMinimumWidth(500);
    updateTimeline(500);
}

int QWidgetRuler::updateTimeline(int newWidth)
{
    //    int newWidth = 500 +accuracy;

    int iStep = 0;
    while (iStep < nbSteps && newWidth * steps[iStep] < 50 * duration)
        iStep++;

    if (iStep == nbSteps) {
        qDebug() << "too small";
        return width();
    }

    step = steps[iStep];

    nbInterval = int(duration / step) + 2;
    //    wInterval = newWidth / nbInterval;
    pixPerSec = (newWidth / float(nbInterval)) / step;

    //    emit rulerChange(step, nbInterval, pixPerSec);
    //    leftSpacer->changeSize(0, 0);

    return newWidth;
}

//void QWidgetRuler::wheelEvent(QWheelEvent *event)
//{
////    qDebug() << "QWidgetRuler: wheelEvent " << event->angleDelta().ry();
////    setMinimumWidth(width() +event->angleDelta().ry() /2);
//    //    event->accept();
//}

void QWidgetRuler::onChangePrecision(int accuracy)
{
    //    qDebug() << "QWidgetRuler: onChangePrecision";

    //    int newWidth =width() +accuracy;

    int newWidth = updateTimeline(width() + accuracy);
    setMinimumWidth(newWidth);
    //    update();

    //    leftSpacer->changeSize(wInterval +wInterval *start / duration, 0);
    //    leftSpacer->minimumSize(0);
    //    updateTimeline();
    //    qDebug() << leftSpacer;
    //    playZone->setMinimumWidth((nbInterval -2) *wInterval * (end -start) / duration);
    //    frameSelector->update();

    //    emit changeScale();
}

double * QWidgetRuler::getPixPerSec()
{
    return &pixPerSec;
}

//void QWidgetRuler::setFrameSelector(QFrameSelector *value)
//{
//    frameSelector = value;
//}

//int* QWidgetRuler::getWInterval() const
//{
//    return &wInterval;
//}

int* QWidgetRuler::getNbInterval()
{
    return &nbInterval;
}

double* QWidgetRuler::getStep()
{
    return &step;
}

//void QWidgetRuler::setLeftSlider(QLabel *value)
//{
//    leftSlider = value;
//}

//void QWidgetRuler::setLeftSpacer(QSpacerItem *value)
//{
//    leftSpacer = value;
//}

//void QWidgetRuler::setPlayZone(QFrame *value)
//{
//    playZone = value;
//}
