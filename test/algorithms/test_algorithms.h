#ifndef TEST_ALGORITHMS_H
#define TEST_ALGORITHMS_H

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

// make streamable for boost test:
namespace std {
inline std::ostream &boost_test_print_type(std::ostream &os,
                                           std::array<int32_t, 8> const &arr) {
  os << "{";
  for (char const *sep = ""; auto const &el : arr)
    os << std::exchange(sep, ", ") << el;
  return os << "}";
}
} // namespace std
#endif // TEST_ALGORITHMS_H
