// NOT complete.
#include<iostream>
#include<stack>
using namespace std;

int main(){
  stack<int> st;
  char in;
  int tot_sect = 0;

  for (int i; cin >> in; i++) {
    if (in == '\\') st.push(i);
    else if (in == '/' && st.size() > 0) {
      int j = st.top(); st.pop();
      tot_sect += i - j;
      cout << tot_sect << endl;
    }
  }

  cout << tot_sect << endl;

  return 0;
}
