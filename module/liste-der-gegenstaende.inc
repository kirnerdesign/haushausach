<?php

		    
include ('db/raum_position.inc')  ;

	$sql = " SELECT * FROM allegegenstaende "; 
	
 ?>
 
<!--XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX--> 	

<div style="margin-left:25px;">
	<a href="index.php?RAUM=<?php echo $_REQUEST['RAUM']; ?>"><h1 style="color:#00d">zurück in den Raum</h1></a>
</div>
<div id="right_start">
<div id="rightinner2">

<?php 
if (isset($_REQUEST['SORT'])) {$sortierung=$_REQUEST['SORTIERUNG']; $richtung=$_REQUEST['RICHTUNG'];
    }  else {$sortierung='NAME'; $richtung='V';}
if (isset($_REQUEST['SUCH']) && $_REQUEST['SUCH']>'' ){ $BEGRIFF=$_REQUEST['SUCH']; $SUCH = " AND ( NAME LIKE '%".$_REQUEST['SUCH']."%' OR KOMMENTAR LIKE '%".$_REQUEST['SUCH']."%' OR SORT1 LIKE '%".$_REQUEST['SUCH']."%' OR SORT2 LIKE '%".$_REQUEST['SUCH']."%' OR NOTIZEN LIKE '%".$_REQUEST['SUCH']."%'  ) "; 
    } else { $SUCH = ""; $BEGRIFF='';}	
?>
	
	<table class="nummerliste" >	
	<tr>
<form name="sortierung" action="index.php" method="get" ><!--FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF-->
	<td><span style="color:white;"><strong>Sortierung: </strong></span></td>
		<td>
		 

		</td>
		<td>
    		<?php
		  $zustand[0]='ID';
		  $zustand[1]='NAME';
          $zustand[2]='UNTERPOS';
          $zustand[3]='SORT1';
          $zustand[4]='SORT2';
          $zustand[5]='DATUM';
          $zustand[6]='BEWERTUNG';
             for ($r=0; $r<7; $r++){
              if ($zustand[$r] == $sortierung){$zustandS[$r] = 'selected="selected"';} else {$zustandS[$r]= '';}              
              }
           ?>
		<select class="select" name="SORTIERUNG" size="1">
			<option value="ID" 			<?php echo $zustandS[0]; ?> >normal</option>			
			<option value="NAME" 		<?php echo $zustandS[1]; ?> >nach Namen</option>
			<option value="UNTERPOS" 	<?php echo $zustandS[2]; ?> >nach Position</option>
			<option value="SORT1" 		<?php echo $zustandS[3]; ?> >nach Sortierung 1</option>
			<option value="SORT2" 		<?php echo $zustandS[4]; ?> >nach Sortierung 2</option>
			<option value="DATUM" 		<?php echo $zustandS[5]; ?> >nach Datum der Aufnahme</option>
			<option value="BEWERTUNG" 	<?php echo $zustandS[6]; ?> >Nach Bewertung</option>
		</select>
		</td>
		<td>
		    		<?php
		  		$folge[0]='V';
		  		$folge[1]='R';
             for ($f=0; $f<2; $f++){
              if ($folge[$f] == $richtung){$folgeS[$f] = 'selected="selected"';} else {$folgeS[$f]= '';}              
              }
           ?>
    <select class="select" name="RICHTUNG" size="1">
			<option value="V" <?php echo $folgeS[0]; ?> >&darr;</option>			
			<option value="R" <?php echo $folgeS[1]; ?> >&uarr;</option>
		</select>
		</td>

		<td style="width:580px;">
        
<!--PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP-->        
        <?php $TBLP=''; $LP=''; if ($RAUM==3 && $POS==1 ) { //$sortierung='NAME';
		/*
		if(isset($_REQUEST['PLATTENSORT'])){$LPzust=$_REQUEST['PLATTEZEIGEN']; }
		
		  $LP[0]='ALLE';
		  $LP[1]='AUFLEGEN';
          $LP[2]='NEU';
          $LP[3]='WAV';
          $LP[4]='MP3';
		      $LP[5]='FNEU';
             for ($r=0; $r<7; $r++){
              if ($LP[$r] == $LPzust){$LPS[$r] = 'selected="selected"';} else {$LPS[$r]= '';}              
              }
            ?>
        
       <!-- <form name="plattenzeigen" action="index.php" method="get" >-->
       <div style="float:left;<?php echo $TBLP; ?>">
        <select class="select" name="PLATTEZEIGEN" size="1">
			<option value="ALLE" 		<?php echo $LPS[0]; ?> >Alle Platten</option>		
            <option value="AUFLEGEN" 	<?php echo $LPS[1]; ?> >Platten auflegen</option>			
			<option value="NEU" 		<?php echo $LPS[2]; ?> >zu digitalisieren</option>
			<option value="WAV" 		<?php echo $LPS[3]; ?> >zu bearbeiten (WAV)</option>
			<option value="MP3" 		<?php echo $LPS[4]; ?> >zu bearbeiten (MP3)</option>
      <option value="FNEU" 		<?php echo $LPS[5]; ?> >noch aufnehmen</option>
		</select>&nbsp;
        </div>
        <input type="hidden" name= "PLATTENSORT" value="aktualisieren"  />
        <?php  $LP='JA'; */ } ?>
		
     <span style="color:white;"><strong> Suchbegriff: </strong> 
        <input type="text" name= "SUCH" size="16" placeholder="Suchbegriff" value="<?php echo $BEGRIFF; ?>"  />	
        <!--PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP--> 
        <input type="hidden" name= "POS"  value="<?php echo $POS; ?>"  />		
		<input type="hidden" name= "RAUM" value="<?php echo $RAUM; ?>"  />
        <input type="submit" name= "SORT" value="aktualisieren"  />
          
     
