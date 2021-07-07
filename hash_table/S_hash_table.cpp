#include <iostream>
#include<string>
#include<vector>
#define cls system("cls")
#define pause system("pause")
#define lli long long int
#define HASH_TABLE_SIZE 7
#define loop(n) for ( int i = 0; i < n; i++)

using namespace std;

#if 1
    string hash_table[HASH_TABLE_SIZE];

    lli hash_function(string s){  // improve
        lli sum = 0;
        loop(s.length())
            sum = sum * 31 + (lli)s[i]; //  ' 31 ' is the best choose for hashing
        return sum % HASH_TABLE_SIZE;
    }

    #if 1  
        void insert(string s){
            getline(cin, s);
            int index = hash_function(s);
            while(hash_table[index] != ""){
                index = (index + 1) % HASH_TABLE_SIZE;
            }
            hash_table[index] = s; 
        }

        int search(string s){
            lli index = hash_function(s);
            while(hash_table[index] != "" && hash_table[index] != s){
                index = (index + 1) % HASH_TABLE_SIZE;
            }

            if(hash_table[index] == s)
                return index;
            else
                return -1;
        }
    #endif // Linear Probing Method

    #if 0  
        void insert(string s){
            getline(cin, s);
            int k = 1;
            lli index = hash_function(s);
            while(hash_table[index] != ""){
                index = (index + k*k) % HASH_TABLE_SIZE;
                k++;
            }

            hash_table[index] = s;
        }

        int search(string s){
            lli index = hash_function(s);
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
    #endif // Quadratic Probing Method

#endif // Not use linked list

#if 0  
    vector<string> hash_table[HASH_TABLE_SIZE];
    int hash_function(string s){ // focus array
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
#endif // Direct chaining Method - Linked List

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

