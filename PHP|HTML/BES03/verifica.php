<html>
<head>
	<title>verifica di Zeng</title>
</head>
<body>
	<h4>validazione dati</h4>
	<?php
	$Nome=$_POST["Nome"];
	$Cognome=$_POST["Cognome"];
	$Data=$_POST["Data"];
	$Codice_fiscale=$_POST["Codice_fiscale"];
	$Email=$_POST["Email"];
	$Cellulare=$_POST["Numero_di_telefono"];
	$via_piazza=$_POST["via/piazza"];
	$Cap=$_POST["Cap"];
	$Comune=$_POST["Comune"];
	$Provincia=$_POST["Provincia"];
	$Nickname=$_POST["Nickname"];
	$Password=$_POST["Password"];
	
	if (preg_match("/^[a-zA-Z ]*$/", $Nome)) {
		echo "Nome:";
		echo trim($Nome);
		echo "<br>";
	} else {
	  echo "<font color='red'>$Nome non si può mettere numeri e carateri speciali</font>";
	  echo "<br>";
	}

	if (preg_match("/^[a-zA-Z' ]*$/", $Cognome)) {
		echo "Cognome:";
		echo trim($Cognome);
		echo "<br>";
	} else {
	  echo "<font color='red'>$Cognome non si può mettere numeri e carateri speciali ecceto</font>";
	  echo "<br>";
	}

	if (preg_match("/^[a-zA-Z0-9]*$/", $Codice_fiscale)) {
		echo "Codice fiscale:$Codice_fiscale<br>";
	} else {
	  echo "<font color='red'>$Codice_fiscale non è valido</font>";
	  echo "<br>";
	}
	
	if (filter_var($Email, FILTER_VALIDATE_EMAIL)) {
		echo "Email:$Email";
		echo trim($Email);
		echo "<br>";
	} else {
	  echo "<font color='red'>$email non è valido</font>";
	  echo "<br>";
	}

	if (preg_match("/^39[0-9]*$/", $Cellulare)) {
		echo "Cellulare:$Cellulare<br>";
	} else {
	  echo "<font color='red'>$Cellulare non è valido</font>";
	}

	if (preg_match("/^[a-zA-Z' ]*$/", $via_piazza)) {
		echo "Via/Piazza:";
		echo trim($via_piazza);
		echo "<br>";
	} else {
	  echo "<font color='red'>$via_piazza non si può mettere carateri speciali e numeri</font>";
	  echo "<br>";
	}
	
	if (preg_match("/^[0-9]*$/", $Cap)) {
		echo "Cap:$Cap<br>";
	} else {
	  echo "<font color='red'>$Cap è sbagliato</font>";
	  echo "<br>";
	}
	
	if (preg_match("/^[a-zA-Z' ]*$/", $Comune)) {
		echo "Comune:";
		echo trim($Comune);
		echo "<br>";
	} else {
	  echo "<font color='red'>$Comune è sbagliato</font>";
	  echo "<br>";
	}
	
	if (preg_match("/^[a-zA-Z' ]*$/", $Provincia)) {
		echo "Provincia:";
		echo trim($Provincia);
		echo "<br>";
	} else {
	  echo "<font color='red'>$Provincia è sbagliato</font>";
	}
	
	if ($Nickname!=$Nome) {
	echo "Nickname:$Nickname<br>";
	} else {
	  echo "<font color='red'>$Nickname non si può mettere carateri speciali e numeri</font>";
	}
	
	if (preg_match("/^[[a-z]+[A-Z]+[0-9]+]{8,}+$/", $Password)) {
	echo "Password:$Password";
	} else {
	  echo "<font color='red'>$Password è troppo corto o non ha ragiunto i requesiti</font>";
	}
	?>
</body>
</html>
