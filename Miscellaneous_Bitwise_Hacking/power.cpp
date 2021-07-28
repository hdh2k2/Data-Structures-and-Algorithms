#include <iostream>

#define cls system("cls")
#define pause system("pause")

using namespace std;

bool isPower_of_2(int n){
	if(!(n&(n-1)))
		return true;
	else
		return false;
}
int main() {
    cls;
    int n;
    cout << "Input a number: ";
    cin >> n;

    cout<<n<<" is power of 2:"<<(isPower_of_2(n)== 1 ? " YES":" NO");

    pause;
    return 0;
}