<?php
	$f = fopen("./tmp/.restart", "r");
	$line = fgets($f);
	fclose($f);
	$c = fopen("./tmp/.restart", "w");
	fclose($c);
	echo trim($line);
?>
