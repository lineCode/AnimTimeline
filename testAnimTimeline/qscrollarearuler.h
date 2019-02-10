#ifndef QSCROLLAREARULER_H
#define QSCROLLAREARULER_H

#include <QObject>
#include <QScrollArea>
#include <QWidget>

class QScrollAreaRuler : public QScrollArea {
    Q_OBJECT
public:
    explicit QScrollAreaRuler(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

signals:
    void changePrecision(int accuracy);

public slots:

private:
    bool ctrlDown;
    bool midMouseDown;

    int mousePosX;
    int sliderPos;
};

#endif // QSCROLLAREARULER_H