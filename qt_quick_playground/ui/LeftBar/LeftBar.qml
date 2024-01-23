import QtQuick 2.15

// making the rectangle menu
Rectangle{
    id:left_bar
    anchors{
        top:parent.top
        bottom:parent.bottom
    }
    color:"black"
    height:parent.height
    width:parent.width/9


    // Gaill logo
    Image {
        id: logo
        anchors{
            top:parent.top
            left:parent.left
            right:parent.right
        }
        width:parent.width/5
        fillMode:Image.PreserveAspectFit
        source: "qrc:/ui/access/beaglelogo 2.a3bd98fa2d5dc31fff04.png"
    }

    // Settings
    // Image {
    //     id: settings
    //     anchors{
    //         topMargin: 30
    //         top:logo.bottom
    //         left:parent.left
    //         right:parent.right
    //     }
    //     width:parent.width/15000
    //     fillMode:Image.PreserveAspectFit
    //     source: "qrc:/ui/access/cogwheel.png"
    // }

}
