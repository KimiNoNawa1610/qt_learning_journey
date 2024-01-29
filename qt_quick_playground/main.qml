import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.VirtualKeyboard 2.15
import "ui/LeftBar"
import "ui/MainScreen"


Window {
    id: window
    width: 1280
    height: 720
    visible: true
    title: qsTr("GAILL MOCK")
    //property alias stack:stack_view // expose the stack view

    // navigation bar
    LeftBar{
        id:menu
    }

    Loader{
        id:main_loader
        anchors{
            left:menu.right
            right:parent.right
            top:parent.top
            bottom:parent.bottom
        }
        source:"qrc:/ui/MainScreen/MainScreen.qml"
    }






}
