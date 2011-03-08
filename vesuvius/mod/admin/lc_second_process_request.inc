<?php
/**
 * @name         Administration
 * @version      1.0
 * @package      admin
 * @author       Greg Miernicki <g@miernicki.com> <gregory.miernicki@nih.gov>
 * @about        Developed in whole or part by the U.S. National Library of Medicine and the Sahana Foundation
 * @link         https://pl.nlm.nih.gov/about
 * @link         http://sahanafoundation.org
 * @license	 http://www.gnu.org/copyleft/lesser.html GNU Lesser General Public License (LGPL)
 * @lastModified 2011.0303
 */

// Get a file into an array.  In this example we'll go through HTTP to get
// the HTML source of a URL.

define('LENGTH', 8);
$locale = $_REQUEST['locale'];



function _find_translated_str() {
	$msgid = $_REQUEST['msgid'];
	$msgstr = $_REQUEST['msgstr'];
	$locale = $_REQUEST['locale'];
	$tag = $_REQUEST['tag'];
	if(strlen($msgid)>70) {
		$msgid = substr($msgid,0,70);
	}

	$_SESSION['admin']['locale']['sahana_po'] = implode('', file("../res/locale/$locale/LC_MESSAGES/sahana_temp.po"));
	$position = strpos($_SESSION['admin']['locale']['sahana_po'],$msgid);

	if($position!=null)
		_find_str();
	else
		_find_translated_str_and_replace();
}




function _find_str() {
	$msgid = $_REQUEST['msgid'];
	$msgstr = $_REQUEST['msgstr'];
	$locale = $_REQUEST['locale'];

	$msgstr = addslashes($msgstr);
	//$lines = file('sahana.po');
	// Loop through our array, show HTML source as HTML source; and line numbers too.
	$_SESSION['admin']['locale']['sahana_po'] = implode('', file("../res/locale/$locale/LC_MESSAGES/sahana.po"));

	if(strlen($msgid)>70) {
		$msgid = substr($msgid,0,70);
		$msgid = trim($msgid);
		$position = strpos($_SESSION['admin']['locale']['sahana_po'],$msgid);
		_replace_str_confirm($position,$msgid,$msgstr,$locale);
	}else {
		$i=0;
		$position=1;
		$msgid = trim($msgid);
		while($position!=null) {
			if($i!=0) {
				$position = strlen($msgid) + $position;
			}
			$position = strpos($_SESSION['admin']['locale']['sahana_po'],$msgid,$position);
			$qutationpos = strpos($_SESSION['admin']['locale']['sahana_po'],"\"",$position);
			//$qutationpos = $position+strlen("Organization Registry");
			$qutationcheck = $position+strlen($msgid);
			if($qutationcheck==$qutationpos) {
				$position =$position;
				_replace_str_confirm($position,$msgid,$msgstr,$locale);
				break;
			}
			$i++;
	 	}
	}
}



function _replace_str_confirm($position,$msgid,$msgstr,$locale) {
	if($msgid!='') {

		$strlength = strlen($msgid);
		$positionfirst = $position + $strlength;
		$positionfirst = strpos($_SESSION['admin']['locale']['sahana_po'],"msgstr",$positionfirst);
		$position = $positionfirst + LENGTH;
		$qutationpos = strpos($_SESSION['admin']['locale']['sahana_po'],"\"",$position);
		$qutationpos = $qutationpos - $position;
		$stringlegth = strlen($_SESSION['admin']['locale']['sahana_po']);
		$secondposition = $position - $stringlegth + $qutationpos;

		$var = $msgstr;
		$_SESSION['admin']['locale']['sahana_po'] = substr_replace($_SESSION['admin']['locale']['sahana_po'],$var,$position,$secondposition);

		$filename = "../res/locale/$locale/LC_MESSAGES/sahana.po";
		$somecontent = $_SESSION['admin']['locale']['sahana_po'];

		if(is_writable($filename)) {
    		if(!$handle = fopen($filename, 'w+')) {
         		echo "Cannot open file ($filename)";
         		exit;
    		}
			if(fwrite($handle, $somecontent) === FALSE) {
        		echo "Cannot write to file ($filename)";
        		exit;
    		}
    		echo "Success, wrote to file ($filename) .$msgstr"."MSGID = ".$msgid;
    		fclose($handle);

		}else {
    		echo "The file $filename is not writable";
		}
	}
}


