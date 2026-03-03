<?php

/**
 * rapidfuzz-php stub file for IDE autocompletion
 *
 * This file provides type hints and autocompletion for the rapidfuzz PHP extension.
 * The extension provides fuzzy string matching functions based on rapidfuzz-cpp.
 */

/**
 * Calculate simple ratio between two strings (Levenshtein distance normalized to 0-100)
 *
 * @param string $s1 First string
 * @param string $s2 Second string
 * @param float|int $score_cutoff Optional score cutoff (0-100). If the result is below this threshold, returns 0.0
 * @return float Similarity ratio between 0 and 100, where 100 means identical strings
 */
function rapidfuzz_fuzz_ratio(string $s1, string $s2, float $score_cutoff = 0): float {}

/**
 * Calculate partial ratio between two strings
 *
 * Best partial match with substrings - useful when one string is a substring of another
 *
 * @param string $s1 First string
 * @param string $s2 Second string
 * @param float|int $score_cutoff Optional score cutoff (0-100). If the result is below this threshold, returns 0.0
 * @return float Partial similarity ratio between 0 and 100
 */
function rapidfuzz_fuzz_partial_ratio(string $s1, string $s2, float $score_cutoff = 0): float {}

/**
 * Calculate token sort ratio between two strings
 *
 * Tokens are sorted alphabetically before comparing
 *
 * @param string $s1 First string
 * @param string $s2 Second string
 * @param float|int $score_cutoff Optional score cutoff (0-100). If the result is below this threshold, returns 0.0
 * @return float Token sort similarity ratio between 0 and 100
 */
function rapidfuzz_fuzz_token_sort_ratio(string $s1, string $s2, float $score_cutoff = 0): float {}

/**
 * Calculate token set ratio between two strings
 *
 * Tokens are treated as sets (order-independent)
 *
 * @param string $s1 First string
 * @param string $s2 Second string
 * @param float|int $score_cutoff Optional score cutoff (0-100). If the result is below this threshold, returns 0.0
 * @return float Token set similarity ratio between 0 and 100
 */
function rapidfuzz_fuzz_token_set_ratio(string $s1, string $s2, float $score_cutoff = 0): float {}