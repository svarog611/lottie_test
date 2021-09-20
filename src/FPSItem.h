#include <QQuickPaintedItem>

class FPSItem: public QQuickPaintedItem
{
    Q_OBJECT
public:
    Q_PROPERTY(int fps READ fps NOTIFY fpsChanged)

    FPSItem(QQuickItem *parent = 0);
    virtual ~FPSItem();

    void paint(QPainter *);

    int fps() const;

signals:
    void fpsChanged(int);

private:
    void recalculateFPS();

private:
    int m_currentFPS;
    int m_cacheCount;
    QVector<qint64> m_times;
};
