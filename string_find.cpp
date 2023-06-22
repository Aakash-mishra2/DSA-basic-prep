#include <iostream>
#include <string>
using namespace std;

int main()
{
    string paragraph = "WE are learning about STL strings.are are UPAR SE ORDER HAI?";
    string word;
    getline(cin, word);
    size_t index = paragraph.find(word);
    if (index != -1)
    {
        cout << "first occ" << index << endl;
    }
    index = paragraph.find(word, index + 1);
    if (index != -1)
    {
        cout << "second occurence" << index << endl;
    }
    if (index == -1)
    {
        cout << "string not found. ";
    }

    return 0;
}