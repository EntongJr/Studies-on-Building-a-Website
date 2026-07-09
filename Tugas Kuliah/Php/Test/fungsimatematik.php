<?php
$nilai = 21.3451;

// Menggunakan <br> agar hasil tampil di baris baru pada browser
echo "Nilai Absolut Dari Nilai = " . abs($nilai) . "<br>";
echo "Nilai Pembulatan ke atas = " . ceil($nilai) . "<br>";
echo "Nilai Pembulatan ke bawah = " . floor($nilai) . "<br>";
echo "Nilai Pembulatan = " . round($nilai) . "<br>";
echo "Nilai Phi = " . pi() . "<br>";

$bilangan = 2;
echo "Nilai Pangkat 2 = " . pow($bilangan, 2) . "<br>";
echo "Nilai Pangkat 3 = " . pow($bilangan, 3) . "<br>";

// Menghasilkan angka acak antara 0 sampai 100
echo "Nilai Random = " . rand(0, 100) . "<br>";
