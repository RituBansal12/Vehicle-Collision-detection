<?php
$uploadfile = "";
echo "Uploading ";
echo $_FILES["userfile"]["name"];
if(strlen(basename($_FILES["userfile"]["name"])) > 0)
{
 $uploadfile = basename($_FILES["userfile"]["name"]);
 if(move_uploaded_file($_FILES["userfile"]["tmp_name"], $uploadfile))
 {
 @chmod($uploadfile,0777); echo " Ok! ";
$datum = mktime(date('H')+0, date('i'), date('s'), date('m'), date('d'), date('y'));
if (file_exists("old/".date('Y_m_d', $datum) )) {
 print("Directory already exists.\n");
 } else {
 mkdir("old/".date('Y_m_d', $datum));
 copy("index1.php","old/".date('Y_m_d', $datum)."/index.php");
 print("Directory creating.\n");
 }
echo "saved ";
copy($uploadfile,"old/".date('Y_m_d', $datum)."/".date('Y.m.d_H-i-s', $datum).".jpg");
 }
 else echo " Error copying!";
}
echo date('Y.m.d_H:i', $datum);
?>
