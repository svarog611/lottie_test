#include "VideoSource.h"
#include "ImageVideoBuffer.h"

#include <QVideoSurfaceFormat>
#include <QFile>

#include <QElapsedTimer>
#include <QDebug>

VideoSource::VideoSource(QObject* parent)
    : QObject(parent)
    , m_fps(60)
    , _currentFrame(0)
    , _frameCount(0)
    , m_surface(nullptr)
{
    connect(&m_timer, &QTimer::timeout, this, &VideoSource::animateFrame);

    m_timer.setInterval(1000 / m_fps);
    m_timer.start();
}

VideoSource::~VideoSource()
{
    m_timer.stop();
    closeSurface();
}

QAbstractVideoSurface* VideoSource::videoSurface() const
{
    return m_surface;
}

QString VideoSource::fileName() const
{
    return m_fileName;
}

void VideoSource::setFileName(const QString& fileName)
{
    if (m_fileName != fileName)
    {
        m_fileName = fileName;
        emit fileNameChanged();

        _animation = rlottie::Animation::loadFromFile(fileName.toStdString());
        setFrameCount(_animation->totalFrame());
    }
}

void VideoSource::setVideoSurface(QAbstractVideoSurface* surface)
{
    closeSurface();
    m_surface = surface;
}

void VideoSource::setImage(QImage* image)
{
    if (m_surface)
    {
        if (!m_surface->isActive())
            m_surface->start(QVideoSurfaceFormat(image->size(), QVideoFrame::Format_ARGB32));

        m_surface->present(QVideoFrame(new ImageVideoBuffer(image), image->size(), QVideoFrame::Format_ARGB32));
    }
    else
        delete image;
}

int VideoSource::fps() const
{
    return m_fps;
}

void VideoSource::setFps(int newFps)
{
    if (m_fps != newFps)
    {
        m_fps = newFps;
        emit fpsChanged();
    }
}

qreal VideoSource::width() const
{
    return m_width;
}

void VideoSource::setWidth(qreal newWidth)
{
    if (!qFuzzyCompare(m_width, newWidth))
    {
        m_width = newWidth;
        emit widthChanged();
    }
}

qreal VideoSource::height() const
{
    return m_height;
}

void VideoSource::setHeight(qreal newHeight)
{
    if (!qFuzzyCompare(m_height, newHeight))
    {
        m_height = newHeight;
        emit heightChanged();
    }
}

void VideoSource::closeSurface()
{
    if (m_surface && m_surface->isActive())
        m_surface->stop();
}

void VideoSource::animateFrame()
{
    if (reversed()) {
        decrementFrame();
    } else {
        incrementFrame();
    }

    QElapsedTimer t;
    t.start();
    QImage* _frameImage = new QImage(QSize(m_width, m_height), QImage::Format_ARGB32_Premultiplied);
    rlottie::Surface _frameSurface =
            rlottie::Surface(reinterpret_cast<uint32_t *>(_frameImage->bits()), _frameImage->width(), _frameImage->height(), _frameImage->bytesPerLine());
    _animation->renderSync(_currentFrame, _frameSurface);
    qDebug() << "render took" << t.elapsed();
    setImage(_frameImage);
}

void VideoSource::incrementFrame()
{
    if (currentFrame() < (frameCount() - 1))
        setCurrentFrame(currentFrame() + 1);
    else
        setCurrentFrame(0);
}

void VideoSource::decrementFrame()
{
    if (currentFrame() >= 0) {
        setCurrentFrame(currentFrame() - 1);
    } else {
        setCurrentFrame((frameCount() - 1));
    }
}

void VideoSource::setCurrentFrame(int currentFrame)
{
    if (_currentFrame == currentFrame)
        return;

    _currentFrame = currentFrame;
    emit frameChanged(_currentFrame);
}

void VideoSource::setReversed(bool reversed)
{
    if (_reversed == reversed)
        return;

    _reversed = reversed;
    emit reversedChanged(_reversed);
}

int VideoSource::frameCount() const
{
    return _frameCount;
}

int VideoSource::currentFrame() const
{
    return _currentFrame;
}

bool VideoSource::reversed() const
{
    return _reversed;
}

void VideoSource::setFrameCount(int frameCount)
{
    if (_frameCount == frameCount)
        return;

    _frameCount = frameCount;
    emit frameCountChanged(_frameCount);
}
