<html>
	<head>
		<title>Main_page</title>
	</head>
	<body>
		<br>
        <?php
            session_start();
            $Username=$_SESSION['Username'] ?? "Ospite";
            echo "<h1>home page</h1>";
            echo "<p>Benvenuto $Username nella home page</p><br><br>";
            if ($Username=='Ospite') {
                echo "<a href='Login.php'>Effetua Login</a><br>";
            }
            else {
                echo "<a href='AreaR.php'>Area Riservata</a><br>";
                echo "<a href='Logout.php'>Disconessione</a><br>";
            }
        ?>	
	</body>
</html>