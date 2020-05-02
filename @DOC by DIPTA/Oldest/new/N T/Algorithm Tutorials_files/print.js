function setElementClass(elementName, className) {
    var object = document.getElementById(elementName);
    if(object != null) {
        object.className = className;
    }
}


function makeInvisible() {


    setElementClass("onTop",'invisible');
    setElementClass("onLeft",'invisible');
    setElementClass("onRight",'invisible');
    setElementClass("onBottom",'invisible');
    setElementClass("printableLink",'invisible');
    setElementClass("navigableLink",'');


    return;
}
function makeNavigable() {


    setElementClass("onTop",'');
    setElementClass("onLeft",'');
    setElementClass("onRight",'');
    setElementClass("onBottom",'');
    setElementClass("printableLink",'');
    setElementClass("navigableLink",'invisible');

    return;
}
