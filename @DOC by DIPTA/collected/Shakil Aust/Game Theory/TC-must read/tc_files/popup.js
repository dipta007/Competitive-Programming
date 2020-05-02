var objPopUp = null;
// called when you popup at the bottom right of an object
function popUp(popper,popupID) {
    var pos = findPos(popper);
    var x = pos[0] + popper.offsetWidth + 2;
    var y = pos[1] + popper.offsetHeight + 2;
    popShow(x,y,popupID);
}
// called when you know the exact spot you want to pop up at
function popShow(posX,posY,popupID) {
    objPopUp = document.getElementById(popupID);
    objPopUp.style.left = posX + 'px';
    objPopUp.style.top = posY + 'px';
    objPopUp.style.display = 'block';
}
function popHide() {
    objPopUp.style.display = 'none';
    objPopUp = null;
}
function findPos(obj) {
    var curLeft = curTop = 0;
    if (obj.offsetParent) {
        curLeft = obj.offsetLeft;
        curTop = obj.offsetTop;
        while (obj = obj.offsetParent) {
            curLeft += obj.offsetLeft;
            curTop += obj.offsetTop;
        }
    }
    return [curLeft,curTop];
}
function postPopUpText(popupTextID,myText) {
    document.getElementById(popupTextID).innerHTML = myText;
}
