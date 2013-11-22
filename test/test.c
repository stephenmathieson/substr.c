
#include "describe.h"
#include "../src/substr.h"

int main(int argc, char **argv) {
  describe("substr", {
    it("should return NULL when given a negative starting index", {
      assert(NULL == substr("foo", -1, 10));
    });
    it("should return NULL when given an ending index lower than the starting index", {
      assert(NULL == substr("foo", 10, 3));
    });
    it("should return NULL when given a starting index larger than the string's length", {
      assert(NULL == substr("foo", 400, 500));
    });
    it("should return NULL when given an ending index larger than the string's length", {
      assert(NULL == substr("foo", 1, 500));
    });
    it("should return substrings of strings", {
      assert_str_equal("hello", substr("hello world", 0, 5));
      assert_str_equal("world", substr("hello world", 6, 11));
    });
    it("should copy strings when given the entire array", {
      char foo[] = "foo";
      char *res = substr(foo, 0, 3);
      assert_str_equal(foo, res);
      foo[0] = 'g';
      assert_str_not_equal(foo, res);
    });
  });
  return 0;
}
