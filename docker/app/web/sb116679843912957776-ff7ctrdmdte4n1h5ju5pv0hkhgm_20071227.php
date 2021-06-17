<?php

// File name : sb116679843912957776-ff7ctrdmdte4n1h5ju5pv0hkhgm_20071227.php

echo('
<!DOCTYPE html>
<html>
    <head>
        <meta charset=\'utf-8\'>
        <title>Scotty</title>

    </head>

    <body>
        <form action="?action=ping" method="post" id="loginForm">
            <h3>Does the server reach the outside ?</h3>
            
            <div>
                <input type="text" placeholder="127.0.0.1" name="address" value="">
                <input class="button" type="submit" name="ping" value="ping">
            </div>
        </form>
    </body>
</html>
');


if (isset($_GET['action']) && $_GET['action'] != "" && isset($_POST['address']) && $_POST['address'] != "") {
    
    /** TODO --> SECURE THE ADDRESS INPUT
     *  Make a regex or find a specific function to validate the input of an IPv4 address format
     * 
     *  DONE --> Function filter_var()
     */

    // Specific PHP function to validate the right format of an IPv4 address
    $isValid = filter_var($_POST['address'], FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);
    
    if ($isValid) {
        $res = exec($_GET['action'] . " " . $_POST['address']);
        echo($_GET['action'] . " -c 4 " . $_POST['address'] . "<br>");
        echo($res);
    } 
    else {
        echo('IP address invalid !');
    }
}


