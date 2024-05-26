#include "iostream"
using namespace std;

int helper(int& a, int& b, int& c){
    int ans = a+b+c;
    if (ans%2) return -1;
    int mxPoint = c, mnPoint = a, mxDraw = mnPoint, totalGame = ans/2;
    if (mxPoint > totalGame) return -1;
    else return mxDraw;
}

int main(){
    int n=0;
    cin>>n;
    while (n--){
        int a=0, b=0, c=0;
        cin>>a;
        cin>>b;
        cin>>c;
        cout<<helper(a, b, c)<<"\n";
    }
    cout<<"\n\n";
    system("pause");
    return 0;
}