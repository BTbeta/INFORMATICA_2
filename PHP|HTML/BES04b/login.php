<?php
session_start();
if (isset($_SESSION['user'])) {
	header('Location: riservata.php');
	exit();
}
$errmsg = $_GET['errmsg'] ?? "";
$user = $_POST["username"] ?? "";
$password = $_POST["password"] ?? "";

if(isset($_POST["submit"])) 
{
	if($user!="admin" || $password!="password")
	{
		$errmsg = "Credenziali sbagliate";
	}
	else
	{
		$_SESSION['user']=$user;
		header("Location: riservata.php");
		exit;
	}
}
?>
<html>
<head>
	<title>login di zeng</title>
</head>
<body>
	<style>.err {color: #FF0000;}</style>
	<p class="err"><?=$errmsg?></p>
	<form name="frmlogin" method="post" action="<?=$_SERVER['PHP_SELF']?>">
	Username:<input type="text" name="username"><br>
	Password:<input type="password" name="password"><br>
	<input type="hidden" name="from" value="<?=$from?>" />
	<input type="submit" name="submit">
	</form>
	<a href="index.php">torna pagina principale</a>
</body>
</html>