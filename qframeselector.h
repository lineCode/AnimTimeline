
#ifndef QFRAMESELECTOR_H
#define QFRAMESELECTOR_H

#include "qwidgetruler.h"
#include <QFrame>
#include <QSpacerItem>
//#include <QSet>
#include <set>
#include <QDoubleSpinBox>
#include <QToolButton>

class QFrameSelector : public QFrame {
    Q_OBJECT
public:
    explicit QFrameSelector(QWidget* parent = nullptr);
//    ~QFrameSelector() override;

    void setLeftSlider(QLabel* value);
    void setPlayZone(QFrame* value);
    void setRightSlider(QLabel* value);
    void setLeftSpacer(QFrame* value);
    //    void drawRulerScale();

    void setCursorSpin(QDoubleSpinBox *value);

    void setStartSpin(QDoubleSpinBox *value);

    void setEndSpin(QDoubleSpinBox *value);
    void setCursor(double time);
    void updatePlayZone();
    double getCursor();

    double getStart() const;

    double getEnd() const;
    int getNbKeyPoses() const;
    double getKeyPose(int id) const;

    void setRemoveKeyPoseButton(QToolButton *value);

//    std::set<double> keyPoses;

    std::set<double> getKeyPoses() const;
    void setKeyPoses(const std::set<double> &value);

    void setStartInc(QDoubleSpinBox *value);

    void setEndInc(QDoubleSpinBox *value);

//    void setTotalDuration(QDoubleSpinBox *value);

    void setTotalDurationSpin(QDoubleSpinBox *value);

protected:
    virtual void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void keyPressEvent(QKeyEvent * event) override;
    //    virtual bool eventFilter(QObject * watched, QEvent *event) override;
    //    virtual void wheelEvent(QWheelEvent * event) override;


signals:
//    void startChanged(double time);
//    void endChanged(double time);
    void cursorChanged(double time);
    void nbKeyPosesChanged(int nbEl);
//    void changePauseMode();
//    void pause();
//    void play();
//    void isOnKeyPose(bool isOn);
    void keyPoseAdded(double time);
    void keyPoseChanged(int num);
    void keyPosesChanged(double gap);
    void removeKeyPose(int num);
//    void changePeriod(double time);

    //    void changePrecision(int accuracy);
    //    void updatePlayZone(int xPos, int width);

public slots:
//    void onRedrawScale();
    void onSlideLeftSlider(int deltaX);
    void onSlideRightSlider(int deltaX);
    void onSlideRelease();

    void onAddingKeyPose(double time = -1.0);
    void onDeleteKeyPose();

    void onChangeStart(double time);
    void onChangeEnd(double time);
    void onChangeCursor(double time);
    void onChangeDuration();

    void onSetCursorToStart();
    void onSetCursorToEnd();
    void onSetCursorToPreviousKeyPose();
    void onSetCursorToNextKeyPose();

    void onPlay();
    void onPause();
//    void onTickTimer();
    void onChangeCursorSpin();
    void onChangeStartSpin();
    void onChangeEndSpin();

    void onStartIncPlus();
    void onStartIncLess();
    void onEndIncPlus();
    void onEndIncLess();
    //    void onLeftSliderClicked(int);
    //    void onRulerChange(double step, int nbInterval, double pixPerSec);
private:
    void updateCursorSpin();
    void updateStartSpin();
    void updateEndSpin();
    void updateKeyPoses(double gap);
    void updateDurationSpin();

private:
    QWidgetRuler* widgetRuler;

    //    QSpacerItem * leftSpacer;
    QFrame* leftSpacer;
    QLabel* leftSlider;
    QLabel* rightSlider;
    QFrame* playZone;

    QDoubleSpinBox * cursorSpin;
    QDoubleSpinBox * startSpin;
    QDoubleSpinBox * endSpin;
    QDoubleSpinBox * totalDurationSpin;

    QDoubleSpinBox * startInc;
    QDoubleSpinBox * endInc;

    QToolButton * removeKeyPoseButton;

    double start = 0.0;
//    double maxDuration = 11.0;
    double end = 20.0;
    double cursor = 5.0;
//    double period = 1.0 /24.0;
//    double period = 1.0 /5.0;
//    double period = 1.0;
//    int i = 0;

//    int leftSpacerX;

    int * nbInterval;
    double * step;
    double * pixPerSec;
    double * zero;
    double * maxDuration;

    // question : why QSet is unordered
//    QSet<double> keyPoses;
    std::set<double> keyPoses;


    int iPaint = 0;
    //    bool rulerChanged =true;
    bool sliding = false;
    bool clicked = false;

//    QTimer * timer;
};

#endif // QFRAMESELECTOR_H
