//popcornA.js
//Javascript code for popcornA.html document

function getPlace(zip) {
    var xhr = new XMLHttpRequest();


    //register reciever as handler
    xhr.onreadystatechange = function () {
        if (xhr.readyState == 4 && xhr.status == 200) {
            var result = xhr.responseText;
            var place = result.split(', ');
            if (document.getElementById("city").value == "")
                document.getElementById("city").value = place[0];
            if (document.getElementById("state").value == "")
                document.getElementById("state").value = place[1];
        }


    }
    xhr.open("GET", "getCityState.php?zip=" + zip);
    xhr.send(null)
}