#include <bits/stdc++.h>
using namespace std;
class File
{
public:
    int start;
    string file_name;
    vector<int> blocks;
    void input()
    {
        cout << "Enter file name : ";
        cin >> file_name;
        cout << "Enter Starting block : ";
        cin >> start;
        blocks.push_back(start);
        int n;
        cout << "Enter number of additional blocks :";
        cin >> n;
        cout << "Enter " << n << " blocks : ";
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            blocks.push_back(x);
        }
    }
    void display()
    {
        cout << file_name << "\t" << start << "\t" << blocks.size() << "\t";
        for (int i = 1; i < blocks.size(); i++)
        {
            if (i > 1)
                cout << "--->";
            cout << blocks[i];
        }
        cout << endl;
    }
};
int main()
{
    int n;
    cout << "Enter number of file : ";
    cin >> n;
    vector<File> files(n);
    for (int i = 0; i < n; i++)
    {
        files[i].input();
    }
    cout << "\nFile\tStart\tSize\tBlocks" << endl;
    for (auto f : files)
    {
        f.display();
    }
    return 0;
}