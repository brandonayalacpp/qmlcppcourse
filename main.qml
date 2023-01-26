import QtQuick 2.3
import QtQuick.Window 2.12
import QtQuick.Controls 1.2

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    Connections
//    {
//        target: MessageClass
//        onMessageChange: textId.text = value;
//    }

    function logger(element)
    {
        print("Array element " + element)
    }

    function logArray(someArray)
    {
        someArray.forEach(logger)
    }

    function logMap(someMap)
    {
        for(var element in someMap)
        {
            print("some item", element, "=", someMap[element] )
        }
    }

    function javaScriptFunction(value)
    {
        print("c++ called the javaScriptFunction with parameter" + value);
        return "this message was return from java scriptfunction";
    }

    Column
    {
        Text
        {
            id: textId
            text: MessageClass.message
        }
        Button
        {
            text: "Change text"
            onClicked: MessageClass.doMessageChange()
        }
        Button
        {
            text: "New Button"
            onClicked:{
                var result = MessageClass.sendMessageFromCpp("This is QML")
                print("result:" + result)
            }
        }
    }

}
