#include <cstdio>
#include <cmath>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <memory.h>
#include <memory>
#include <functional>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <functional>

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

string s[101];

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        cin >> s[i];
    
    int ans = 0;
    for(char ch = 'a' ; ch <= 'z' ; ++ch)
    {
        bool fl = 1;
        for(int i = 0 ; fl && i < n ; ++i)
        {
            fl = 0;
            for(int j = 0 ; j < s[i].size() ; ++j)
            if(s[i][j] == ch)
                fl = 1;
        }
        if(fl)
            ++ans;
    }
    cout << ans << "\n";
    return 0;
}