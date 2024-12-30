#include<bits/stdc++.h>
using namespace std;

void file_io(){
    ios_base::sync_with_stdio;
    cout.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main(){
    file_io();
   string input; cin>>input;
    unordered_map<char, int> M; queue<char> q;
    for(int i = 0; i<input.length(); i++){
        M[input[i]]++;
        if(M[input[i]] == 1){ q.push(input[i]); }
        while( M[q.front()] > 1){
            q.pop();
        }
        if( q.empty()){ cout<<"-1 ";}
        else cout<<q.front()<<" ";
    }
    return 0;

    /*
     file_i_o();
  queue<char> q;
  int freq[27] = {0};

  char ch;
  cin >> ch;

  // prints first non repeating letter so far in string
  while (ch != '.')
  {
    // letter
    q.push(ch);
    freq[ch - 'a']++;

    // query
    while (!q.empty())
    {
      int idx = q.front() - 'a';

      if (freq[idx] > 1)
        q.pop();

      else
      {
        cout << q.front() << endl;
        break;
      }
    }
    if (q.empty())
      cout << " -1 " << endl;
    cin >> ch;
  }

  return 0;
    */
}
