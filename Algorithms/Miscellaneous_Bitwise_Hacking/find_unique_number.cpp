#include <iostream>
#include<unordered_map>
#include<vector>

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

	for(int i = 0; i < n; i++)
		res^=v[i];

    cout << "The number that appears perhaps times in the array : "<< res ;
    pause;
    return 0;
}