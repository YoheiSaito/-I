

<?php
  if (isset($_GET['message']) && $_GET['message'] != "") {
    $f = fopen("./tmp/angle.dat", "w");
    fwrite($f, htmlspecialchars($_GET['message']) . "\n");
    fclose($f);
  }
?>

