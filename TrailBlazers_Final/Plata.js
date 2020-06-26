const form = document.getElementById("form2")
const pin = document.getElementById("pin")
const data = document.getElementById("dataExp")

form.addEventListener('submit', (e) => {
    let lista = [];
    let regexPin = /^\d{4}\s\d{4}\s\d{4}\s\d{4}$/
    let regexdata=/^(0\d|1[012])[/]\d{2}$/

    if (regexPin.test(pin.value) === false)
        lista.push("Pin invalid");

    if(regexdata.test(data.value)=== false)
        lista.push("data invalida");

    if (lista.length > 0) {
        e.preventDefault();
        alert(lista.join(', '));
    } else {
        lista.push("Plata efectuata cu succes!");
        e.preventDefault();
        alert(lista.join(", "));
        window.location.href = "./Tickets.html";
    }


});