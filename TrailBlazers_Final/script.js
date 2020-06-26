/*
1. Se instaleaza node.js
2. Se instaleaza json-server
3. Se insereaza ajax in fisierul HTML
4. Nu uitati sa porniti json-server pentru fisierul JSON pe care il folositi (db.json)
*/


/*
URL -> path-ul unde se face requestul
TYPE: GET/POST/PUT/DELETE
dataType: doar in cazul request-urilor de tip GET, tipul de date intors (in general json)
data: body-ul trimis pe request, in cazul request-urilor de tip POST/PUT; puteti sa vedeti ce
        ati trimis in inspect -> network -> request-ul facut -> header -> ultima informatie
 */
function getTickets() {
    $.ajax({
        url: 'http://localhost:3000/bilete',
        type: 'GET',
        dataType: 'json',
        success: function (data) {
            console.log(data);
        },
        error: function (data) {
            console.log(data);
        }
    });

}

/*
ATENTIE!

Cand vreti sa va folositi de o functie care aduce date apelarea urmatoarei functii se face
la success, pentru ca JavaScript este un limbaj asincron si nu am invatat cum sa gestionam asta
 */
function getOneTicket(id) {
    $.ajax({
        url: 'http://localhost:3000/bilete?id=' + id,
        type: 'GET',
        dataType: 'json',
        success: function (data) {
            updateTicket(data[0])
        }
    });
}

function insertTicket() {
    var name = document.getElementById("name").value;
    var meci=document.getElementById("meci").value;
    var bilet = {
        nume: name,
        meci: meci
    }
    $.ajax({
        url: 'http://localhost:3000/bilete',
        type: 'POST',
        data: bilet,
        success: function (data) {
            console.log(data)
        },
        error: function (error) {
            console.log(error);
        }
    });
}

/*
ATENTIE!

Desi in general puteti adauga date pe url asa: '/path?id=' + id
libraria json-server are un bug si se adauga asa: 'path/' + id
*/
function updateTicket(bilet) {
    var newMeci = document.getElementById("updateTicket").value;
    bilet.meci = newMeci;
    $.ajax({
        url: 'http://localhost:3000/bilete/2',
        type: 'PUT',
        data: bilet,
        success: function (data) {
            console.log(data);
        }
    })
}

/*
DELETE -> nu intoarce nimic
*/
function deleteTicket() {
    var id = document.getElementById("dogId").value;
    $.ajax({
        url: 'http://localhost:3000/bilete/' + id,
        type: 'DELETE',
        success: function (data) {
            console.log(data);
        }
    })
}
