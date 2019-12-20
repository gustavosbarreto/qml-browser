import QtQuick 2.6

Rectangle {
    width: 800
    height: 600

    focus: true

    color: "#fff"

    Timer {
        id: evalTimer
        interval: 500

        onTriggered: {
            if (playground.program != textEditor.text) {
                playground.program = textEditor.text;
                var playgroundItem = Qt.createQmlObject("import QtQuick 2.6\n"+textEditor.text, playground, "playgroundItem");
                if (playgroundItem) {
                    if (playground.item)
                        playground.item.destroy();

                    playground.item = playgroundItem;
                }
            }
        }
    }

    Rectangle {
        id: textEditorRect
        color: Qt.rgba(0, 0, 0, 0.7)
        width: parent.width/2
        height: parent.height

        TextEdit {
            id: textEditor
            focus: true

            anchors.fill: parent
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            anchors.topMargin: 10
            anchors.bottomMargin: 10

            color: "#fff"

            font.pixelSize: 18

            Keys.onPressed: {
                evalTimer.restart();
            }

            Keys.onTabPressed: {
                insert("    ");
            }

            function insert(s) {
                var before = text.slice(0, cursorPosition);
                var after = text.slice(cursorPosition);
                var pos = cursorPosition;
                text = before + s + after;
                cursorPosition = pos + s.length;
            }
        }
    }

    Item {
        id: playground

        property string program
        property variant item

        anchors.left: textEditorRect.right
        anchors.right: parent.right
	anchors.top: parent.top
	anchors.bottom: parent.bottom
    }
}
