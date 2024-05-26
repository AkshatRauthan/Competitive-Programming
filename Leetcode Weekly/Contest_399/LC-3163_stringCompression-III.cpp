#include "iostream"
#include "string"
using namespace std;

string compressedString(string str) {
    string ans = "";
    for (int i=0; i<str.length(); i++){
        int n = 1;
        char f = str[i];
        while (str[i] == str[i+1] && n < 9) i++, n++;
        ans += to_string(n) + str[i];
    }
    return ans;
}

int main(){
    string s = "";
    cout<<"\n\nEnter The Input String : \n";
    cin>>s;
    string ans = compressedString(s);
    cout<<"\n\nThe Compressed String Is : "<<ans;
    cout<<"\n\n";
    system("pause");
}