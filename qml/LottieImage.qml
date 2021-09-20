import QtQuick 2.0
import QtMultimedia 5.6
import VideoSource 1.0

Item {
    id: root

    property alias filePath: videoSource.fileName

    VideoSource {
        id: videoSource

        width: parent.width
        height: parent.height
        reversed: false
    }

    VideoOutput {
        id: videoOutput

        anchors.fill: parent

        source: videoSource
        fillMode: VideoOutput.Stretch
    }
}
