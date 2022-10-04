#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct person {
    double x;
    double t;
};
bool fn(person a , person b) {
    return a.x < b.x;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, jMax {};
        double maxTi {}, xiMax {}, sum {};
        cin >> n;
        person person[n] {};
        for (int j = 0; j < n; j++) {
            cin >> person[j].x;
        }
        for (int j = 0; j < n; j++) {
            cin >> person[j].t;
            if (maxTi < person[j].t) {
                maxTi = person[j].t;
                xiMax = person[j].x;
                jMax = i;
            }
        }
        for (int j = 0; j < n; j++) {
            if (j != jMax) {
                if (person[j].x < xiMax) {
                    double newXi = person[j].x + maxTi - person[j].t;
                    if (newXi > xiMax)
                        person[j].x = xiMax;
                    else
                        person[j].x = newXi;
                } else if (person[j].x == xiMax) {
                    sum += person[j].x;
                    continue;
                }

                else {
                    double newXi = person[j].x - maxTi + person[j].t;
                    if (newXi < xiMax)
                        person[j].x = xiMax;
                    else
                        person[j].x = newXi;
                }
            }
            //sum += person[j].x;

        }
        sort(person, person + n, fn);

        //double res = sum / (double) n;
        double res = (person[0].x + person[n-1].x) / 2;
        cout << setprecision(2) << res << endl;


    }
    return 0;
}