</form><!--FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF-->     
            </td>	
		</tr>
	</table>	


<?php   
if ($richtung=='R'){$R='DESC';} else {$R='';}

//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

/*
 if ($LP=='JA' && isset($_GET['PLATTEZEIGEN'])){
	 	
 	
	 $sql .= " WHERE RAUM = '$RAUM' AND POSITION = '$POS' ";
	 
	 if($LPzust=='ALLE') 	 {  $sql .= " ";  }	
	 if($LPzust=='AUFLEGEN') {  $sql .= " AND NOTIZEN LIKE 'Digitalisiert%' ";  }	
	 if($LPzust=='NEU')		 {  $sql .= " AND SORT1 LIKE '%noch aufnehmen%' ";  }
	 if($LPzust=='FNEU')	 {  $sql .= " AND SORT1 LIKE '%aufnehmen%' ";  }	
	 if($LPzust=='WAV')		 {  $sql .= " AND SORT1 LIKE 'bearbeiten wav%' ";  }	
	 if($LPzust=='MP3')		 {  $sql .= " AND SORT1 LIKE 'bearbeiten mp3%' ";  }	
	  
	 $sql .= $SUCH." ORDER BY $sortierung $R ";
	 
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
	 
 } else { */
	 
	 $sql .= " WHERE RAUM = '$RAUM' AND POSITION = '$POS' ".$SUCH." ORDER BY $sortierung $R "; //}
	 
//echo '<span style="color:white;">'.$sql.'</span><br />';

 include('db/objekte_einlesen.inc'); // include('db/realordner.inc');

?>

<div id="ganzeliste">
<?php $TBLPsymbol='platteauflegen.png';$TBLPtext='Platte auflegen';

