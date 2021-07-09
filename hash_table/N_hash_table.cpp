#include <iostream>
#include<string>
#include<vector>
#include<math.h>
#define MAX 7
#define cls system("cls")
#define pause system("pause")
#define lli long long int
#define HASH_TABLE_SIZE MAX
#define Modified_HASH_TABLE_SIZE MAX + 1
#define ELEMENT_FOR_HASH MAX + 7
#define loop(n) for ( int i = 0; i < n; i++)

using namespace std;

#if 1 
    lli hash_table[HASH_TABLE_SIZE] = {}; // make all element = 0 

    #if 1 
        #if 1
            lli hash_function(lli n ){  
                return n % HASH_TABLE_SIZE;
            }
        #endif // Division method 

        #if 0
            lli hash_function(lli n ){  
                return (int)(n*HASH_TABLE_SIZE / ELEMENT_FOR_HASH);
            }
        #endif // Uniform hash function

        #if 0
            lli hash_function(lli n ){  
                return (int)(HASH_TABLE_SIZE *(n * (sqrt(5) - 1) / 2  - (int)(n * (sqrt(5) - 1) / 2)));
            }
        #endif // Multiplication with GOLDEN RADIO method
    #endif // Init hash_table

    #if 1 
        #if 0  
            void insert(lli n){
                cin >> n;
                lli index = hash_function(n);
                while(hash_table[index] != 0 && hash_table[index] != -1){
                    index = (index + 1) % HASH_TABLE_SIZE;
                }
                hash_table[index] = n; 
            }

            int search(lli  n){
                lli index = hash_function(n);
                while(hash_table[index] != 0 && hash_table[index] != n ){
                    index = (index + 1) % HASH_TABLE_SIZE;
                }

                if(hash_table[index] == n)
                    return index;
                else
                    return -1;
            }

            void remove(lli n ){
                for (lli i = 0; i < HASH_TABLE_SIZE; i++)
                    if (hash_table[i] == n)
                        hash_table[i] = -1; // mark deleted location
            }
        #endif // Linear Probing Method

        #if 0  
            void insert(lli n){
                cin >> n;
                int index = hash_function(n);
                while(hash_table[index] != 0 && hash_table[index] != -1 ){
                    index = (index + 1*Modified_HASH_TABLE_SIZE) % HASH_TABLE_SIZE;
                }
                hash_table[index] = n; 
            }

            int search(lli  n){
                lli index = hash_function(n);
                while(hash_table[index] != 0 && hash_table[index] != n ){
                    index = (index + 1) % HASH_TABLE_SIZE;
                }

                if(hash_table[index] == n)
                    return index;
                else
                    return -1;
            }

            void remove(lli n ){
                for (lli i = 0; i < HASH_TABLE_SIZE; i++)
                    if (hash_table[i] == n)
                        hash_table[i] = -1; // mark deleted location
            }
        #endif // Modified Linear Probing Method, fix " primary clustering " from " Linear Probing Method "

        #if 1   
            #if 1 
                void insert(lli n){ 
                    cin >> n;
                    int k = 1;
                    lli index = hash_function(n);
                    lli temp = index;
                    while(hash_table[temp] != 0 && hash_table[temp] != -1){
                        temp = (index + k*k) % HASH_TABLE_SIZE;
                        k++;
                    }

                    hash_table[temp] = n;
                }

                int search(lli n){
                    lli index = hash_function(n);
                    lli temp = index;
                    int k = 1;
                    while(hash_table[temp] != 0 && hash_table[temp] != n){
                        temp = (index + k*k) % HASH_TABLE_SIZE;
                        k++;
                    }

                    if(hash_table[temp] == n)
                        return temp;
                    else
                        return -1;
                }
            #endif // Quadratic Probing Method without Linearing

            #if 1 
                void insert(lli n){ 
                    cin >> n;
                    int k = 1;
                    lli index = hash_function(n);
                    while(hash_table[index] != 0 && hash_table[index] != -1){
                        index = (index + k*k) % HASH_TABLE_SIZE;
                        k++;
                    }

                    hash_table[index] = n;
                }

                int search(lli n){
                    lli index = hash_function(n);
                    int k = 1;
                    while(hash_table[index] != 0 && hash_table[index] != n){
                        index = (index + k*k) % HASH_TABLE_SIZE;
                        k++;
                    }

                    if(hash_table[index] == n)
                        return index;
                    else
                        return -1;
                }
            #endif // Quadratic Probing Method with Linearing

            void remove(lli n ){
                for (lli i = 0; i < HASH_TABLE_SIZE; i++)
                    if (hash_table[i] == n)
                        hash_table[i] = -1; // mark deleted location
            }
        #endif // Quadratic Probing Method

        #if 1   

            #if 0
                lli hash_function_second(lli n ){  
                    return n % (HASH_TABLE_SIZE - 2);
                }
                void insert(lli n){
                    cin >> n;
                    lli index = hash_function(n);
                    while(hash_table[index] != 0 && hash_table[index] != -1 ){
                        index = (index + 1*hash_function_second(n)) % HASH_TABLE_SIZE;
                    }
                    hash_table[index] = n; 
                }

                int search(lli  n){
                    lli index = hash_function(n);
                    while(hash_table[index] != 0 && hash_table[index] != n ){
                        index = (index + 1*hash_function_second(n)) % HASH_TABLE_SIZE;
                    }

                    if(hash_table[index] == n)
                        return index;
                    else
                        return -1;
                }
            #endif // Double hashing - simple

            #if 1

                lli hash_function_second(lli n ){  
                    return (HASH_TABLE_SIZE - 2) - n % (HASH_TABLE_SIZE - 2);
                }

                void insert(lli n){
                    cin >> n;
                    lli index = hash_function(n);
                    while(hash_table[index] != 0 && hash_table[index] != -1 ){
                        index = (index + 1*hash_function_second(n)) % HASH_TABLE_SIZE;
                    }
                    hash_table[index] = n; 
                }

                int search(lli  n){
                    lli index = hash_function(n);
                    while(hash_table[index] != 0 && hash_table[index] != n ){
                        index = (index + 1*hash_function_second(n)) % HASH_TABLE_SIZE;
                    }

                    if(hash_table[index] == n)
                        return index;
                    else
                        return -1;
                }
            #endif // Double hashing - fix " hash_function = hash_function_second " 

            void remove(lli n ){
                for (lli i = 0; i < HASH_TABLE_SIZE; i++)
                    if (hash_table[i] == n)
                        hash_table[i] = -1; // mark deleted location
            }
        #endif // Double hashing, fix secondary clustering " from " Quadratic Probing Method "

    #endif
#endif // Not use linked list

#if 0   // Direct chaining Method - Linked List
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
#endif 
//#endif
int main(){
    cls;
    string s = "Not found !!! ";
    cout << "Input total of number for search: ";
    int n;
    lli k;
    cin >> n;
    loop(n){
        cout << "Input number " << i + 1 << ": ";
        insert(k);
    } 
    loop(1){
        cout << "\nIndex of "<< "35: ";
        if (search (35) != -1)
            cout << search(35);
        else 
            cout << s;
   }

   pause;
}

