<form name="form1" method="post" action="aksi_post.php">
    Masukkan Nama Anda : <input type="text" name="nama"> <br>
    <input type="submit" name="submit" value="Submit">
    <input type="reset" name="Submit2" value="Reset">
</form>
<?php
$a = $_POST['nama'];
echo ("Nama : " . $a . "<br>");
?>