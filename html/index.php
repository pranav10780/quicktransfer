<!doctype html>
<html lang="">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>making</title>
	<link rel="stylesheet" href="css/style.css">
</head>

<body>
	<p>Choose an ip address from wherer you would like to send the files</p>

	<?php
	$file = "../ip_addr.txt";
	$fp = fopen($file,"r");
	if (!$fp) {
	    echo "File \"ip_addr.txt\"not found!";
	}

	if($fp){
		echo "<ul>";
		while (($line = fgets($fp)) !== false){
			$ip = trim($line);
			echo "<li><a href=\"http://$ip/\">$ip</a></li>";
		}
		echo "</ul>";
		fclose($fp);
	}
	?>
</body>

</html>
