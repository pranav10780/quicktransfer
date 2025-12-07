<!-- the actaul page which takes ip as a param and makes a qr to enable the file tranfer -->
<?php
include "phpqrcode/qrlib.php";
QRcode::png('helo');
?>
