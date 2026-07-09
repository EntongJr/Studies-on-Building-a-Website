const progres = [{
    nama: "Dimasakti",
    alamat: "Kemangi no 24",
    usia: 17,
    pekerjaan: "Masih Sekolah"
},
{
    nama: "Saktidimas",
    alamat: "burun no 29",
    usia: 23,
    pekerjaan: "progammer"
}
]
function getDetailData () {
    progres.map(function (result, i) {
        console.table(result)
    } )
    // console.log(`data yang anda cari adalah : ${progres.nama}`)
}