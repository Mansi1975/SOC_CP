#include <iostream>
#include <stack>
#include <string>
using namespace std;

string revstr(string s){
    
    stack<char> st;
    for(char c : s){
        st.push(c);
    }
    string result = "";
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;

}

int main(){
    string s, str2;

    //cout << "Enter word s: ";
    cin >> s;

    //cout << "Enter word t: ";
    cin >> str2;

   string t = revstr(str2);
   //string ans;

//    for(int i=0; i<t.length(); i++){
//        if(s[i]!=t[i]){
//        ans = "NO";
//    } else {
//     ans = "YES";
//    }

//    }

if (s == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
//cout << ans << endl;
    return 0;
}