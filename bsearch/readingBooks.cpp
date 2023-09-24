//Given number of pages in n different books and m students. The are arranged in any order(not necessarily ascendign) of number of pages. 
//Every student is assigned to read some consecutive segment of books. Thes task is to assign books in such a way that the maximum of number  of 
//pages asigned to a student is minimum.
//Find the maxinum number of pages that a student will have to read.
#include<bits/stdc++.h>
using namespace std;

int_least32_t canAssign(vector<int> books, int pages_limit){
 int current_pages = 0, assigned = 0;
 cout<<endl;
 for( int i = 0; i<books.size(); i++){
    if(current_pages + books[i] >= pages_limit){
        assigned++;
        current_pages = books[i];
    }
    else{ current_pages += books[i]; }
 }
 return assigned;
}

int readingBooks(vector<int> books, int students ){
sort(books.begin(), books.end());
int max = INT_MIN, answer = 0;
 int s, e = 0; for( auto i : books){
    if(i>max){ max = i; }
    e += i;  }
    s = max;
    while(s <= e){
        int mid = s + (e-s)/2;
        int temp = canAssign(books, mid);
        if( temp >= students){
            answer = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return answer;
}

int main(){
    vector<int> books = {10, 20, 30, 15};
    int students = 2;
    cout<<readingBooks(books, students);
}
