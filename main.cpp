#include "Template.hpp"
#include "user.hpp"

int main()
{
    fastio;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, r;
        string y, z;
        cin >> x >> y >> z >> r;

        User user(x, y, z);

        if(r != -1) user.updateRating(r);
        debug(user);
        print(user);
    }
}