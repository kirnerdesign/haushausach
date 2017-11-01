
<!--=========================================================================-->
<div id="freiraum">
</div>
<!--=========================================================================
<?php 
//header('Location:medien/galerie'.$RAUM.'/index.html');
include ('db/raum_position.inc')  ;

 ?>
<!--^vvvvvvvvvvvv"rightinner"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv-->	    
<div id="right_start">
<a href="index.php"><h1><?php echo $titelzeile; ?></h1></a>
<div id="rightinner">
<?php 
if ($RAUM==0) {  //alle Räume 1 - 10 zeigen
for ($i=1;$i<11;$i++) { ?>
	<div class="kachel"> 
      <!--<a href="index.php?RAUM=<? echo $i; ?>"><img src="images/Raum'.substr('0'.$i,-2).'.jpg" /></a>-->
	  <a href="medien/galerie<? echo $i; ?>"><img src="images/Raum<? echo substr('0'.$i,-2); ?>.jpg" /></a>
	</div> <? }
} else {
	
echo '<div style="height:340px;background-image: url(images/RaumHG'.substr('0'.$RAUM,-2).'.jpg);background-repeat:no-repeat;">';

for ($i=1;$i<=$posi[$RAUM][0];$i++) { //alle Gruppen in den Räumen zeigen
    if (file_exists('images/Position'.substr('0'.$RAUM,-2).substr('0'.$i,-2).'.jpg')){
    $positionsbild='Position'.substr('0'.$RAUM,-2).substr('0'.$i,-2).'.jpg';
    }  else { $positionsbild='Position0000.jpg';}	
	
echo '<div style="float:right;margin-right:15px;margin-bottom:15px;">
      <a href="index.php?RAUM='.$RAUM.'&amp;POS='.$i.'"><img src="images/'.$positionsbild.'" />
      </a><div style="font-size:16px;font-weight:bold;color:white;margin-left:5px;margin-top:-25px;">'.$posi[$RAUM][$i].'</div>';
echo '</div>'; 
	}
echo '<div style="float:right;margin-right:15px;margin-bottom:15px;">
      <a href="medien/galerie'.$RAUM.'/index.html" target="_blank"><img src="images/Position0000.jpg" />
      </a><div style="font-size:16px;font-weight:bold;color:white;margin-left:5px;margin-top:-25px;">'.$posi[$RAUM][99].'</div>';
echo '</div>';


}

?>
</div>
</div>
<!--=========================================================================-->

