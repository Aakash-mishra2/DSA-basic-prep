//Given number of pages in n different books and m students. The are arranged in any order(not necessarily ascendign) of number of pages. 
//Every student is assigned to read some consecutive segment of books. Thes task is to assign books in such a way that the maximum of number  of 
//pages asigned to a student is minimum.
//Find the maxinum number of pages that a student will have to read.
#include<bits/stdc++.h>
using namespace std;

int_least32_t canAssign(vector<int> books, int pages_limit){
        int current_pages = 0, assigned = 1;
        for( int i = 0; i<books.size(); i++){
            if( current_pages + books[i] <= pages_limit ){
                current_pages += books[i];
            }
            else{
                assigned += 1;
                current_pages = books[i];
            }
        }
    return assigned;
}

int readingBooks(vector<int> books, int students ){
    int s = 0, e = 0, ans;
    for(auto i : books){
        if ( i > s){ s = i; }
        e += i;
    }

    while( s<=e ){
        int mid = s + (e - s)/2;
        int st = canAssign(books, mid);
        if( st <= students ){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> books = {10, 20, 30, 15};
    int students = 2;
    cout<<readingBooks(books, students);
}
