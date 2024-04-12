<?php

function db_connection() {
    $hostname = "localhost";
    $dbname = "es05";
    $user = "ES05_user";
    $pass = "*40F87C79E26ABDA1D423339533256337181A4F64";
    $conn = mysqli_connect($hostname, $user, $pass, $dbname);
    if (!$conn) {
        die("Connessione al database fallita: " . mysqli_connect_error());
    }
}
function login($Username, $Password) {
  
    if(! isset($Username, $password)) 
      return array(false, "Inserire le proprie credenziali e premere il pulsante login.");
      
    if(empty($Username) || empty($password)) 
      return array(false, "Inserire le proprie credenziali e premere il pulsante login.");
  
    try {
      $sql = "SELECT Username, Password FROM es05 WHERE Username=:email LIMIT 1";
  
      if($rowCount == 1) {
        //l'utente esiste
        $db_userid = $row['id'];
        $db_username = $row['username'];
        $db_password = $row['password'];
        // Verifica che la password memorizzata nel database corrisponda alla password fornita dall'utente.
      // Verifica che la password memorizzata nel database corrisponda alla password fornita dall'utente.
      if($db_password == $password) { 
        // Password corretta! Login eseguito con successo.
        $_SESSION['userid'] = $db_userid; 
        $_SESSION['username'] = $db_username;
        return array(true, "Login eseguito correttamente");
      } else {
        // Password sbagliata.
        $_SESSION['userid'] = null;
        return array(false, "Attenzione! Password sbagliata.");
      }
    } else {
      // L'utente inserito non esiste.
      $_SESSION['userid'] = null;
      return array(false, "Attenzione! L'utente inserito non esiste.");
    }  
    
  } catch (Exception $e) {
    return array(false, "Attenzione! Errore: " . $e->getMessage());
  }
}