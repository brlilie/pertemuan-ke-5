#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> myQ;
    while (N--) {
        string word;
        cin >> word;

        if (word == "push") {
            int num;
            cin >> num;
            myQ.push(num);
        } else if (word == "pop" && !myQ.empty()) {
            myQ.pop();
        }

        if (!myQ.empty()) {
            queue<int> temp = myQ;
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
        } else {
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}