#include <bits/stdc++.h>
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
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
    // create max heap of size K

    priority_queue<Car, vector<Car>, compare> max_heap(cars.begin(), cars.begin() + k);
    for (int i = k; i < cars.size(); i++)
    {
        Car car = cars[i];
        if (car.dist() < max_heap.top().dist())
        {
            max_heap.pop();
            max_heap.push(car);
        }
    }
    // all the car inside heap will now be closest k cars
    vector<Car> output;
    while (!max_heap.empty())
    {
        output.push_back(max_heap.top());
        max_heap.pop();
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