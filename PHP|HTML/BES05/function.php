<?php

function db_connection() {
    $hostname = "localhost";
    $dbname = "es05";
    $user = "ES05_user";
    $pass = "mia_password";
    $conn = mysqli_connect($hostname, $user, $pass, $dbname);
    if (!$conn) {
        die("Connessione al database fallita: " . mysqli_connect_error());
    }
    return;
}
function login($Username, $Password) {
  
    if(! isset($Username, $password)) 
      return array(false, "Inserire le proprie credenziali e premere il pulsante login.");
      
    if(empty($Username) || empty($password)) 
      return array(false, "Inserire le proprie credenziali e premere il pulsante login.");
  
    try {
      $query = "SELECT * FROM utente WHERE Username = '$username' AND Password = '$password'";
      $result = mysqli_query($conn, $query);
      if(mysqli_num_rows($result)==1) {
        //l'utente esiste
        $db_username = $row['username'];
        $db_password = $row['password'];
        // Verifica che la password memorizzata nel database corrisponda alla password fornita dall'utente.
      // Verifica che la password memorizzata nel database corrisponda alla password fornita dall'utente.
      if($db_password == $password) { 
        // Password corretta! Login eseguito con successo.
        $_SESSION['Username']=$db_username;
        $_SESSION['Password']=$db_password;
        return array(true, "Login eseguito correttamente");
      } else {
        // Password sbagliata.
        return array(false, "Attenzione! Password sbagliata.");
      }
    } else {
      // L'utente inserito non esiste.
      return array(false, "Attenzione! L'utente inserito non esiste.");
    }  
    
  } catch (Exception $e) {
    return array(false, "Attenzione! Errore: " . $e->getMessage());
  }
}