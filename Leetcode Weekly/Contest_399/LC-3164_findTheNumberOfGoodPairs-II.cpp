#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    unordered_map<int, int> m1;
    for (int num : nums1) {
        ++m1[num];
    }
    long long ans = 0;
    unordered_map<int, long long> countDivisible;

    for (int num : nums2) {
        long long product = static_cast<long long>(num) * k;
        if (countDivisible.count(product)) {
            ans += countDivisible[product];  
            continue;
        }
        
        long long currentCount = 0;
        
        for (long long multiple = product; multiple <= 1000000; multiple += product) {
            if (m1.count(multiple)) {
                currentCount += m1[multiple];
            }
        }

        countDivisible[product] = currentCount;
        ans += currentCount;
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
    long long ans = numberOfPairs(v1, v2, k);
    cout<<"\n\nThe Number Of Good Pairs Bewteen The Given Vectors Is : "<<ans;
    cout<<"\n\n";
    system("pause");
}