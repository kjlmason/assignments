//ch6-ex6.5.js
//Javascript file for exercise6.5

function newImage(ImageName) {
    document.getElementById('fruit').src = ImageName + '.jpg';
    document.getElementById('fruit').alt = ImageName;
}