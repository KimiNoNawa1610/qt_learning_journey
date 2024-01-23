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

    // navigation bar
    LeftBar{
        id:menu
    }

    // main screen
    MainScreen{
        id:main_screen
    }



}
