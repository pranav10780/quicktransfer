<!doctype html>
<html lang="">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>making</title>
	<link rel="stylesheet" href="css/style.css">
</head>

<body>
	<p>Scan the qr code on moobile</p>
	<img src="qr.php" alt="QR code">
	<?php
	$cmd = "ip -o -4 addr show $interface 2>/dev/null | awk '{print $4}' | cut -d/ -f1 | grep \"192\"";
	echo trim(shell_exec($cmd));
	?>
</body>

</html>
