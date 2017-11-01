<?php
$RAUM=0; $titelzeile='';
?>
<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="de">

	<head>

		<title>Willkommen in Hausach</title>

  <meta http-equiv="content-type" content="text/html; charset=utf-8" />
  <meta name="robots" content="index, no follow" />
  <meta name="keywords" content="" />
  <meta name="description" content="" />
  <meta name="generator" content=".kirner.logo.web.design." />
    <meta name="viewport" content="initial-scale = 1.0,maximum-scale = 1.0" />
    <script>var __adobewebfontsappname__ = "reflow"</script>
    <script src="http://use.edgefonts.net/asul:n4:all.js"></script>
    <script src="http://use.edgefonts.net/concert-one:n4:all.js"></script>



<link rel="shortcut icon" href="favicon.ico" type="image/x-icon" />

	<link  rel="stylesheet" type="text/css" media="all" href="css/template.css" />
	 <!--<link  rel="stylesheet" type="text/css" media="all" href="css/menuK.css" />
<link  rel="stylesheet" type="text/css" media="all" href="css/admin.css" /> -->



</head>

<body id="hg1">


<div id="wrapper">

<?php
  if (isset($_POST['SPEICHERN'])){
      $ID         	= $_POST['ID'];
      $RAUM       	= $_POST['RAUM'];
      $GRUPPE   	= $_POST['GRUPPE']; $POS=$GRUPPE;
      $UNTERPOS   	= $_POST['UNTERPOS'];
      $NAME       	= str_replace("'","&lsquo;",$_POST['NAME']);
      $SORT1      	= $_POST['SORT1'];
      $SORT2      	= $_POST['SORT2'];
      $BILD       	= $_POST['BILD'];
      $ORDNER     	= $_POST['ORDNER'];
      $BEWERTUNG  	= $_POST['BEWERTUNG'];
      $KOMMENTAR  	= str_replace("'","&lsquo;",$_POST['KOMMENTAR']);
      $NOTIZEN    	= str_replace("'","&lsquo;",$_POST['NOTIZEN']);
      $DATUM      	= $_POST['DATUM'];

      include('db/objekt_ueberschreiben.inc');
      echo $SQLresultat;
      include('module/liste-der-gegenstaende.inc');
    }

if (isset($_GET['RAUM'])) {$RAUM=$_GET['RAUM'];  $titelzeile='zurück zur Raumübersicht';

    }
if (isset($_GET['RAUM']) && isset($_GET['POS']))  {
     $RAUM=$_GET['RAUM'];$POS=$_GET['POS'];

    include('module/liste-der-gegenstaende.inc');
    } else {
    if (!isset($_POST['SPEICHERN'])){include('module/raum-position.inc');
    } }
?>

</div><!--id="wrapper"-->
<footer>
<div class="kachel2">
<a href="medien/galerieUtensilien/index.html"  ><img src="images/HausachGalerieLM.jpg" height="100"  /></a>
<br /></div>
<div class="kachel2"><a href="medien/galerieHaus/index.html"  ><img src="images/HausachGalerieHaus.jpg" height="100"  /></a>
<br /></div>
<div class="kachel2"><a href="medien/galerieGarten/index.html" ><img src="images/HausachGalerieGarten.jpg" height="100"  /></a>
<br /></div>
<div class="kachel2"><a href="medien/galerieHausach/index.html"  ><img src="images/HausachGalerie.jpg" height="100"  /></a>
<br /></div>
<div class="kachel2"><a href="medien/galerieUmgebung/index.html"  ><img src="images/HausachGalerieUA.jpg" height="100"  /></a>
<br /></div>
<div class="kachel2"><a href="medien/galerieGegenstaende/index.html"><img src="images/HausachGalerieG.jpg" height="100"  /></a>
<br /></div>
<div style="clear:both; ">
<a href="medien/pdf/Abfall2016.pdf" target="_blank"><span style=" font-size:1.1em;font-weight:700;color:#FFFFFF;">Abfallplan 2017</span></a> .....
<a href="medien/pdf/HeizungHausach.pdf" target="_blank"><span style=" font-size:1.1em;font-weight:700;color:#FFFFFF;">Heizungshandbuch</span></a> .....
<a href="http://www.hausach.de/BUeRGERINFO/Rathaus/Mitteilungsblaetter" target="_blank"><span style=" font-size:1.1em;font-weight:700;color:#FFFFFF;"> Mitteilungsblatt "Aktuell-Aktuell-Aktuell"</span></a>
</div>
<!--<div>
<a href="ZIBhochladen.php" target="_blank" >ZIP-Datei mit neuen Bildern </a> <br />
<a href="BilderInDatenbank.php" target="_blank" >Neu in den Ordner "bilder" gespeicherte JPGs  in die Datenbank importieren</a> <br />
<a href="pdfInDatenbank.php" target="_blank" >Neu in den Ordner "pdf" gespeicherte PDFs in die Datenbank importieren</a> <br />
<a href="BilderPositionieren.php" target="_blank" >Neu in die Datenbank importierten Objekte positionieren</a> <br /><br />
 <br />
</div>-->
</footer>

</body>
</html>
