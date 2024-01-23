import QtQuick 2.15

Rectangle {
    id:nav_search
    color:"#fff"
    radius:5
    Image{
        id:search_icon
        anchors{
            top:parent.top
            left:parent.left
            bottom:parent.bottom
            verticalCenter: parent.verticalCenter
            margins: 15
        }
        source:"qrc:/ui/access/search-interface-symbol.png"
        width:parent.width/7.5
        height:parent.height/7.5
        fillMode:Image.PreserveAspectFit
    }
    TextInput {
        id: search_input
        anchors{
            left:search_icon.right
            verticalCenter: parent.verticalCenter
        }
        width: parent.width / 2
        text:"Navigate"
        font.pixelSize: 20
        onEditingFinished: {
            // Handle input, e.g., output to console
            console.log("Entered Place:", text)
            systemHandler.navigateToLocation(text);
        }
    }

}
