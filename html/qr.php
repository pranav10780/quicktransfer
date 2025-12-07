<?php
include "phpqrcode/qrlib.php";
$cmd = "ip -o -4 addr show $interface 2>/dev/null | awk '{print $4}' | cut -d/ -f1 | grep \"192\"";
QRcode::png(trim(shell_exec($cmd)));
?>
