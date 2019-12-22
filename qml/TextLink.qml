import QtQuick 2.0

Text {
    property string href: ""

    LinkArea {
        href: parent.href
        anchors.fill: parent
    }
}
