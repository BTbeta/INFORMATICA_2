<?php
session_start();

require 'functions.php';
// Costanti per la connessione al database
db_connection()
//echo "Connessione al database riuscita";
// Recupera le credenziali dalla richiesta POST
$errmsg = $_GET['errmsg'] ?? "";
$username = $_POST['Username'] ?? "";
$password = $_POST['password'] ?? "";

// Verifica se la query ha restituito risultati
if(isset($_POST["submit"])) 
{
  $errmsg=login($Username, $Password)
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

