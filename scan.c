#include <iostream>
#include <vector>
#include <list>
using namespace std;
int LRU(int n, int p, const vector<int> &input)
{
    vector<int> frame(n, -1);
    list<int> order;
    int fault = 0;
    cout << "\nPage Replacement Process:\n";
    for (int i = 0; i < p; i++)
    {
        bool found = false;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (frame[j] == input[i])
            {
                found = true;
                index = j;
                break;
            }
        }
        if (found)
        {
            order.remove(input[i]);
            order.push_front(input[i]);
            cout << "Page " << input[i] << " already in frame" << endl;
        }
        else
        {
            if (order.size() == n)
            {
                int lruPage = order.back();
                order.pop_back();
                for (int j = 0; j < n; j++)
                {
                    if (frame[j] == lruPage)
                    {
                        index = j;
                        break;
                    }
                }
                cout << "Page " << lruPage << " replaced by ";
            }
            else
            {
                index = order.size();
            }
            frame[index] = input[i];
            order.push_front(input[i]);
            fault++;
            cout << "Page " << input[i] << endl;
        }
        cout << "Current Frame: ";
        for (int page : frame)
        {
            if (page != -1)
            {
                cout << page << " ";
            }
        }
        cout << endl;
    }
    return fault;
}
int main()
{
    int n, p;
    cout << "Enter the size of the frame: ";
    cin >> n;
    cout << "Enter the No. of Input Pages: ";
    cin >> p;
    vector<int> input(p);
    cout << "Enter the Input Pages: ";
    for (int i = 0; i < p; i++)
    {
        cin >> input[i];
    }
    int faults = LRU(n, p, input);
    cout << "\nThe No. of Page Faults is: " << faults << endl;
    return 0;
}