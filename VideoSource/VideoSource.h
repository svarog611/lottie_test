#pragma once

#include <QAbstractVideoSurface>
#include <QObject>
#include <QTimer>
#include <QMediaObject>

#include "src/inc/rlottie.h"

//class QAbstractVideoSurface;

class VideoSource : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface)
    Q_PROPERTY(QString                fileName     READ fileName     WRITE setFileName     NOTIFY fileNameChanged)
    Q_PROPERTY(int                    fps          READ fps          WRITE setFps          NOTIFY fpsChanged)
    Q_PROPERTY(bool reversed READ reversed WRITE setReversed NOTIFY reversedChanged)
    Q_PROPERTY(qreal                  width        READ width        WRITE setWidth        NOTIFY widthChanged)
    Q_PROPERTY(qreal                  height       READ height       WRITE setHeight       NOTIFY heightChanged)
    Q_PROPERTY(int currentFrame READ currentFrame WRITE setCurrentFrame NOTIFY frameChanged)
    Q_PROPERTY(int frameCount READ frameCount WRITE setFrameCount NOTIFY frameCountChanged)

    explicit VideoSource(QObject* parent = nullptr);
    ~VideoSource() override;

    QAbstractVideoSurface* videoSurface() const;
    void setVideoSurface(QAbstractVideoSurface* surface);

    QString fileName() const;
    void setFileName(const QString& fileName);

    int fps() const;
    void setFps(int newFps);

    qreal width() const;
    void setWidth(qreal newWidth);

    qreal height() const;
    void setHeight(qreal newHeight);

    int currentFrame() const;
    void setCurrentFrame(int currentFrame);

    int frameCount() const;
    void setFrameCount(int frameCount);

    bool reversed() const;
    void setReversed(bool reversed);

signals:
    void fileNameChanged();
    void widthChanged();
    void heightChanged();
    void fpsChanged();

    void frameChanged(int currentFrame);
    void frameCountChanged(int frameCount);
    void reversedChanged(bool reversed);

private:
    void setImage(QImage* image);
    void closeSurface();

    void animateFrame();
    void incrementFrame();
    void decrementFrame();

private:
    int m_fps;

    int _currentFrame;
    int _frameCount;
    qreal _speed;
    bool _reversed;

    qreal m_width;
    qreal m_height;
    QAbstractVideoSurface* m_surface;
    std::unique_ptr<rlottie::Animation> _animation;
    QString m_fileName;
    QTimer m_timer;
};
