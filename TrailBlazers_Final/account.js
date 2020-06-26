const final = new Date()
final.setFullYear(2020, 5, 26)
final.setHours(17, 8, 20, 0)

var acum = new Date()
var diff = final - acum

var z = Math.floor(diff / 1000 / 3600 / 24)
var o = Math.floor(diff / 1000 / 3600) % 24
var m = Math.floor(diff / 1000 / 60) % 60
var s = Math.floor(diff / 1000) % 60

document.getElementById("ziua").innerHTML = z
document.getElementById("ora").innerHTML = o
document.getElementById("minut").innerHTML = m
document.getElementById("secunda").innerHTML = s


setInterval(() => {
    s--
    if (s < 0) {
        s = 59
        m--
        if (m < 0) {
            m = 59
            o--
            if (o < 0) {
                o = 23
                z--
                if(z<0)
                    clearInterval()
            }
        }
    }
    document.getElementById("ziua").innerHTML = z
    document.getElementById("ora").innerHTML = o
    document.getElementById("minut").innerHTML = m
    document.getElementById("secunda").innerHTML = s
}, 1000);

function Move(){
    let minge=document.getElementById("animatie")
    let pozitie=0
    let unghi=0

    setInterval(()=>{
        if(pozitie === 1704)
            clearInterval()
        else{
            pozitie=pozitie+1.5
            minge.style.left=pozitie+"px"
        }
    },2)

    setInterval(()=>{
        if(pozitie === 1704)
            clearInterval()
        else{
            minge.style.transform = "rotate("+unghi+"deg)"
            unghi=unghi+2
        }
    },5)

}
