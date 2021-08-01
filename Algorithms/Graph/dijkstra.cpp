
#include <iostream>
#include<cstring>

using namespace std;

const int inf = 9999999;
int way[1001][1001];
int d[1001];
int visited[1001];
int n, m;

void solve(){
	cin >> n >> m;

	memset(way, -1, sizeof way);
	
	for(int i = 0; i < n; ++i){
		visited[i] = false;
		d[i] = inf;
	}

	for (int i = 0; i < m; ++i){
		int a, b, k;
		cin >> a >> b >> k;
		way[a][b] = k;
	}

	int start; 
    cin >> start; 

	for (int node = 0; node < n; ++node){
		for (int i = 0; i < n; ++i){
			
			if (way[start][i] != -1 && d[i] > d[start] + way[start][i]) 
				d[i] = d[start] + way[start][i];
		}

		visited[start] = true;
		int point = inf;

		for (int i = 0; i < n; ++i){
			if (visited[i] == false && point > d[i]){
				point = d[i];
				start = i;
			}
		}
	}

	for(int i = 0; i < n; ++i){
		cout << d[i] << " ";
	} cout << endl;
}

int main (){
    solve();
}