import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Pickers 1.0

FilePickerPage {
    id: root

    nameFilters: [
        '*.json'
    ]

    onSelectedContentPropertiesChanged: {
        pageStack.animatorPush("SecondPage.qml", { filePath: selectedContentProperties.filePath })
    }
}
