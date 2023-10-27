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
	
	if (preg_match("/^[a-zA-Z ]$/", $Nome)) {
	echo "Nome:"trim($Nome);
	} else {
	  echo "$Nome non si può mettere numeri e carateri speciali";
	}
	
	if (preg_match("/^[a-zA-Z' ]$/", $Cognome)) {
	echo "Cognome:"trim($Cognome);
	} else {
	  echo "$Cognome non si può mettere numeri e carateri speciali ecceto'";
	}
	if (preg_match("/^[a-zA-Z0-9]$/", $Codice_fiscale)) {
	echo "Codice fiscale:$Codice_fiscale";
	} else {
	  echo "$Codice_fiscale non è valido";
	}
	
	if (filter_var($Email, FILTER_VALIDATE_EMAIL)) {
	echo "Email:$Email";
	} else {
	  echo "$email non è valido";
	}

	if (preg_match("/^39[0-9]$/", $Cellulare)) {
	echo "Cellulare:$Cellulare";
	} else {
	  echo "$Cellulare non è valido";
	}

	if (preg_match("/^[a-zA-Z' ]$/", $via_piazza)) {
	echo "Via/Piazza:"trim($via_piazza);
	} else {
	  echo "$via_piazza non si può mettere carateri speciali e numeri";
	}
	
	if (preg_match("/^[0-9]{5}$/", $Cap)&&) {
	echo "Cap:$Cap";
	} else {
	  echo "$Cap è sbagliato";
	}
	
	if (preg_match("/^[a-zA-Z' ]$/", $Comune)&&) {
	echo "Comune:"trim($Comune);
	} else {
	  echo "$Comune è sbagliato";
	}
	
	if (preg_match("/^[a-zA-Z' ]$/", $Provincia)&&) {
	echo "Provincia:"trim($Provincia);
	} else {
	  echo "$Provincia è sbagliato";
	}
	
	if (preg_match("/^[a-zA-Z0-9_]$/", $Nickname)&&$Nickname!=$Nome) {
	echo "Nickname:$Nickname";
	} else {
	  echo "$Nickname non si può mettere carateri speciali e numeri";
	}
	
	if (preg_match("/^[a-z]+[A-Z]+[0-9]+[ -/:-@[-'{-}]+$/", $Password)) {
	echo "Password:$Password";
	} else {
	  echo "$Password è troppo corto o non ha ragiunto i requesiti";
	}
	?>
</body>
</html>
