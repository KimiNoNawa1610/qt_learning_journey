import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15

// main screen
Rectangle{
    id:main_screen
    anchors{
        top:parent.top
        bottom:parent.bottom
        left:menu.right
    }
    width:parent.width-menu.width
    height:parent.height


    Plugin{
        id:map_plugin
        name:"osm" // can be changed to Esri or any other map, but will need addtional installation
    }

    Map{
        anchors.fill:parent
        plugin:map_plugin
        center:QtPositioning.coordinate(33.670780,-117.864810) // Oslo Qt company center
        zoomLevel: 14
    }

    Image{
        id:lock_icon
        anchors{
            left:parent.left
            top:parent.top
            margins:20
        }
        width:parent.width/25
        fillMode:Image.PreserveAspectFit
        source: (systemHandler.screenLocked ? "qrc:/ui/access/padlock_locked.png":"qrc:/ui/access/padlock_unclocked.png")
        MouseArea{
            anchors.fill: parent
            onClicked: {
                systemHandler.setScreenLocked(!systemHandler.screenLocked) // this will change the screen lock to unclock and vice versa

            }
        }

    }

    Text{
        id:date_time
        anchors{
            left:lock_icon.right
            leftMargin: 40
            bottom:lock_icon.bottom
        }
        font.pixelSize: 20
        font.bold: true
        color:"black"
        text:systemHandler.currentTime
    }

    Text{
        id:temperature
        anchors{
            left:date_time.right
            leftMargin: 40
            bottom:date_time.bottom
        }
        font.pixelSize: 20
        font.bold: true
        color:"black"
        text:systemHandler.temperature + "°F"
    }

    Image{
        id:user_icon
        anchors{
            left:temperature.right
            bottom:date_time.bottom
            leftMargin: 40
        }
        width:parent.width/35
        fillMode:Image.PreserveAspectFit
        source: "qrc:/ui/access/user.png"
    }

    Text{
        id:user_name
        anchors{
            left:user_icon.right
            bottom:date_time.bottom
        }
        font.pixelSize: 20
        font.bold: true
        color:"black"
        text:systemHandler.userName
    }
}
