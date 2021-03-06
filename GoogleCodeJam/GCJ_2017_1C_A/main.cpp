#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
#include <limits>
#include <cassert>
#include <math.h>
#include <tuple>
#include <memory.h>

//#pragma comment(linker, "/STACK:134217728")

using namespace std;
using namespace tr1;

#define all(c) (c).begin(), (c).end()
#define CLEAR(x) memset(x,0,sizeof x)

typedef long long ll;
typedef unsigned long long ull;

void solve(int test)
{
   printf("Case #%d: ", test + 1);
   int n;
   int k;
   cin >> n;
   cin >> k;
   vector<tuple<double, int, int>> pk;
   double r;
   double h;
   double p;
   const double pi = std::acos(-1);
   for (int i = 0; i < n; ++i) {
      cin >> r;
      cin >> h;
      p = pi*(r*r + 2 * r*h);
      pk.push_back(make_tuple(p, h, r));
   }

   sort(pk.rbegin(), pk.rend());

   double totalH = 0;

   double result = 0;
   
   for (int i = 0; i < k; ++i) {
      r = get<2>(pk[i]);
      h = get<1>(pk[i]);
      result += 2 * r*h;
   }
   r = get<2>(pk[0]);

   result = pi*(result + r*r);

   printf("%.8f\n", result);

} 

int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   int tests;
   scanf("%d", &tests);

   for (int test = 0; test < tests; ++test)
   {
      fprintf(stderr, "Solving %d/%d\n", test + 1, tests);
      solve(test);
   }

   return 0;
}
