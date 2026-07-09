<?php
$nama = "Ahmad Latif"; // Variabel Dengan Tipe data String
$nilai_bhs = 2; // Variabel Dengan Tipe data Integer
$nilai_ipa = 2.5; // Variabel Dengan Tipe data Double
$bentuk_boolean = true; // Variabel dengan tipe data Boolean
echo ("Nama Mahasiswa =" . $nama . "<br>");
echo ("Nilai Bahasa = " . $nilai_bhs . "<br>");
echo ("Nilai IPA = " . $nilai_ipa . "<br>");
if ($bentuk_boolean == true) {
    echo ("Boolean Menunjukkan Nilai Benar <br>");
}
//Konfersi ke float
$nilai_bhs = (float)$nilai_bhs;
//Konfersi ke integer
$nilai_ipa = (int)$nilai_ipa;
echo ("Nilai Bahasa setelah dikonfersi float = " . $nilai_bhs . "<br>");
echo ("Nilai IPA Setelah dikonfersi integer= " . $nilai_ipa . "<br>");
