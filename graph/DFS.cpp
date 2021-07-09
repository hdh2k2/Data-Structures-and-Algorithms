#include <iostream>
#include<string>
#include<vector>
#define cls system("cls")
#define pause system("pause")
#define MAX_SIZE 1000
#define FOR(i,a,b) for ( int i = a; i <= b; i++)

int arr[MAX_SIZE][MAX_SIZE] = {}; // same init_array
int Stack[MAX_SIZE];
int number_of_vertices, number_of_edges, Begin_Vertex, First_Vertex, Second_Vertex;

using namespace std;

// void init_array(){
//     FOR(i,1,number_of_vertices)
//         FOR(j,1,number_of_vertices)
//             arr[i][j] = 0;
// }

void _add_edge(){
    FOR(i,1,number_of_edges){
        cin >> First_Vertex >> Second_Vertex;
        arr[First_Vertex][Second_Vertex] = 1;
        arr[Second_Vertex][First_Vertex] = 1;
    }
}

void DFS(int First_Vertex){
    cout << First_Vertex << endl;
    Stack[First_Vertex] = 0;
    FOR(Second_Vertex,1,number_of_vertices)
        if (arr[First_Vertex][Second_Vertex] == 1 && Stack[Second_Vertex])
            DFS(Second_Vertex);
}

int main(){
    cls;
    cout << "Input number_of_vertices, number_of_edges, Begin_Vertex: ";
    cin >> number_of_vertices >> number_of_edges >> Begin_Vertex;
   // init_array();
    _add_edge();
    FOR(i,1,number_of_vertices)
        Stack[i] = 1;
    DFS(Begin_Vertex);
    pause;
    return 0;
}