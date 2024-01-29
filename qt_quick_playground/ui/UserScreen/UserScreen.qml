import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id:user_screen
    anchors{
        top:parent.top
        bottom:parent.bottom
        left:menu.right
    }
    width:parent.width
    height:parent.height
    anchors.horizontalCenter: parent.horizontalCenter

    Image{
        id:user_image
        anchors{
            left:user_screen.left
            top:user_screen.top
            leftMargin: 40
            topMargin: 20
        }
        width:parent.width/15
        fillMode:Image.PreserveAspectFit
        source: "qrc:/ui/access/profile.png"
    }

    // username
    Label {
        id:user_name
        text: "Username: Tester"
        font.bold: true
        font.pixelSize: 20
        anchors{
            top:user_image.top
            bottom:user_image.bottom
            left:user_image.right
            margins: 20
        }
    }

    // email
    Label {
        id:user_email
        anchors{
            left:user_screen.left
            top:user_image.bottom
            leftMargin: 40
            topMargin: 20
        }
        text: "Email: tester@gmail.com"
        font.pixelSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    // language
    ComboBox {
        id:user_language
        anchors{
            left:user_screen.left
            top:user_email.bottom
            leftMargin: 40
            topMargin: 20
        }
        font.pixelSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        editable: false
        model: ListModel {
            id: language_options
            ListElement { text: "English"}
            ListElement { text: "Vietnamese"}
            ListElement { text: "Thai"}
            ListElement { text: "Chinese"}
        }
    }

    // user role
    Label {
        id:user_role
        anchors{
            left:user_screen.left
            top:user_language.bottom
            leftMargin: 40
            topMargin: 20
        }
        text: "Role: Tester"
        font.pixelSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

}
