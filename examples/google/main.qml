import QtQuick 2.12
import QtQuick.Layouts 1.1

Rectangle {
    Column {
        anchors.centerIn: parent
        spacing: 8

        Image {
            source: "logo.png"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            width: 400
            height: 30
            border.color: "#ccc"
            border.width: 1
            radius: 12

            TextInput {
                anchors.fill: parent
                anchors.leftMargin: 8
                anchors.rightMargin: 8
                topPadding: 8
                clip: true
                focus: true
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            height: 30
            spacing: 8

            Rectangle {
                color: "#eee"
                height: 30
                width: 180

                Text {
                    text: "Pesquisar"
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: window.alert("not implemented yet")
                }
            }

            Rectangle {
                color: "#eee"
                height: 30
                width: 180

                Text {
                    text: "Estou com sorte"
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: window.alert("not implemented yet")
                }
            }
        }

    }
}
