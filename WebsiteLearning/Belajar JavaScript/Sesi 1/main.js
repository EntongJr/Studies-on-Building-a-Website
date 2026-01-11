// Function Menghitung Luas Lingkaran
function lingkaran() {
    const jaring = Number(prompt('Berapa Jari-Jarinya?'))
    const x = 3.14*jaring*jaring
    alert(`Jari-Jarinya = ${jaring}, Jadi Luasnya Adalah ${x}`)
}

function segitiga() {
    const alas = Number(prompt('Berapa Alasnya?'))
    const tinggi = Number(prompt('Berapa Tingginya?'))
    const luasSegitiga = (alas*tinggi)/2
    alert(`Segitiga mempunyai alas = ${alas} dan mempunyai tinggi = ${tinggi}, Jadi luas segitiganya adalah ${luasSegitiga}`)
}
function persegiPanjang() {
    const panjang = Number(prompt('Berapa Panjangnya?'))
    const lebar = Number(prompt('Berapa Lebarnya?'))
    const luasPersegiPanjang = panjang*lebar
    alert(`Persegi Panjang mempunyai Panjang = ${panjang} dan mempunyai lebar = ${lebar}, Jadi luas Persegi panjang adalah ${luasPersegiPanjang}`)
}
function jajarGenjang() {
    const alas = Number(prompt('Berapa Alasnya'))
    const tinggi = Number(prompt('Berapa Tingginya'))
    const luasJajarGenjang = (alas*tinggi)
    alert(`Jajar Genjang mempunyai alas = ${alas} dan mempunyai tinggi = ${tinggi}, Jadi luas Jajar Genjang adalah ${luasJajarGenjang}`)
}

function gajiKaryawan() {
    const nama = prompt('Nama Karyawanya Siapa?')
    const gjp = Number(prompt('Gaji Per-Harinya Berapa?'))
    const hari = Number(prompt('Sebulan Masuk Berapa?'))
    const gaji = gjp*hari
    alert(`Karyawan Bernama ${nama}, Masuk Berapa Hari ${hari},dan Gaji Perharinya Adalah Rp.${gjp}, Jadi Total Gajinya Selama Sebulan Adalah Rp.${gaji}`)
}