/**
 * rapidfuzz.cpp
 *
 * Implementation of rapidfuzz PHP extension
 * Provides fuzzy string matching functions: ratio, partial_ratio, token_sort_ratio, token_set_ratio
 */

#include "php_rapidfuzz.h"

// RapidFuzz headers
#include <rapidfuzz/fuzz.hpp>
#include <string>

/**
 * Convert zend_string* to std::string
 */
static inline std::string zstr_to_std(zend_string* zstr) {
    return std::string(ZSTR_VAL(zstr), ZSTR_LEN(zstr));
}

/**
 * PHP_FUNCTION(rapidfuzz_fuzz_ratio)
 * Calculate simple ratio between two strings
 *
 * @param string $s1 First string
 * @param string $s2 Second string
 * @param float $score_cutoff Optional score cutoff (0-100)
 * @return float Similarity ratio (0-100)
 */
PHP_FUNCTION(rapidfuzz_fuzz_ratio)
{
    zend_string *s1 = NULL;
    zend_string *s2 = NULL;
    double score_cutoff = 0;

    ZEND_PARSE_PARAMETERS_START(2, 3)
        Z_PARAM_STR(s1)
        Z_PARAM_STR(s2)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(score_cutoff)
    ZEND_PARSE_PARAMETERS_END();

    std::string str1 = zstr_to_std(s1);
    std::string str2 = zstr_to_std(s2);

    double result = rapidfuzz::fuzz::ratio(str1, str2, score_cutoff);

    RETURN_DOUBLE(result);
}

/**
 * PHP_FUNCTION(rapidfuzz_fuzz_partial_ratio)
 * Calculate partial ratio between two strings
 *
 * @param string $s1 First string
 * @param string $s2 Second string
 * @param float $score_cutoff Optional score cutoff (0-100)
 * @return float Partial similarity ratio (0-100)
 */
PHP_FUNCTION(rapidfuzz_fuzz_partial_ratio)
{
    zend_string *s1 = NULL;
    zend_string *s2 = NULL;
    double score_cutoff = 0;

    ZEND_PARSE_PARAMETERS_START(2, 3)
        Z_PARAM_STR(s1)
        Z_PARAM_STR(s2)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(score_cutoff)
    ZEND_PARSE_PARAMETERS_END();

    std::string str1 = zstr_to_std(s1);
    std::string str2 = zstr_to_std(s2);

    double result = rapidfuzz::fuzz::partial_ratio(str1, str2, score_cutoff);

    RETURN_DOUBLE(result);
}

/**
 * PHP_FUNCTION(rapidfuzz_fuzz_token_sort_ratio)
 * Calculate token sort ratio between two strings
 *
 * @param string $s1 First string
 * @param string $s2 Second string
 * @param float $score_cutoff Optional score cutoff (0-100)
 * @return float Token sort similarity ratio (0-100)
 */
PHP_FUNCTION(rapidfuzz_fuzz_token_sort_ratio)
{
    zend_string *s1 = NULL;
    zend_string *s2 = NULL;
    double score_cutoff = 0;

    ZEND_PARSE_PARAMETERS_START(2, 3)
        Z_PARAM_STR(s1)
        Z_PARAM_STR(s2)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(score_cutoff)
    ZEND_PARSE_PARAMETERS_END();

    std::string str1 = zstr_to_std(s1);
    std::string str2 = zstr_to_std(s2);

    double result = rapidfuzz::fuzz::token_sort_ratio(str1, str2, score_cutoff);

    RETURN_DOUBLE(result);
}

/**
 * PHP_FUNCTION(rapidfuzz_fuzz_token_set_ratio)
 * Calculate token set ratio between two strings
 *
 * @param string $s1 First string
 * @param string $s2 Second string
 * @param float $score_cutoff Optional score cutoff (0-100)
 * @return float Token set similarity ratio (0-100)
 */
PHP_FUNCTION(rapidfuzz_fuzz_token_set_ratio)
{
    zend_string *s1 = NULL;
    zend_string *s2 = NULL;
    double score_cutoff = 0;

    ZEND_PARSE_PARAMETERS_START(2, 3)
        Z_PARAM_STR(s1)
        Z_PARAM_STR(s2)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(score_cutoff)
    ZEND_PARSE_PARAMETERS_END();

    std::string str1 = zstr_to_std(s1);
    std::string str2 = zstr_to_std(s2);

    double result = rapidfuzz::fuzz::token_set_ratio(str1, str2, score_cutoff);

    RETURN_DOUBLE(result);
}

/**
 * Argument info for fuzz functions
 */
ZEND_BEGIN_ARG_INFO_EX(arginfo_rapidfuzz_fuzz_ratio, 0, 0, 2)
    ZEND_ARG_INFO(0, s1)
    ZEND_ARG_INFO(0, s2)
    ZEND_ARG_INFO(0, score_cutoff)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rapidfuzz_fuzz_partial_ratio, 0, 0, 2)
    ZEND_ARG_INFO(0, s1)
    ZEND_ARG_INFO(0, s2)
    ZEND_ARG_INFO(0, score_cutoff)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rapidfuzz_fuzz_token_sort_ratio, 0, 0, 2)
    ZEND_ARG_INFO(0, s1)
    ZEND_ARG_INFO(0, s2)
    ZEND_ARG_INFO(0, score_cutoff)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rapidfuzz_fuzz_token_set_ratio, 0, 0, 2)
    ZEND_ARG_INFO(0, s1)
    ZEND_ARG_INFO(0, s2)
    ZEND_ARG_INFO(0, score_cutoff)
ZEND_END_ARG_INFO()

/**
 * Function entries
 */
static const zend_function_entry rapidfuzz_functions[] = {
    PHP_FE(rapidfuzz_fuzz_ratio, arginfo_rapidfuzz_fuzz_ratio)
    PHP_FE(rapidfuzz_fuzz_partial_ratio, arginfo_rapidfuzz_fuzz_partial_ratio)
    PHP_FE(rapidfuzz_fuzz_token_sort_ratio, arginfo_rapidfuzz_fuzz_token_sort_ratio)
    PHP_FE(rapidfuzz_fuzz_token_set_ratio, arginfo_rapidfuzz_fuzz_token_set_ratio)
    PHP_FE_END
};

/**
 * Module dependencies
 */
static const zend_module_dep rapidfuzz_module_deps[] = {
    { NULL, NULL, NULL, 0 }
};

/**
 * Module entry
 */
zend_module_entry rapidfuzz_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_RAPIDFUZZ_EXTNAME,
    rapidfuzz_functions,
    NULL,  // MINIT
    NULL,  // MSHUTDOWN
    NULL,  // RINIT
    NULL,  // RSHUTDOWN
    NULL,  // MINFO - will be added later
    PHP_RAPIDFUZZ_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_RAPIDFUZZ
ZEND_GET_MODULE(rapidfuzz)
#endif
