#include <iostream>
#include <vector>

#define maxN 101
#define inf 0xfffffff

using namespace std;

int nodes, edges, a, b, k; 
vector<pair<int, int> > city[maxN];
int d[maxN];

void fordBellman(int s, int n){ // Starting point - s
    
    for(int i = 0; i < n; ++i) 
        d[i] = inf;

    d[s] = 0;
    vector<pair<int,int> >::iterator it;
    for(int i = 0; i < n - 1; ++i) // n-1 iteration, we are checking for improvements in graph
        for(int j = 0; j < n; ++j) // n iteration for 
            for(it = city[j].begin(); it != city[j].end() ; ++it){
                int k = (*it).first; // cost
                int dest = (*it).second; // destination city
                d[dest] = min(d[dest], d[j] + k); // getting the min distance for the dest-node
            }
}

void solve(){
    
    cin >> nodes >> edges; 

    for(int i = 0; i < edges; ++i){
        cin >> a >> b >> k;
        city[a].push_back(make_pair(k, b));
        
    }
    
    int s;
    cin >> s; 

    fordBellman(s, nodes);

    printf("FORD BELLMAN ALGORITHM\n");
    cout<<"Point " << s<<"'s distance to every other node:\n";
    cout<<"Node\tDistance\n";
    for(int i = 0; i < nodes; ++i)
        cout << i << "\t" << d[i] << " \n";
}

int main(){

    solve();
}