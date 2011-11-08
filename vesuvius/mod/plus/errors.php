<?
/**
 * @name         PL User Services
 * @version      2.0
 * @package      plus
 * @author       Greg Miernicki <g@miernicki.com> <gregory.miernicki@nih.gov>
 * @about        Developed in whole or part by the U.S. National Library of Medicine
 * @link         https://pl.nlm.nih.gov/about
 * @license	 http://www.gnu.org/copyleft/lesser.html GNU Lesser General Public License (LGPL)
 * @lastModified 2011.1007
 */


// define error codes
define("ERRORCODES", serialize(array(
	0    => "No error.",
	1    => "Invalid username or password.",
	2    => "User account is not active.",
	3    => "Invalid confirmation request.",
	4    => "Account already active.",
	5    => "Account activated.",
	6    => "User exists with provided email address.",
	7    => "Username already in use.",
	8    => "Invalid email address.",
	9    => "Password does not meet the following criteria: 1. The minimum length of the password is 8 characters. 2. The maximum length of the password is 16 characters. 3. Must have at least one uppercase character. 4. Must have at least one lowercase character. 5. Must have at least one numeral (0-9). 6. The password cannot contain your username.",
	10   => "User does not exist or user's account is not active.",
	11   => "Email address is not associated with any user account.",
	12   => "Username does not exist.",
	100  => "No hospital registered with this id.",
	200  => "sessionTimeout value missing from database.",
	201  => "Invalid number of uuid’s requested, value must be between 2 and 100.",
	300  => "Insufficient privileges to access data in this event.",
	301  => "Authentication required to access this non-public event.",
	302  => "Event does not exist with this shortname.",
	400  => "Invalid enumeration.",
	401  => "Duplicate person report ~ p_uuid collision.",
	402  => "Invalid p_uuid ~ out of range.",
	403  => "Error parsing XML.",
	405  => "Event is closed to reporting.",
	406  => "Invalid event.",
	407  => "No record associated with this mass casualty ID exists.",
	408  => "Insufficient permission to revise this record.",
	410  => "No record available with the given uuid.",
	411  => "Invalid start or limit value.",
	412  => "Invalid or future unix timestamp.",
	9000 => "Database Error.",
	9998 => "Function not yet implemented (stub).",
	9999 => "Unknown error.",
)));