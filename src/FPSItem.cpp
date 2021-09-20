#include "FPSItem.h"

#include <QBrush>
#include <QDateTime>
#include <QPainter>

FPSItem::FPSItem(QQuickItem *parent) : QQuickPaintedItem(parent), m_currentFPS(0), m_cacheCount(0)
{
    m_times.clear();
    setFlag(QQuickItem::ItemHasContents);
}

FPSItem::~FPSItem()
{
}

void FPSItem::recalculateFPS()
{
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    m_times.push_back(currentTime);

    while (m_times[0] < currentTime - 1000)
        m_times.pop_front();

    int currentCount = m_times.length();
    m_currentFPS = (currentCount + m_cacheCount) / 2;

    if (currentCount != m_cacheCount)
        fpsChanged(m_currentFPS);

    m_cacheCount = currentCount;
}

int FPSItem::fps()const
{
    return m_currentFPS;
}

void FPSItem::paint(QPainter *painter)
{
    recalculateFPS();
    QBrush brush(Qt::yellow);

    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->drawRoundedRect(0, 0, boundingRect().width(), boundingRect().height(), 0, 0);
    update();
}
