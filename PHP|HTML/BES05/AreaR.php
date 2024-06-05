<html>
	<head>
		<title>AreaRiservata</title>
	</head>
	<body>
		<br>
        <?php
            session_start();
            $Username=$_SESSION['Username'];
            echo "<h1Area Riservata</h1>";
            echo "<p>Benvenuto $Username nella home page</p><br><br>";
            echo "<a href='index.php'>torna alla Home page</a><br>";
            echo "<a href='Logout.php'>Disconessione</a><br>";
        ?>	
	</body>
</html>