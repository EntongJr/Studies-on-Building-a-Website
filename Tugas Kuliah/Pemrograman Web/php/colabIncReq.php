<?php
$nama = "Achmad Dimas Sakti";
echo ("<br> Hallo Nama Saya Adalah " . $nama);
function salam()
{
    global $nama;
    echo ("<br> Hallo Nama Saya Adalah " . $nama);
}
