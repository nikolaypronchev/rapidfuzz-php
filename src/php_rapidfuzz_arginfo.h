/**
 * Argument info for rapidfuzz PHP extension
 */

#ifndef PHP_RAPIDFUZZ_ARGINFO_H
#define PHP_RAPIDFUZZ_ARGINFO_H

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

#endif /* PHP_RAPIDFUZZ_ARGINFO_H */
