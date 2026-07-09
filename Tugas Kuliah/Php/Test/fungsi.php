<?php
function lingkaran($r)
{
    $hitung = pi() * $r * $r;
    return $hitung;
}
function tabung($tinggi, $luas_lingkaran)
{
    $volume_tabung = $tinggi * $luas_lingkaran;
    return $volume_tabung;
}
echo ("<br>Nilai  Volume Tabung :" . tabung(10, lingkaran(10)));
