
// valid Parantheses ({[]})

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool ok = true;
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                ok = false;
            }
            else
            {
                if (c == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (c == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else if (c == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    ok = false;
                }
            }
        }
    }
    if (ok)
        cout << "It's Valid" << endl;
    else
        cout << "Not Valid" << endl;
    return 0;
}