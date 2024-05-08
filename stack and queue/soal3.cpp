#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> mystack;
    while (N--) {
        string word;
        cin >> word;

        if (word == "push") {
            int num;
            cin >> num;
            mystack.push(num);
        } else if (word == "pop" && !mystack.empty()) {
            mystack.pop();
        }

        if (!mystack.empty()) {
            stack<int> temp = mystack;
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
        } else {
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
