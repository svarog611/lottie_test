#pragma once

#include <QAbstractVideoBuffer>

class ImageVideoBuffer : public QAbstractVideoBuffer
{
public:
    ImageVideoBuffer(QImage* image);
    ~ImageVideoBuffer() override;

public:
    MapMode mapMode() const override;

    uchar* map(MapMode mode, int* numBytes = nullptr, int* bytesPerLine = nullptr) override;
    void unmap() override;

private:
    QImage* m_image;
    QAbstractVideoBuffer::MapMode m_mapMode;
};
