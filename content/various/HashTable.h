/**
 * Author: Loke Gustafsson
 * Date: 2025-02-27
 * License: CC0
 * Description: Fast hashmap. Default value 0 for all keys. 
 */
#pragma once

typedef uint64_t ull;
ull C = 3'964'846'488'687'501'853;
template<class T>
struct HashMap {
  int b;
  vector<pair<ull, T>> v;
  HashMap(int b) : b(b), v(1<<b) {}
  T& operator[](ull x) { // x=0 NOT OK. All others ok
    ull y = (x*(ull)C) >> (64 - b), m = (1<<b) - 1;
    while (v[y].first && v[y].first != x) ++y &= m;
    v[y].first = x;
    return v[y].second;
  }
};
ull hsh(ull a, ull b, ull c) {
  return ((a*C +b)*C +c)*C;
}
