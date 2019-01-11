/* thunkit extension for PHP */

#ifndef PHP_THUNKIT_H
# define PHP_THUNKIT_H

extern zend_module_entry thunkit_module_entry;
# define phpext_thunkit_ptr &thunkit_module_entry

static PHP_FUNCTION(_sleep);
static PHP_FUNCTION(_flush);
static PHP_FUNCTION(_ob_flush);

# define PHP_THUNKIT_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_THUNKIT)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_THUNKIT_H */

