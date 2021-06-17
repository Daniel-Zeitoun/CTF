<?php

/* Old code to connect to MySQL, but not needed anymore because the government shut down the website

	$hote="localhost";
	$loginDB="scotty";
	$passDB="password123";
    $nameDB="hackathon_ctf";
    
    $bdd = new mysqli($hote, $loginDB, $passDB, $nameDB);
    if ($bdd->connect_errno) {
        die ('Connection failed :' . $bdd->connect_error);
    }
*/

    $nameDB="./M/ctf.sqlite";

    if (!class_exists('SQLite3'))
        die ("SQLite3 is not supported ...");
	$bdd = new SQLite3($nameDB);