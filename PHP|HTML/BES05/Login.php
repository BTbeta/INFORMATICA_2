<?php
session_start();
// Costanti per la connessione al database
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'ES05_user');
define('DB_PASSWORD', 'mia_password');
define('DB_NAME', 'es05');

// Connessione al database
$conn = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_NAME);
// Verifica della connessione
if (!$conn) {die("Connessione fallita: " . mysqli_connect_error());}

//echo "Connessione al database riuscita";
// Recupera le credenziali dalla richiesta POST
$errmsg = $_GET['errmsg'] ?? "";
$username = $_POST['Username'] ?? "";
$password = $_POST['password'] ?? "";

// Esegui la query per verificare le credenziali dell'utente
$query = "SELECT * FROM utente WHERE Username = '$username' AND Password = '$password'";
echo $query . "<br>";
$result = mysqli_query($conn, $query);

// Verifica se la query ha restituito risultati
if(isset($_POST["submit"])) 
{
  if (mysqli_num_rows($result) == 1) {
      $errmsg ="Login riuscito. Benvenuto!"; // L'utente è autenticato con successo
      $_SESSION['Username']=$username;
      $_SESSION['Password']=$password;
      header("Location: AreaR.php");
  } else {
      $errmsg ="Credenziali non valide. Riprova."; // L'utente non è autenticato
  }
}
// Chiudere la connessione quando non è più necessaria
mysqli_close($conn);

?>
<!DOCTYPE html>
<html>
<head><title>Login</title></head>
<body>
  <h3>Pagina di login</h3>
  <style>.err {color: #FF0000;}</style>
	<p class="err"><?=$errmsg?></p>
  <form action="login.php" method="post">
    <label>Email <input type="text" name="Username" /></label><br />
    <label>Password <input type="password" name="password"/></label><br />
    <input type="submit" name="submit" value="Login" /><input type="reset" value="Cancel" />
  </form>
  <p>Non hai un account? <a href="register.php">Registrati adesso</a>.</p>        
</body>
</html>
