#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(2);
    st.push(3);
    st.push(6);

    cout << st.top(); //6
    st.pop(); //���� ���� ����
    cout << st.top(); //3

    return 0;
}