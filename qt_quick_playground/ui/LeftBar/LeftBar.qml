import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

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

    ColumnLayout{
        id: column_buttons
        height: parent.height/2
        width: left_bar.width
        spacing:0
        anchors{
            top:logo.bottom
            left: parent.left
            right: parent.right

        }

        Button{
            id:user_button
            width:parent.width
            text:"User Profile"
            onClicked:{if (main_loader.source!="qrc:/ui/UserScreen/UserScreen.qml"){
                    main_loader.setSource("qrc:/ui/UserScreen/UserScreen.qml")
                }
            }
        }

        Button{
            id:map_button
            width:parent.width
            text:"Map"
            onClicked:{
                if (main_loader.source!="qrc:/ui/MainScreen/MainScreen.qml"){
                    main_loader.setSource("qrc:/ui/MainScreen/MainScreen.qml")
                }
            }
        }

        Button{
            id:table_button
            width:parent.width
            text:"Table"
            onClicked:{if (main_loader.source!="qrc:/ui/TableScreen/TableScreen.qml"){
                    main_loader.setSource("qrc:/ui/TableScreen/TableScreen.qml")
                }
            }
        }

        Button{
            id:graph_button
            width:parent.width
            text:"Graph"
        }
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
