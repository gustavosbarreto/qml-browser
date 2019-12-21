import QtQuick 2.0

MouseArea {
    property string href: ""

    onClicked: window.location = href
}
