<?php

//=== original server ===============
include('db_start.inc');
//====================================
$verbindung = mysql_connect ($server, $Benutzer, $Kennwort);
//============================================================ Fehler-check 1
if (!$verbindung) {die('Keine Verbindung möglich: ' . mysql_error());}
//============================================================
$db_selected = mysql_select_db($DBNAME, $verbindung);
//============================================================ Fehler-check 2
if (!$db_selected) {die('Auswahl der Datenbank nicht möglich: ' . mysql_error());}
//============================================================ Daten ändern

$sql_eintrag = "UPDATE allegegenstaende SET

RAUM = '$RAUM',
POSITION = '$GRUPPE',
UNTERPOS = '$UNTERPOS',
NAME = '$NAME',
SORT1 = '$SORT1',
SORT2 = '$SORT2',
BILD = '$BILD',
ORDNER = '$ORDNER',
BEWERTUNG = '$BEWERTUNG',   
KOMMENTAR = '$KOMMENTAR',
NOTIZEN = '$NOTIZEN',
DATUM = '$DATUM'

WHERE ID = '$ID' "; 

$eintrag = mysql_query($sql_eintrag, $verbindung);

if($eintrag){
$SQLresultat = '<h4 style="padding-left:30px;color:green; background-color:white;"> Der Gegenstand: "'.$NAME.'" wurde erfolgreich &uuml;berschrieben! </h4><br /><br />';
} else {
$SQLresultat = '<h4 style="padding-left:20px;color:red; background-color:white;"> Der Gegenstand: "'.$NAME.'" konnte nicht geschrieben werden! </h4><br /><br />';
}  //mysql_free_result($eintrag);
mysql_close($verbindung);  


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, VDISP = '$VDISP'


?>
