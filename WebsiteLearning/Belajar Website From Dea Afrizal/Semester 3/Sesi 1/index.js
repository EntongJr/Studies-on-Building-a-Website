const express = require('express')
const app = express()
const port = 3000
const bodyParser = require('body-parser')
const db = require('./connection')
const response = require('./response')

app.use(bodyParser.json())

app.get("/", (req, res) => {
    response(200,"ini Data", "Masalahh", res)
})
app.get("/mahasiswa", (req, res) => {
    response(200, "Tabel Mahasiswa", res)
})
app.get("/mahasiswa/:nim", (req, res) => {
    const nim = req.params.nim
    response(200, `Tabel Mahasiswa ${nim}`, res)
})

app.post("/mahasiswa/", (req, res) => {
    response(200, "Ini Posting", res)
})

app.put("/mahasiswa", (req, res) => {
    response(200, "Ini Put", res)
})

app.delete("/mahasiswa", (req, res) => {
    response(200, "Ini Delete", res)
})

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})