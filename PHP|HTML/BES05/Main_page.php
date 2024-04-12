<html>
	<head>
		<title>Main_page</title>
	</head>
	<body>
		<br>
        <?php
            session_start();
            if (isset($_SESSION['Username'])) {
                $Username=$_SESSION['Username'];
                echo "<h1>home page</h1>";
                echo "<p>Benvenuto <?php $Username?> nella home page</p><br><br>";
                echo "<a href='BES05\Login.php'>ES05 - Area Riservata</a><br>";
            }
            else {
                echo "<h1>home page</h1>";
                echo "<p>Benvenuto ospite nella home page</p><br><br>";
                echo "<a href='BES05\Login.php'>Effetua Login</a><br>";
            }
        ?>	
	</body>
</html>