<?php

use PHPUnit\Framework\TestCase;

/**
 * Test case for rapidfuzz PHP extension
 */
class RapidFuzzTest extends TestCase
{
    /**
     * Test fuzz_ratio function
     */
    public function testRatioIdenticalStrings(): void
    {
        $result = rapidfuzz_fuzz_ratio("hello", "hello");
        $this->assertEquals(100.0, $result);
    }

    public function testRatioCompletelyDifferent(): void
    {
        $result = rapidfuzz_fuzz_ratio("hello", "world");
        $this->assertLessThan(50.0, $result);
    }

    public function testRatioPartialMatch(): void
    {
        $result = rapidfuzz_fuzz_ratio("hello", "hello world");
        $this->assertGreaterThan(80.0, $result);
    }

    public function testRatioWithScoreCutoff(): void
    {
        $result = rapidfuzz_fuzz_ratio("hello", "world", 50.0);
        // Should return 0 if below cutoff
        $this->assertEquals(0.0, $result);
    }

    /**
     * Test fuzz_partial_ratio function
     */
    public function testPartialRatioIdentical(): void
    {
        $result = rapidfuzz_fuzz_partial_ratio("hello", "hello");
        $this->assertEquals(100.0, $result);
    }

    public function testPartialRatioSubstring(): void
    {
        $result = rapidfuzz_fuzz_partial_ratio("hello", "say hello world");
        $this->assertEquals(100.0, $result);
    }

    /**
     * Test fuzz_token_sort_ratio function
     */
    public function testTokenSortRatio(): void
    {
        $result = rapidfuzz_fuzz_token_sort_ratio("world hello", "hello world");
        $this->assertEquals(100.0, $result);
    }

    public function testTokenSortRatioDifferent(): void
    {
        $result = rapidfuzz_fuzz_token_sort_ratio("hello world", "foo bar");
        $this->assertLessThan(50.0, $result);
    }

    /**
     * Test fuzz_token_set_ratio function
     */
    public function testTokenSetRatio(): void
    {
        $result = rapidfuzz_fuzz_token_set_ratio("hello world", "world hello");
        $this->assertEquals(100.0, $result);
    }

    public function testTokenSetRatioPartial(): void
    {
        $result = rapidfuzz_fuzz_token_set_ratio("hello", "hello world");
        $this->assertGreaterThan(80.0, $result);
    }

    /**
     * Test edge cases
     */
    public function testEmptyString(): void
    {
        $result = rapidfuzz_fuzz_ratio("", "");
        $this->assertEquals(100.0, $result);
    }

    public function testOneEmptyString(): void
    {
        $result = rapidfuzz_fuzz_ratio("", "hello");
        $this->assertEquals(0.0, $result);
    }

    public function testUnicodeStrings(): void
    {
        $result = rapidfuzz_fuzz_ratio("привет", "привет");
        $this->assertEquals(100.0, $result);
    }

    public function testScoreCutoffReturnsZero(): void
    {
        // Using a high cutoff that the result won't meet
        $result = rapidfuzz_fuzz_ratio("abc", "xyz", 100.0);
        $this->assertEquals(0.0, $result);
    }

    public function testScoreCutoffMet(): void
    {
        // Using a low cutoff that will be met
        $result = rapidfuzz_fuzz_ratio("hello", "hello", 50.0);
        $this->assertEquals(100.0, $result);
    }
}
