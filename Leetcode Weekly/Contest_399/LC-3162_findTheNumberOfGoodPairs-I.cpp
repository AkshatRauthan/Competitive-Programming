#include "iostream"
#include "vector"
using namespace std;

int numberOfPairs(vector<int>& v1, vector<int>& v2, int k) {
    int ans = 0;
    for (int i=0; i<v1.size(); i++){
        for (auto ele : v2) if (v1[i]%(ele*k) == 0) ans++;
    }
    return ans;
}

int main(){
    int n, m;
    cout<<"\n\nEnter The Size Of The First Vector : \n";
    cin>>n;
    vector<int> v1(n, 0);
    cout<<"\n\nEnter The "<<n<<" Elements Of The First Vector : \n";
    for (int i=0; i<n; i++) cin>>v1[i];
    cout<<"\n\nEnter The Size Of The Second Vector : \n";
    cin>>m;
    vector<int> v2(m, 0);
    cout<<"\n\nEnter The "<<m<<" Elements Of The Second Vector : \n";
    for (int i=0; i<m; i++) cin>>v2[i];
    int k = 1;
    cout<<"\n\nEnter The Value Of K : \n";
    cin>>k;
    int ans = numberOfPairs(v1, v2, k);
    cout<<"\n\nThe Number Of Good Pairs Bewteen The Given Vectors Is : "<<ans;
    cout<<"\n\n";
    system("pause");
}