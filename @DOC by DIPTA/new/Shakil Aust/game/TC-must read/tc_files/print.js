function makeInvisible(){
var object = document.getElementById("onTop");
object.className = 'invisible';
object = document.getElementById("onLeft");
object.className = 'invisible';
object = document.getElementById("onRight");
object.className = 'invisible';
object = document.getElementById("onBottom");
object.className = 'invisible';
object = document.getElementById("printableLink");
object.className = 'invisible';
object = document.getElementById("navigableLink");
object.className = '';
return;
}
function makeNavigable(){
var object = document.getElementById("onTop");
object.className = '';
object = document.getElementById("onLeft");
object.className = '';
object = document.getElementById("onRight");
object.className = '';
object = document.getElementById("onBottom");
object.className = '';
object = document.getElementById("printableLink");
object.className = '';
object = document.getElementById("navigableLink");
object.className = 'invisible';
return;
}
