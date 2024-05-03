<!DOCTYPE html>
<html lang="it">
<head>
    <title>colora</title>
</head>
<body>
    <form action="/action_page.php">
        <label for="fname">First name:</label><br>
        <input type="text" id="fname" name="fname" value="John"><br>
        <label for="lname">Last name:</label><br>
        <input type="text" id="lname" name="lname" value="Doe"><br><br>
        <input type="submit" value="Submit" id="submit">
    </form>
    <script>
        document.getElementById("submit").style.backgroundColor = "DodgerBlue";
    </script>
</body>
</html>
