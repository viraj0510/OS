-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <iostream>
#include <vector>
                                                                                                                                                                     using namespace std;
int optimal(int n, int p, const vector<int> &input)
{
    vector<int> frame(n, -1);
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
            cout << "Page " << input[i] << " already in frame" << endl;
        }
        else
        {
            if (n > 0 && frame[0] == -1)
            {
                frame[0] = input[i];
                n--;
            }
            else
            {
                int farthest = 0;
                int maxDist = 0;
                for (int j = 0; j < n; j++)
                {
                    int dist = p;
                    for (int k = i + 1; k < p; k++)
                    {
                        if (frame[j] == input[k])
                        {
                            dist = k - i;
                            break;
                        }
                    }
                    if (dist > maxDist)
                    {
                        maxDist = dist;
                        farthest = j;
                    }
                }
                cout << "Page " << frame[farthest] << " replaced by ";
                frame[farthest] = input[i];
            }
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
    int faults = optimal(n, p, input);
    cout << "\nThe No. of Page Faults is: " << faults << endl;
    return 0;
}
