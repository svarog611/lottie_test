#include "VideoSource_plugin.h"
#include "VideoSource.h"

#include <qqml.h>

void VideoSourcePlugin::registerTypes(const char* uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<VideoSource>(uri, 1, 0, "VideoSource");
}