for ($l=1;$l<$dz;$l++){
//========================================================== Schallplatten =====================================================

    if ($LP=='JA') {  
		$Plattenspieler='';
		/*
		foreach (glob("medien/".$aORDNER[$l]."/*.mp3") as $filename) {
			if($filename){
    		$Plattenspieler='<a href="javascript:void window.open(\'plattenspieler.php?PLATTE='.$aID[$l].'\',\'\',\'width=503,scrollbars=yes\')"><img style="height:60px;" src="images/'.$TBLPsymbol.'" /></a><br /><p class="weiss">'.$TBLPtext.'</p><br /><br />';
		}}
		$NotOrt='Notizen:';
        $bildquelle='medien/'.$aORDNER[$l].'/FotoVorschau.jpg';
		*/
        } 

//==============================================================================================================================			
		else { 
        $bildquelle='medien/bilder/'.$aBILD[$l];
		$NotOrt='Notizen:'; 
		}
        //echo  $bildquelle;
    if (!$aDATUM[$l]) { $aDATUM[$l]=date("Y-m-d");  }
    
    $sql = " SELECT * FROM pdf WHERE ID_ag = '$aID[$l]' "; // echo 'ACHTUNG:'.$aID[$l];
    include('db/pdfs_einlesen.inc');
      
   ?>
    <a name="<?php echo $aID[$l]; ?>"></a>
<!--FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF-->    
<form  name="NummerLIST" action="index.php#<?php echo $aID[$l]; ?>" method="post" > 

	<table class="nummerliste" ><tr>	 
   		
 			<td>
            <?php if(file_exists('medien/'.$aORDNER[$l].'/CD-cover.pdf')){ $bildquelleG='medien/'.$aORDNER[$l].'/CD-cover.pdf'; $breite=800;$hoehe=500;} else {$bildquelleG=$bildquelle; $breite=450;$hoehe=450;}?>
            
 			<a  href="javascript:void window.open('<?php echo $bildquelleG; ?>','','width=auto,height=<?php echo $hoehe; ?>,scrollbars=no')">
            <?php $size = GetImageSize ($bildquelle); if ($size[0]>450){$mittig=(-60);} else {$mittig=0;} ?> 
            <div style="height:200px;width:200px; overflow:hidden;">
            <img style="margin: 0 0 -5px <?php echo $mittig; ?>px;" src="<?php echo $bildquelle; ?>" height="200"  />
            </div>
            </a>
       
      </td>
      
 			<td valign="top" style="width:135px;padding-left:5px;font-size:0.9em;">&nbsp;Raum: <span class="weiss"><?php echo $raum_name[$RAUM]; ?></span> 
        <a style="float:right;margin-right:5px;color:white;
        " href="BilderNeuPositionieren.php?ID=<?php echo $aID[$l]; ?>" target="_blank">Position?</a>
       <br />
 			                 &nbsp;Gruppe: <span class="weiss"><?php echo $posi[$RAUM][$POS]; ?></span><br />
                       &nbsp;Position: &nbsp; &nbsp; &nbsp;<input type="text" name="UNTERPOS" size="18" value="<?php echo $aUNTERPOS[$l]; ?>" />
       <textarea type="text" name="NAME" rows="5" cols="23" ><?php echo $aNAME[$l]; ?></textarea>
       Sortierung1:&nbsp;<input type="text" name="SORT1" size="18" value="<?php echo $aSORT1[$l]; ?>" />
       Sortierung2:&nbsp;<input type="text" name="SORT2" size="18" value="<?php echo $aSORT2[$l]; ?>" />
      </td>
       
       
 			<td style=";padding-left:5px;font-size:0.9em;">Kommentar:
       &nbsp;<textarea type="text" name="KOMMENTAR" rows="5" cols="26" ><?php echo $aKOMMENTAR[$l]; ?></textarea><br />
       &nbsp;<?php echo $NotOrt; ?>
       &nbsp;<textarea type="text" name="NOTIZEN" rows="2" cols="26" ><?php echo $aNOTIZEN[$l]; ?></textarea>
      </td> 
 			
 			<?php
 			    $val[1]='unbbeh'; $col[1]='0,153,0';          $text[1]=' unbedingt behalten '; 
          $val[2]='bedbeh'; $col[2]='102,153,102';      $text[2]=' bedingt behalten ';
          $val[3]='abwart'; $col[3]='104,104,104';      $text[3]=' unentschieden/abwarten '; 
          $val[4]='eigenw'; $col[4]='104,102,104';      $text[4]=' verkaufen ';
          $val[5]='versch'; $col[5]='150,50,0';         $text[5]=' verschenken ';
          $val[6]='unbweg'; $col[6]='255,50,0';         $text[6]=' unbedingt wegschmeißen ';
            if($aBEWERTUNG[$l]=='') {$aBEWERTUNG[$l]=$val[1];}
          for($v=1;$v<=6;$v++){
            if($aBEWERTUNG[$l]==$val[$v]) {
              $setting[$v]='selected="selected"';
              $color=$col[$v];
              } else {$setting[$v]='';}
              }          
       ?>
           
     <td valign="top" style="padding:5px;font-size:0.9em;line-height:1em">
      <div style="height:130px;">        
          
          <?php 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ?>
          <a class="weiss" href="medien/pdf/<?php echo $pPDF[$p]; ?>" target="_blank"><?php echo $pPDF[$p];  ?></a>
          <?php } for ($p=1;$p<=$pdfdz;$p++){$pPDF[$p]='';} 	  	  
          ?>    
      </div>
      
     
     <select style="font-size:1.1em;" class="select" name="BEWERTUNG" size="1">  <!--AKTIONEN-->
          <?php for($v=1;$v<=6;$v++){ ?>
         	<option value="<?php echo $val[$v]; ?>" <?php echo $setting[$v]; ?>><?php echo $text[$v]; ?></option>
         	<?php }  ?>
        </select>
        <div style="height:26px;width:100%;background-color:rgba(<?php echo $color; ?>,0.5)">
        </div>
       <?php if ($LP=='JA' ){ ?>		
        <input type="hidden" name="PLATTEZEIGEN" 	value="<?php echo $LPzust; ?>" />
        <input type="hidden" name="PLATTENSORT" 	value="JA" />
		<?php } ?>
        <input type="hidden" name="SORT" value="JA" />
        <input type="hidden" name="SORTIERUNG" 	value="<?php echo $sortierung; ?>" />
		<input type="hidden" name="RICHTUNG" 	value="<?php echo $richtung; ?>" />	
        <input type="hidden" name="ID" 			value="<?php echo $aID[$l]; ?>" />
        <input type="hidden" name="RAUM" 		value="<?php echo $aRAUM[$l]; ?>" />
        <input type="hidden" name="GRUPPE" 		value="<?php echo $aPOSITION[$l]; ?>" />
        <input type="hidden" name="BILD" 		value="<?php echo $aBILD[$l]; ?>" />
        <input type="hidden" name="ORDNER" 		value="<?php echo $aORDNER[$l]; ?>" />        
        <input type="hidden" name="DATUM" 		value="<?php echo $aDATUM[$l]; ?>" />
        <input type="submit" name="SPEICHERN" 	value="&nbsp;&nbsp; Änderungen speichern&nbsp;&nbsp;" />        
        
     </td>

  </tr></table>
</form>
<!--FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF-->      
<?php }

 ?>
</div>
<?php 

?>
	</div></div>
