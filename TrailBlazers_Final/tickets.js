const form = document.getElementById("form");
var nume = document.getElementById("nume");
var prenume = document.getElementById("prenume");
var email = document.getElementById("email");
var nrTelefon = document.getElementById("telefon");
const meci = document.getElementById("meciuri");

var pret=document.getElementById("pret");

//const URL="http://localhost:5000";
//var butonStergere=document.getElementById("butonStergere");
//divAfisare=document.getElementById("afisare");


form.addEventListener("submit", (e) => {
    let mesaj = [];
    let regexNumbers = /\d/
    let regexUsername = /^[A-Z]\w*[a-z]$/
    let regexEmail = /^\w*.\w*@\w+[.]com/
    let regexTelefon = /^07\d{8}/

    if (regexUsername.test(nume.value) === false) {
        mesaj.push("Numele trebuie sa contina doar litere si sa inceapa cu litera mare");
    }
    if (regexUsername.test(prenume.value) === false) {
        mesaj.push("Prenumele trebuie sa contina doar litere si sa inceapa cu litera mare");
    }
    if (regexNumbers.test(nume.value)) {
        mesaj.push("Numele nu poate contine cifre!");
    }
    if (regexNumbers.test(prenume.value)) {
        mesaj.push("Prenumele nu poate contine cifre!");
    }
    if (regexEmail.test(email.value) === false) {
        mesaj.push("Email Invalid ");
    }
    if (regexTelefon.test(nrTelefon.value) === false) {
        mesaj.push("Nr telefon invalid");
    }

    if (mesaj.length > 0) {
        alert(mesaj.join(', '));
        e.preventDefault();
    }
    else {
        mesaj.push("Veti fi redirectionat pentru plata si veti primi detalii la adresa ");
        mesaj.push(email.value);
        localStorage.setItem("nume_persoana", nume.value);
        localStorage.setItem("prenume_persoana", prenume.value);
        localStorage.setItem("email_persoana", email.value);
        alert(mesaj.join(": "));
        e.preventDefault();
        window.location.href = "./PlataBCR.html";


        // const data={nume: nume.value, prenume: prenume.value, email: email.value, loc: loc, pret: pret, meci: meci}
        // fetch(URL + '/buy', {
        //     method: 'POST',
        //     body: JSON.stringify(data),
        //     headers: {
        //         'content-type': 'application/json'
        //     }
        // })
        //     .then((response) => response.json())
        //     .then((response) => {
        //         form.reset();
        //         console.log(response);
        //     });
    }
});

// fetch(URL+'/tickets').then((response) => response.json())
//     .then((response)=>{
//         response=JSON.parse(response)
//         //console.log(response.table)
//         response.table.forEach((ticket)=>{
//             //console.log(ticket)
//             divAfisare.innerText+="Nume:"+ticket.nume+"\n"+
//             "Prenume:"+ticket.prenume+"\n"+
//             "Email:"+ticket.email+"\n"+
//             "Loc:"+ticket.loc+"\n"+
//             "Pret:"+ticket.pret+"\n"+
//             "Meci:"+ticket.meci+"\n"+
//             "%--------------------------%\n"})
//
//     })

let sem=0
function SchimbaPret(id) {
    let listaElem =document.querySelectorAll('.deSchimbat')
    switch (id) {
        case "basic":
            document.getElementById("pret").innerText = "$100";
            localStorage.setItem("pretul", "$100");
            localStorage.setItem("locul", document.getElementById(id).value);
            if(sem===1)
                for(let i=0;i<=listaElem.length-1;i++)
                    listaElem[i].classList.toggle('hidden')
            sem=0
            break;
        case "basic+":
            document.getElementById("pret").innerText = "$175";
            localStorage.setItem("pretul", "$175");
            localStorage.setItem("locul", document.getElementById(id).value);
            if(sem===1)
                for(let i=0;i<=listaElem.length-1;i++)
                    listaElem[i].classList.toggle('hidden')
            sem=0
            break;
        case "premium":
            document.getElementById("pret").innerText = "$350";
            localStorage.setItem("pretul", "$350");
            localStorage.setItem("locul", document.getElementById(id).value);
            if(sem===0)
                for(let i=0;i<=listaElem.length-1;i++)
                    listaElem[i].classList.toggle('hidden')
            sem=1
            if(document.getElementById("da").checked===true)
                document.getElementById("pret").innerText="$430"
            break;
    }
    console.log(pret.innerHTML);
}

function AdaugaPret(){
    document.getElementById("pret").innerText="$430"
    localStorage.setItem("pretul","$430")
}

function ScadePret(){
    document.getElementById("pret").innerText="$350"
    localStorage.setItem("pretul","$350")

}

let meciToggle=0
localStorage.setItem("meciul", meci.value);
function SchimbaMeci() {
    localStorage.setItem("meciul", meci.value);
    if(meci.value==="HOU") {
        document.getElementById("warningMeci").classList.toggle('hidden')
        meciToggle = 1
    }
    else{
        if(meciToggle===1)
            document.getElementById("warningMeci").classList.toggle('hidden')
            meciToggle=0
    }
}

if (localStorage.length >= 2) {
    document.getElementById("p1").innerText = localStorage.getItem("nume_persoana") + " " + localStorage.getItem("prenume_persoana");
    document.getElementById("p2").innerText = localStorage.getItem("email_persoana");
    document.getElementById("p3").innerText = localStorage.getItem("meciul");
}


// butonStergere.addEventListener("click", (e)=>{
//     var idStergere=document.getElementById("sterge").value;
//     fetch(URL+'/delete',{
//         method: 'DELETE',
//         body:idStergere
//     }).then((response)=>{
//         console.log(response);
//     })
// })

