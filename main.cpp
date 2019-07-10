#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/find-common-characters/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> s;
        if (A.empty()) return s;
        vector<int> let(26);
        for (auto c: A[0])
            ++let[c - 'a'];
        for (int i = 1; i < A.size(); ++i) {
            vector<int> cur(26);
            for (auto c: A[i])
                ++cur[c - 'a'];
            for (int j = 0; j < 26; ++j) {
                let[j] = min(let[j], cur[j]);
            }
        }
        for (int k = 0; k < 26; ++k) {
            while (let[k]) {
                string p(1, (char)('a' + k));
                s.push_back(p);
                --let[k];
            }
        }
        return s;
    }
};

void test1() {
    vector<string> v1{"bella","label","roller"};

    cout << " ? " << Solution().commonChars(v1) << endl;
}

void test2() {

}

void test3() {

}