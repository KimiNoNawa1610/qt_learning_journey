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

    Map {
        anchors.fill: parent
        plugin: map_plugin
        center: QtPositioning.coordinate(33.670780, -117.864810)
        zoomLevel: 14

        // add a MapItemView to show the current navigation location
        MapItemView {
            delegate: MapQuickItem {
                anchorPoint.x: image.width / 2
                anchorPoint.y: image.height
                coordinate: model.coordinate
                sourceItem: Item {
                    width: 30
                    height: 30
                    Image {
                        id: image
                        source: "qrc:/ui/access/location-pin.png"
                    }
                }
            }
        }

        MapPolyline {
               line.width: 3
               line.color: 'green'
               path: [
                   { latitude: 33.670780, longitude: -117.864810},
                   { latitude: -27, longitude: 154.1 },
               ]
           }

        // connect the centerMap signal from System to update the map center
        Connections {
            target: systemHandler
            onCenterMap: {
                center = coordinates;
            }
        }

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

    NavigationSearchBox{
        id:search_box
        anchors{
            left:lock_icon.left
            top:lock_icon.bottom
            topMargin: 10
        }
        width:parent.width/3
        height:parent.height/12
    }

    Rectangle{
        id:util_map_bar
        anchors{
            top:search_box.top
            right:parent.right

        }
        height: parent.height/3
        width:parent.width/8
        color: "yellow"
        Text {
            id: util_place_holder
            text: qsTr("Util Bar")
            font.pixelSize: 20
        }
    }
}
