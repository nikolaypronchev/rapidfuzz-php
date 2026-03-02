PHP_ARG_ENABLE(rapidfuzz, whether to enable rapidfuzz support,
[  --enable-rapidfuzz           Enable rapidfuzz support])

if test "$PHP_RAPIDFUZZ" != "no"; then
  PHP_REQUIRE_CXX()
  PHP_NEW_EXTENSION(rapidfuzz, src/rapidfuzz.cpp, $ext_shared)

  # Include path for rapidfuzz-cpp headers
  PHP_ADD_INCLUDE(rapidfuzz-cpp)

  # Add -fPIC to CXXFLAGS
  CXXFLAGS="-fPIC -g -O2"
fi
