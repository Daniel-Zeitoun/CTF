<?php

    function accueil() {
        
        if (!isset($_SESSION['profil']))
            $_SESSION['profil'] = "";

        include('./V/html_part/header.html');
        require('./V/index.html'); 
        require('./V/html_part/footer.html');
    }

    function login() {
        include('./V/html_part/header.html');
        require('./V/login.html'); 
        require('./V/html_part/footer.html');
    }

    function admin() {
        require('./V/admin.html'); 
    }

    function connect() {
        $login = isset($_POST['email'])?$_POST['email']:"tapez votre login";
        $pass = isset($_POST['password'])?$_POST['password']:"tapez votre pass";
        $profil = array();

        require('./M/userDB.php');
        
        if (verif_ident($login,$pass,$profil)) {
            session_start();
            $_SESSION['profil'] = $profil;
            accueil();
        }
        else {
            login();
            echo('<div class="alert alert-danger" name="err"><center>Erreur, identifiant ou mot de passe inconnu</center></div>');
        }
    }

    function disconnect() {
        session_destroy();
        header("Location: index.php");
    }


