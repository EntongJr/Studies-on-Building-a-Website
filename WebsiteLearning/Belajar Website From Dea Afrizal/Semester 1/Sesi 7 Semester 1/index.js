const http = require('http');
const host = '127.0.0.1'
const port = 3002

// request adalah = data yang masuk dari luar
// response adalah = data yang keluar dari sistem

const server = http.createServer(function (request, response) {
    const nama = "DIMAS SAKTI"
    const uang = 100000;
    const jajan = 50000;
    const sisa = uang - jajan;
    const hasil = `Nama Saya Adalah ${nama} Saya jajan sebanyak ${jajan}, uang saya tadinya ${uang} sekarang menjadi ${sisa}.`

    response.statusCode = 200;
    response.end(hasil);
});

server.listen(port, host, '', function () {
    console.log(`server menyala di ${host}:${port}`)
});