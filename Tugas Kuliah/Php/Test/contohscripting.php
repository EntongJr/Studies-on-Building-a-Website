<?php
function ketiga()
{
    $hitung = 4 + 7;
    return $hitung;
}
echo (ketiga());
function keempat($sisi)
{
    $luas_persegi = $sisi * $sisi;
    return $luas_persegi;
}
?> //Kode Scriptlet
<?= keempat(4) ?> //Kode Expresi, kode ini akan langsung menampilkan hasil output, tanpa menuliskan perintah echo atau printf