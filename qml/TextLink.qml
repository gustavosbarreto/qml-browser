import QtQuick 2.0

Text {
    property string href: ""

    LinkArea {
        href: href
        anchors.fill: parent
    }
}
