#include<bits/stdc++.h>
using namespace std;

int canAssign(vector<int> books, int pages){
    int stud = 1, pagesAssigned = 0;
    for( int i = 0; i<books.size(); i++){
        if(pagesAssigned + books[i] <= pages){
            pagesAssigned += books[i];
        }
        else{
            stud++;
            pagesAssigned = books[i];
        }
    }
    return stud;
}

int readingBooks(vector<int> books, int m){
  int s = 0, e = 0, ans =0, val = 0;
  for(auto i : books){
    s = max(s, i);
    e = e + i;
  }
  while( s <= e){
    int mid = s + (e-s)/2;
    int students = canAssign(books, mid);
    if( students <= m){
        ans = mid;
        e = mid - 1;
    }
    else s = mid + 1;
  }
  return ans;
}
//0 1 2 3 -- 2
//0 1 2 3 4 5 6 7 8 9 10 -- 4
//0 1 2 3 4 5 6 7 8 9 -- 5

int main(){
    // vector<int> books = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int m = 4;
    vector<int> books = {10, 20, 30, 15};
    int m = 2;

// student can be assigned either one book or all books
// max pages possible to assign to a student from one book is book with max pages;
// max pages possible to assign to a student from all books is sum of all pages;
// assign books s.t. max no. of pages assigned is minimum.

cout<<readingBooks(books, m);

}