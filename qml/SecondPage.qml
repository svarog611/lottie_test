import QtQuick 2.0
import Sailfish.Silica 1.0
import Qt.labs.lottieqt 1.0
import FPSItem 1.0

Page {
    id: root

    property alias filePath: lottie.source

//    LottieImage {
//        id: lottie

//        width: parent.width
//        height: parent.height

//        anchors.centerIn: parent
//    }

    LottieAnimation {
        id: lottie
        anchors.centerIn: parent
        loops: 10
        quality: LottieAnimation.MediumQuality
//        source: "animation.json"
        autoPlay: false
        onStatusChanged: {
            if (status === LottieAnimation.Ready) {
                // any acvities needed before
                // playing starts go here
                gotoAndPlay(0);
            }
        }
        onFinished: {
            console.info("Finished playing")
        }
    }

    FPSItem {
        id: fps_text
        width: 100
        height: width

        Text {
            anchors.centerIn: parent
            text: fps_text.fps.toFixed()
        }
    }
}
