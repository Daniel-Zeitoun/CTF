<?php

$control= isset($_GET['control'])?$_GET['control']:'forum';
$action= isset($_GET['action'])?$_GET['action']:'accueil';

require ('./C/' .  $control . '.php');
$action();


