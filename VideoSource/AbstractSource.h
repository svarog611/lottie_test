#pragma once

class QImage;

class AbstractSource
{
public:
    virtual ~AbstractSource(){}
    virtual void setImage(QImage* image) = 0;
};
