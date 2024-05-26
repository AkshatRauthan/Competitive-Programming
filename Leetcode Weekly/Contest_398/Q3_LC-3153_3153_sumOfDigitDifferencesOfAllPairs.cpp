#include "iostream"
#include "vector"
using namespace std;

long long sumDigitDifferences(vector<int>& v) {
    int n = v.size();
    vector<vector<long long>> aux(12 , vector<long long>(10));
    for(int i = 0; i<n; i++){
        int x = v[i] , pos = 0;
        while(x){
            aux[pos][x%10]+=1;
            pos+=1;
            x/=10;
        }
    }
    long long ans = 0;
    for(int pos = 0;pos<12;pos++){
        for(int i = 0;i<10;i++){
            for(int j = i+1;j<10;j++){
                long long curr = aux[pos][i]*aux[pos][j];
                ans += curr;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"\n\nEnter The Number Of Elements In The Vector : \n";
    cin>>n;
    vector<int> v(n, 0);
    cout<<"\n\nEnter The "<<n<<" Elments Of The Vector :\n";
    for (int i=0; i<n; i++) cin>>v[i];
    long long ans = sumDigitDifferences(v);
    cout<<"\n\nThe Required Sum Is : "<<ans;
    cout<<"\n\n";
    system("pause");
}