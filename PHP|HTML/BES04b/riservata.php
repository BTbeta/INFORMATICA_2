<?php
		session_start();
		if (!isset($_SESSION['user'])) {
			$url = 'login.php?error=Fare prima il login&from=';
			$url .= basename($_SERVER['PHP_SELF']);
			header("Location: $url");
			exit;
		}
?>
<html>
	<head>
		<title>benvenuto di zeng</title>
	</head>
	<body>
		<h1>benvenuto admin<h1>
		<a href="index.php">pagina principale</a><br><br>
		<a href="logout.php">logout</a>
	</body>
</html>