let i=1
function HidePictures(){
    let listaPoze=document.querySelectorAll('img')
    for(let i=0;i<=listaPoze.length-1;i++){
        listaPoze[i].classList.toggle('hidden')
    }
    i=i*(-1)
    if(i===-1)
        document.getElementById("ascunde").innerHTML="Afiseaza poze"
    else
        document.getElementById("ascunde").innerHTML="Ascunde poze"
}



