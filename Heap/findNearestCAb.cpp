#include <bits/stdc++.h>
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    /*
    5 3
    C1 1 1
    C2 2 1
    C3 3 2
    C4 0 1
    C5 2 3
    */
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class Car
{
public:
    string id;
    int x;
    int y;
    Car(string id, int x, int y) : id(id), x(x), y(y) {}
    int dist() const
    {
        return (x * x + y * y);
    }
};

// bool compare = [](const Car& c1, const Car& c2){
//     return c1.dist() < c2.dist();
// };
class compare
{
public:
    bool operator()(const Car c1, const Car c2)
    {
        return c1.dist() < c2.dist();
    }
};

void printNearestCar(vector<Car> cars, int k)
{
    //priority_queue<Car, vector<Car>, decltype(compare)>heap(cars.begin(), cars.begin()+k);
    
    priority_queue<Car, vector<Car>, compare> heap(cars.begin(), cars.begin() + k);
    
    //if distance of any cab out of rest cabs is smaller than largest element of heap;
    //then add it to heap;
    for(int i = k; i<cars.size(); i++){
        Car car = cars[i];
        if(cars[i].dist() < heap.top().dist()){ heap.pop(); heap.push(car); }
    }
    //prints K nearest cabs in descending order by distance 
    // while(!heap.empty()){
    //     cout<<heap.top().id<<endl;
    //     heap.pop();
    // }

    //to print in ascending order by distance;
    vector<Car> output;
    while (!heap.empty())
    {
        output.push_back(heap.top());
        heap.pop();
    }
    sort(output.begin(), output.end(), [](const Car A, const Car B)
         { return A.dist() < B.dist(); });
    for (auto i : output)
    {
        cout << i.id << endl;
    }
    return;
}

int main()
{
    file_i_o();
    int N, K;
    cin >> N >> K;

    string id;
    int x, y;
    vector<Car> vec;
    for (int i = 0; i < N; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        vec.push_back(car);
    }
    printNearestCar(vec, K);
    return 0;
}
