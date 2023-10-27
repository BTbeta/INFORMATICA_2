<html>
<head>
	<title>loginA di zeng</title>
</head>
<body>
	<h3>controllo credenziali</h3>
	<?php
		$user = $_POST['username'];
		$password = $_POST['password'];
		if($user!="admin"||$password!="password"){
		echo"<h4>nome utente o password sbagliate</h4>";
		}
		else{
		echo"<h4>benvenuto</h4>";
		}
	?>
</body>
</html>
