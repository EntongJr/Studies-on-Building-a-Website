const express = require("express")
const app = express()
const port = 3000
const bodyParser = require("body-parser")
const db = require("./connection")
const response = require("./response")

app.use(bodyParser.json())

app.get("/", (req, res) => {
    response(200, "API V1 Ready to Go", "Succes", res)
})

app.get("/mahasiswa", (req, res) => {
    const sql = "SELECT * FROM mahasiswa"
    db.query(sql, (err, fields) => {
        if (err) throw err
        response(200, fields,"mahasiwa get list", res)
    })
})

app.get("/mahasiswa/:nim", (req, res) => {
    const nim = req.params.nim
    const sql = `SELECT * FROM mahasiswa WHERE nim = ${nim}`
    db.query(sql, (err, fields) => {
        if (err) throw err
        response(200, fields, "Detail Data", res)
    })
})

app.post("/mahasiswa", (req, res) => {
    const {nim, namaLengkap, alamat} = req.body
    const sql = `INSERT INTO mahasiswa (nim, namaLengkap, alamat) VALUES (${nim}, ${namaLengkap}, ${alamat})`

    db.query(sql, (err, fields) => {
        if (err) response(500, "Invalid", "error", res)
        if (fields.affectedRows) {
            response(200, fields.insertId, "Data Added Sucessfuly", res)
        }
    })
})

app.put("/mahasiswa", (req, res) => {
    response(200, "INI PUT ATAU UPDATE DATA", res)
})

app.delete("/mahasiswa", (req, res) => {
    response(200, "INI DELETE DATA", res)
})

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})