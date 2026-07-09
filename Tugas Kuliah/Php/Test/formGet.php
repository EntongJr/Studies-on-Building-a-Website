<form name="form1" method="get" action="aksi_get.php">
    Masukkan Nama Anda : <input type="text" name="nama"> <br>
    <input type="submit" name="submit" value="submit">
    <input type="reset" name="Submit2" value="Reset">
</form>
<?php
$a = $_GET['nama'];
echo ("Nama : " . $a . "<br>");
?>