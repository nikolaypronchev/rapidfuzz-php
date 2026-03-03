# rapidfuzz-php

PHP extension for rapidfuzz fuzzy string matching library based on [rapidfuzz-cpp](https://github.com/rapidfuzz/rapidfuzz-cpp).

## Installation

### Prerequisites

- PHP 7.4+ (with development headers)
- C++ compiler with C++11 support
- Git (for submodules)

### Clone and Build

```bash
# Clone repository with submodules
git clone --recursive https://github.com/nikolaypronchev/rapidfuzz-php.git
cd rapidfuzz-php

# Generate configure script
phpize

# Configure
./configure

# Build
make

# Install (optional)
sudo make install
```

### Alternative: CMake Build

```bash
mkdir build && cd build
cmake ..
make
```

## Usage

Load the extension in PHP:

```ini
; php.ini
extension=rapidfuzz.so
```

Or via command line:

```bash
php -d extension=modules/rapidfuzz.so script.php
```

### IDE Autocompletion

For IDE autocompletion support, include the stub file in your PHP project:

**VS Code (PHP Intelephense):**
Add to your `.vscode/settings.json`:
```json
{
    "intelephense.stubs": [
        "rapidfuzz"
    ]
}
```

Or use the stub file directly by copying `src/rapidfuzz.stub.php` to your project's stubs directory.

**PHPStorm:**
1. Copy `src/rapidfuzz.stub.php` to your project or a stubs directory
2. Go to Settings → PHP → Include path
3. Add the path to the stub file

**Manual stub configuration:**
Copy [`src/rapidfuzz.stub.php`](src/rapidfuzz.stub.php) to your project and include it in your PHP include path.

### Troubleshooting

If you see "Undefined function" errors in your IDE:

1. **Verify the extension is loaded in PHP:**
   ```bash
   php -m | grep rapidfuzz
   ```

2. **Check PHP is using the correct php.ini:**
   ```bash
   php --ini
   ```

3. **Make sure the extension is enabled in the correct php.ini file:**
   ```ini
   extension=rapidfuzz.so
   ```

4. **If using PHP CLI, you may need to specify the extension path explicitly:**
   ```bash
   php -d extension=modules/rapidfuzz.so script.php
   ```

### PHP API

```php
<?php

// Basic ratio - simple Levenshtein distance normalized to 0-100
$result = rapidfuzz_fuzz_ratio("hello", "hello");       // 100.0
$result = rapidfuzz_fuzz_ratio("hello", "world");        // ~40.0

// Partial ratio - best partial match with substrings
$result = rapidfuzz_fuzz_partial_ratio("hello", "say hello world"); // 100.0

// Token sort ratio - tokens sorted alphabetically
$result = rapidfuzz_fuzz_token_sort_ratio("world hello", "hello world"); // 100.0

// Token set ratio - tokens as sets
$result = rapidfuzz_fuzz_token_set_ratio("hello world", "world hello"); // 100.0

// With score cutoff - returns 0 if below threshold
$result = rapidfuzz_fuzz_ratio("abc", "xyz", 50.0); // 0.0 (below 50%)
```

## Functions

| Function | Description |
|----------|-------------|
| `rapidfuzz_fuzz_ratio(s1, s2, score_cutoff)` | Simple ratio between two strings |
| `rapidfuzz_fuzz_partial_ratio(s1, s2, score_cutoff)` | Partial ratio with substrings |
| `rapidfuzz_fuzz_token_sort_ratio(s1, s2, score_cutoff)` | Token sort ratio |
| `rapidfuzz_fuzz_token_set_ratio(s1, s2, score_cutoff)` | Token set ratio |

All functions return a float between 0 and 100, where 100 means identical strings.

## Testing

```bash
# Install dependencies
composer install

# Run tests
./vendor/bin/phpunit
```

## Performance

The extension significantly outperforms the popular [fuzzywuzzy](https://github.com/wyndow/fuzzywuzzy) PHP library. The benchmark compares `tokenSetRatio` from FuzzyWuzzy with `rapidfuzz_fuzz_token_set_ratio` from this extension:

![Performance Comparison](tests/Rapidfuzz%20vs%20Fuzzy.png)

The benchmark compares string matching performance with strings up to 500 characters. The extension leverages C++ optimizations and SIMD instructions, providing substantial speed improvements for fuzzy string matching operations.
