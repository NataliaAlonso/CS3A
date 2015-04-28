#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
    cout << "Enter an int.";
    int line;
    stack<int> s;
    cin >> line;
    s.push(line);
    line = s.top();
    cout << line;
}
