#include <iostream>
#include <vector>
#include <algorithm>
#include<Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Напишете 'Stop', когато сте въвели задачите." << endl;
    cout << "Напишете вашите задачи тук:" << endl;

    vector<string> tasks;

    string task = "";
    while (task != "Stop")
    {
        cin >> task;
        tasks.push_back(task);
    }
    cout << "Вашите задачи:" << endl;
    for(string t : tasks)
    {
        cout << t << endl;
    }

}
