#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, c, res = 0;
        cin >> n >> c;
        int planets[100] {};
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            planets[a-1]++;
        }
        for (int j = 0; j < 100; j++) {
            if (planets[j] < c)
                res += planets[j];
            else
                res += c;
        }
        cout << res <<endl;
    }
    return 0;
}
