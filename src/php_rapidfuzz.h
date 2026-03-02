/**
 * php_rapidfuzz.h
 *
 * Header file for rapidfuzz PHP extension
 * Provides fuzzy string matching functions based on rapidfuzz-cpp library
 */

#ifndef PHP_RAPIDFUZZ_H
#define PHP_RAPIDFUZZ_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#define PHP_RAPIDFUZZ_VERSION "1.0.0"
#define PHP_RAPIDFUZZ_EXTNAME "rapidfuzz"

/* Module entry structure */
extern zend_module_entry rapidfuzz_module_entry;
#define phpext_rapidfuzz_ptr &rapidfuzz_module_entry

#endif /* PHP_RAPIDFUZZ_H */
