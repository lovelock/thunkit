/* thunkit extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_thunkit.h"

static zend_function *ori_flush;
static zif_handler ori_flush_handler;
static zend_function *ori_ob_flush;
static zif_handler ori_ob_flush_handler;

static PHP_FUNCTION(_flush)
{
	RETURN_TRUE;
}

static PHP_FUNCTION(_ob_flush)
{
	RETURN_TRUE;
}


PHP_FUNCTION(override_builtin_functions)
{
    ori_flush = (zend_function *) zend_hash_str_find_ptr(EG(function_table), ZEND_STRL("flush"));
    if (ori_flush) 
    {
    	ori_flush->internal_function.handler = PHP_FN(_flush);
    }

    ori_ob_flush = (zend_function *) zend_hash_str_find_ptr(EG(function_table), ZEND_STRL("ob_flush"));
    if (ori_ob_flush) 
    {
    	ori_ob_flush->internal_function.handler = PHP_FN(_ob_flush);
    }

    return SUCCESS;
}

/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(thunkit)
{
#if defined(ZTS) && defined(COMPILE_DL_THUNKIT)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(thunkit)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "thunkit support", "enabled");
	php_info_print_table_row(2, "Version", PHP_THUNKIT_VERSION);
	php_info_print_table_row(2, "Author", "Frost Wong");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */

ZEND_BEGIN_ARG_INFO(arginfo_thunkit_override_builtin_functions, 0)
ZEND_END_ARG_INFO()

/* }}} */

/* {{{ thunkit_functions[]
 */
static const zend_function_entry thunkit_functions[] = {
	PHP_FE(override_builtin_functions,		arginfo_thunkit_override_builtin_functions)
	PHP_FE_END
};
/* }}} */

/* {{{ thunkit_module_entry
 */
zend_module_entry thunkit_module_entry = {
	STANDARD_MODULE_HEADER,
	"thunkit",					/* Extension name */
	thunkit_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(thunkit),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(thunkit),			/* PHP_MINFO - Module info */
	PHP_THUNKIT_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_THUNKIT
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(thunkit)
#endif

