--TEST--
override_builtin_functions() Basic test
--SKIPIF--
<?php
if (!extension_loaded('thunkit')) {
	echo 'skip';
}
?>
--FILE--
<?php
override_builtin_functions();
ob_start();
var_dump("thunkit");
ob_flush();
$var = ob_get_contents();
var_dump($var);
// ob_end_clean();

?>
--EXPECT--
string(7) "thunkit"
string(20) "string(7) "thunkit"
"
