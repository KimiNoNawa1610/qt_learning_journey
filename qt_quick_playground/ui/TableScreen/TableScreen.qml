import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls 1.4
import Qt.labs.qmlmodels 1.0

Item {
    width: 1126
    height: 800

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        TableView {
            anchors.fill: parent
            clip: true

            TableViewColumn {
                role: "customer"
                title: "Customer"
            }

            TableViewColumn {
                role: "address"
                title: "Address"
            }

            TableViewColumn {
                role: "mobile"
                title: "Mobile"
            }

            model: ListModel {

                ListElement {
                    customer: "h1"
                    address: "down1"
                    mobile: "345561"
                }
                ListElement {
                    customer: "h2"
                    address: "down2"
                    mobile: "345562"
                }
                ListElement {
                    customer: "h3"
                    address: "down3"
                    mobile: "345563"
                }
            }
        }
    }
}
