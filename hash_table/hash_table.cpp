#include <iostream>
#include<string>
#include<vector>
#define cls system("cls")
#define pause system("pause")
#define HASH_TABLE_SIZE 1000
#define loop(n) for ( int i = 0; i < n; i++)

using namespace std;

#if 0
string hash_table[HASH_TABLE_SIZE];

int hash_function(string s){
    loop(s.length())
        if (s[i] > 'a') 
            return (s[i] - 'a' );
    
}

#if 0  // Linear Probing Method
void insert(string s){
    getline(cin, s);
    int index = hash_function(s);
    while(hash_table[index] != ""){
        index = (index + 1) % HASH_TABLE_SIZE;
    }

    hash_table[index] = s;
}

int search(string s){
    int index = hash_function(s);
    while(hash_table[index] != "" && hash_table[index] != s){
        index = (index + 1) % HASH_TABLE_SIZE;
    }

    if(hash_table[index] == s)
        return index;
    else
        return -1;
}
#endif  

#if 0   // Quadratic Probing Method
void insert(string s){
    getline(cin, s);
    int k = 1;
    int index = hash_function(s);
    while(hash_table[index] != ""){
        index = (index + k*k) % HASH_TABLE_SIZE;
        k++;
    }

    hash_table[index] = s;
}

int search(string s){
    int index = hash_function(s);
    int k = 1;
    while(hash_table[index] != "" && hash_table[index] != s){
        index = (index + k*k) % HASH_TABLE_SIZE;
        k++;
    }

    if(hash_table[index] == s)
        return index;
    else
        return -1;
}
#endif 

#endif

#if 1   // Direct chaining Method - Linked List
vector<string> hash_table[HASH_TABLE_SIZE];
int hash_function(string s){
    loop(s.length())
        if (s[i] > 'a') 
            return (s[i] - 'a' );
    
}

void insert(string s){
    getline(cin, s);
    int index = hash_function(s);
    hash_table[index].push_back(s);
}

bool search(string s){
    int index = hash_function(s);
    for (auto ss:hash_table[index])
        if (ss==s)
            return true;

    return false;
}
#endif 

int main(){
    cls;
    cout << "Input total of string for search: ";
    int n;
    string s;
    cin >> n;
    cin.ignore();
    loop(n){
        cout << "Input string " << i + 1 << ": ";
        insert(s);
    }

   loop(1){
        cout << "\nIndex of "<< "test: " << search("test");
   }
   pause;
}

