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
var_dump(flush());
var_dump(ob_flush());

?>
--EXPECT--
bool(true)
bool(true)
