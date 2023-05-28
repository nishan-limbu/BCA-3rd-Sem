<?php

$con = new mysqli('localhost', 'root', '', 'taskmanagement'); //taskmanagement-> name of the database in phpMyAdmin

if(!$con){
  die(mysqli_error($con));
}

?>