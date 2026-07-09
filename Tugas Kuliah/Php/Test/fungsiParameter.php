<?php
$nama = "Masukkan Nama Anda";
function bkn_reference($nama)
{
    $nama .= " Memang Tidak Guaul";
    echo ("<br>" . $nama);
}
bkn_reference($nama); // Pemanggilan prosedur
echo ("<br>Kata Tidak Gaul Hilang ==> " . $nama);

function reference(&$nama)
{
    $nama .= " Memang Paling Guaul";
    echo ("<br> <br>" . $nama);
}
reference($nama);
echo ("<br> Kata Tidak Gaul Masih ==>" . $nama); // Pemanggilan prosedur
