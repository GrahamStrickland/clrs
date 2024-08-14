#include <boost/test/included/unit_test.hpp>

#include "../../src/algorithms/search/binary_search.h"
#include "../../src/algorithms/search/linear_search.h"
#include "../../src/algorithms/search/recursive_binary_search.h"

BOOST_AUTO_TEST_SUITE(test_search)

BOOST_AUTO_TEST_CASE(test_binary_search) {
  int32_t A[] = {26, 31, 41, 41, 58, 59};
  uint8_t len = 6;
  int32_t nu = 31;
  int32_t obs = -1;
  int32_t exp = 1;

  obs = binary_search(A, len, nu);
  BOOST_ASSERT(obs == exp);

  nu = 32;
  exp = -1;
  obs = binary_search(A, len, nu);
  BOOST_ASSERT(obs == exp);

  int32_t B[] = {1, 4, 5, 7, 19, 28, 45, 92};
  len = 8;
  nu = 92;
  exp = 7;
  obs = binary_search(B, len, nu);
  BOOST_ASSERT(obs == exp);

  nu = 101;
  exp = -1;
  obs = binary_search(B, len, nu);
  BOOST_ASSERT(obs == exp);
}

BOOST_AUTO_TEST_CASE(test_linear_search) {
  int32_t A[] = {31, 41, 59, 26, 41, 58};
  uint8_t len = 6;
  int32_t nu = 31;
  int32_t obs = -1;
  int32_t exp = 0;

  obs = linear_search(A, len, nu);
  BOOST_ASSERT(obs == exp);

  nu = 32;
  exp = -1;
  obs = linear_search(A, len, nu);
  BOOST_ASSERT(obs == exp);

  int32_t B[] = {1, 4, 39, 99, 100, 20};
  nu = 39;
  exp = 2;
  obs = linear_search(B, len, nu);
  BOOST_ASSERT(obs == exp);

  nu = 101;
  exp = -1;
  obs = linear_search(B, len, nu);
  BOOST_ASSERT(obs == exp);
}

BOOST_AUTO_TEST_CASE(test_recursive_binary_search) {
  int32_t A[] = {26, 31, 41, 41, 58, 59};
  uint8_t len = 6;
  int32_t nu = 31;
  int32_t obs = -1;
  int32_t exp = 1;

  obs = recursive_binary_search(A, nu, 0, len);
  BOOST_ASSERT(obs == exp);

  nu = 32;
  exp = -1;
  obs = recursive_binary_search(A, nu, 0, len);
  BOOST_ASSERT(obs == exp);

  int32_t B[] = {1, 4, 5, 7, 19, 28, 45, 92};
  len = 8;
  nu = 7;
  exp = 3;
  obs = recursive_binary_search(B, nu, 0, len);
  BOOST_ASSERT(obs == exp);

  nu = 101;
  exp = -1;
  obs = recursive_binary_search(B, nu, 0, len);
  BOOST_ASSERT(obs == exp);
}

BOOST_AUTO_TEST_SUITE_END()
