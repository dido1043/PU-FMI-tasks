#include <iostream>
#include <vector>
#include <algorithm>
#include<Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "�������� 'Stop', ������ ��� ������ ��������." << endl;
    cout << "�������� ������ ������ ���:" << endl;

    vector<string> tasks;

    string task = "";
    while (task != "Stop")
    {
        cin >> task;
        tasks.push_back(task);
    }
    cout << "������ ������:" << endl;
    for(string t : tasks)
    {
        cout << t << endl;
    }

}
