#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> st;

    st.push(2);
    st.push(3);
    st.push(6);

    cout << st.front();
    st.pop();
    cout << st.front();

    cout << st.size();

    return 0;
}