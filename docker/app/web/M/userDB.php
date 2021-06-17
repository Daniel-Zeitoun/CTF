<?php

function verif_ident($login,$pass,&$profil) {
    require("./M/connectDB.php");

    $query = "SELECT * FROM users WHERE username = '$login' AND password = '$pass'";

    $res = $bdd->query($query);
    $row = $res->fetchArray();

    if ($row) {
		$profil = $row;
        return true;
    }

    return false;
}
