#ifndef QSCROLLAREARULER_H
#define QSCROLLAREARULER_H

#include "animtimeline.h"
#include "qtoolbuttonplaypause.h"
#include "qwidgetruler.h"
#include <QObject>
#include <QScrollArea>
#include <QWidget>
#include "qdoublespinboxsmart.h"
#include "qframeselector.h"

class QScrollAreaRuler : public QScrollArea {
    Q_OBJECT
public:
    explicit QScrollAreaRuler(QWidget* parent = nullptr);

    bool* getShiftDown();

    void setRuler(QWidgetRuler* value);

    void setPlayPause(QToolButtonPlayPause* value);

    void setAnimTimeline(AnimTimeline *value);

    void setSpinDuration(QDoubleSpinBoxSmart *value);

    bool * getCtrlDown();

//    void setZero(double *value);

    void setSelector(QFrameSelector *value);

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

    void wheelEvent(QWheelEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
//    void scrollContentsBy(int dx, int dy) override;

signals:
//    void changePrecision(int width);
    void addKeyPose();
    void removeKeyPose();
    void previousKeyPose();
    void nextKeyPose();
    void durationChanged();

public slots:
    void onKeyPress(QKeyEvent *event);
    void onKeyRelease(QKeyEvent *event);
//    void onZoomRuler(QWheelEvent *event, double xr);

private:
    bool ctrlDown = false;
    bool shiftDown = false;
    bool midMouseDown = false;

    int mousePosX;
    int sliderPos;

    QWidgetRuler* ruler;
    QToolButtonPlayPause* playPause;
    AnimTimeline * animTimeline;
    QDoubleSpinBoxSmart * spinDuration;

    QFrameSelector * selector;
//    double * zero;
};

#endif // QSCROLLAREARULER_H
