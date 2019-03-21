<?php
//getCityState.php

	$cityState = array("81611" => "Aspen, Colorado",);
	
	header("Content-Type: text/plain");
	$zip = $_GET["zip"];
	if (array_key_exists($zip. $cityState)
		print $cityState[$zip];
	else
		print ",";
?>