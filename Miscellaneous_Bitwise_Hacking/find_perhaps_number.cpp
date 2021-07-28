#include<iostream>
#include<vector>
#include<unordered_map>

#define ll long long int
#define cls system("cls")
#define pause system("pause")

using namespace std;

int main() {
    cls;
    ll res = 0;
    ll n;
    cout << "Input a number of element: ";
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cout << "Input element " << i + 1 << ": ";
        cin >> v[i];
    }

    unordered_map<ll, ll> map;
    for (ll i : v)
        map[i]++;
    for (auto m : map)
        if (m.second & 1)
            res++;
    cout <<"There are " << res << " numbers that appear maybe times in the array.";
    pause;
}