import QtQuick 2.15
import QtCharts 2.15
import QtQuick.Window 2.15

Item{
    ChartView {
        title: "Lines"
        anchors.fill: parent
        antialiasing: true

        LineSeries {
            name: "A-Series"
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1.1; y: 2.1 }
            XYPoint { x: 1.9; y: 3.3 }
            XYPoint { x: 2.1; y: 2.1 }
            XYPoint { x: 2.9; y: 4.9 }
            XYPoint { x: 3.4; y: 3.0 }
            XYPoint { x: 4.1; y: 3.3 }
        }

        LineSeries {
            name: "B-Series"
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1.3; y: 1.1 }
            XYPoint { x: 2.9; y: 2.3 }
            XYPoint { x: 1.1; y: 3.1 }
            XYPoint { x: 4.9; y: 4.9 }
            XYPoint { x: 3.4; y: 5.0 }
            XYPoint { x: 3.1; y: 3.3 }
        }
    }
}
