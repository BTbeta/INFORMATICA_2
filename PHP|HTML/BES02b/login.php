<html>
<head>
	<title>loginB di Zeng</title>
</head>
<body>
	<h4>Richiesta credenziale per l'accesso all'area riservata</h4>
	<?php
	if(isset($_POST["username"])&&isset($_POST["password"])) 
	{
		$user=$_POST["username"];
		$password=$_POST["password"];
	
		if($user!="admin"||$password!="password")
		{
			echo"<h4>nome utente o password sbagliate</h4>";
		}
		else
		{
			echo"<h4>benvenuto</h4>";
		}
	}
	else
	{
		echo<<<END
			<form name="frmlogin" method="post" action="{$_SERVER['PHP_SELF']}">
			Username:<input type="text" name="username"><br>
			Password:<input type="password" name="password"><br>
			<input type="submit" name="submit">
			</form>
		END;
	}
	?>
</body>
</html>
