#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

vector<bool> isArraySpecial(vector<int>& v, vector<vector<int>>& v1) {
    vector<bool> ans(v1.size(), false);
    unordered_map<int,int> tPairs;
    unordered_map<int,int> fPairs;
    int curr_idx = 0;
    for (auto idx : v1){
        if (idx[0] == idx[1]){
            ans[curr_idx++] = true;
            continue;
        }
        if (tPairs.find(idx[0]) != tPairs.end() && tPairs[idx[0]] >= idx[1]) ans[curr_idx++] = true;
        else if (fPairs.find(idx[0]) != fPairs.end() && fPairs[idx[0]] <= idx[1]) ans[curr_idx++] = false;
        else {
            for (int i=idx[0]; i<idx[1]; i++){
                if (v[i]%2 == v[i+1]%2){
                    fPairs[idx[0]] = max(fPairs[idx[0]], idx[1]);
                    ans[curr_idx++] = false;
                    break;
                }
                else if (i == idx[1]-1){
                    tPairs[idx[0]] = max(tPairs[idx[0]], idx[1]);
                    ans[curr_idx++] = true;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"\n\nEnter The Number Of Elements In The Array : \n";
    cin>>n;
    vector<int> v(n, 0);
    cout<<"\n\nEnter The "<<n<<" Elements of The Vector : \n";
    for (int i=0; i<n; i++) cin>>v[i];
    cout<<"\n\nEnter The Number Of Queries : \n";
    cin>>n;
    vector<vector<int>> q(n, vector<int>(2, 0));
    cout<<"\n\nEnter The "<<n<<" Queries : \n";
    for (int i=0; i<n; i++){
        cin>>q[i][0]>>q[i][1];
    }
    vector<bool> ans = isArraySpecial(v, q);
    cout<<"\n\nThe Result Of All The Queries Are As Follows : \n";
    for (bool b : ans) cout<<(b?"True":"False")<<"  ";
    cout<<"\n\n";
    system("pause");
}
