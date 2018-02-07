import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    Loader {
        id:loader
    }
    Button{
        text: "加载"
        onClicked: {
            loader.setSource("Watch.qml");
        }
    }


//    ScrollView {
//        anchors.fill: parent

//        ListView {
//            width: parent.width
//            model: 20
//            delegate: ItemDelegate {
//                text: "Item " + (index + 1)
//                width: parent.width
//            }
//        }
//    }
}
