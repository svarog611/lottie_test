#include "ImageVideoBuffer.h"

#include <QImage>

#include <QDebug>

ImageVideoBuffer::ImageVideoBuffer(QImage* image)
    : QAbstractVideoBuffer(NoHandle)
    , m_image(image)
    , m_mapMode(QAbstractVideoBuffer::NotMapped)
{}

ImageVideoBuffer::~ImageVideoBuffer()
{
    delete m_image;
}

QAbstractVideoBuffer::MapMode ImageVideoBuffer::mapMode() const
{
    return m_mapMode;
}

uchar* ImageVideoBuffer::map(MapMode mode, int* numBytes, int* bytesPerLine)
{
    uchar* result = nullptr;

    if (m_mapMode == NotMapped && m_image->bits() && mode != NotMapped)
    {
        m_mapMode = mode;

        if (numBytes)
            *numBytes = m_image->byteCount();

        if (bytesPerLine)
            *bytesPerLine = m_image->bytesPerLine();

        result = m_image->bits();
    }
    
    return result;
}

void ImageVideoBuffer::unmap()
{
    m_mapMode = NotMapped;
}
