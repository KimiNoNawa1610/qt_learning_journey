import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    anchors.fill:parent
    StackView{
        id:stack_view
        anchors.fill:parent
        initialItem: "qrc:/ui/MainScreen/MainScreen.qml"
    }
}
