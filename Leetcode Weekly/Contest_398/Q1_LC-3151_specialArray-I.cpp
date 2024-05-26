#include "iostream"
#include "vector"
using namespace std;

bool isArraySpecial(vector<int>& v) {
    int a=0, b =0;
    for (int i=0; i<v.size()-1; i++){
        a = v[i]%2, b = v[i+1]%2;
        if (a == b) return false;
    }
    return true;
}

int main(){
    int n;
    cout<<"\n\nEnter The Number Of Elements In The Array : \n";
    cin>>n;
    vector<int> v(n, 0);
    cout<<"\n\nEnter The "<<n<<" Elements of The Vector : \n";
    for (int i=0; i<n; i++) cin>>v[i];
    if (isArraySpecial(v)) cout<<"\n\nYes, The Given Array Is A Special Array.";
    else cout<<"\n\nNo, The Given Array Is Not An Spical Array. ";
    cout<<"\n\n";
    system("pause");
}