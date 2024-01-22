import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

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

}
