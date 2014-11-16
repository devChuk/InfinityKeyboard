import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: applicationWindow1
    y: 0
    visible: true
    width: 640
    height: 480
    color: "#ffffff"
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Image {
        id: bg
        x: 149
        y: 22
        width: applicationWindow1.width
        height: applicationWindow1.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        sourceSize.height: 1024
        sourceSize.width: 768
        fillMode: Image.Stretch
        source: "gradient-background-7-1920x1080.jpg"
    }

    Rectangle {
        id: tile1
        x: 40
        y: 340
        width: 50
        height: 100
        color: "#00000000"
        radius: 3
        anchors.left: parent.left
        anchors.leftMargin: 40
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        border.width: 2

        Text {
            id: qaz
            text: qsTr("Q   A   Z")
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            font.pixelSize: 24
        }

        MouseArea {
            id: qaz_ma
            hoverEnabled: true
            anchors.fill: parent
            onEntered: stateGroup.state = 'pressed'
            onExited: stateGroup.state = 'released'
        }
    }

    StateGroup {
        id: stateGroup
        states: [
            State {
                name: "pressed"

                PropertyChanges {
                    target: tile1
                    color: "#ff0000"
                }
            },
            State {
                name: "released"

                PropertyChanges {
                    target: tile1
                    color: "#00000000"
                }
            }

        ]
    }
}
