#include <bits/stdc++.h>

using namespace std;

void dispRunLengthEncoding(string input)
{
    int count = 0;
    char prev_ch = input[0];
    char next_ch;
    for(int i = 1; i < input.length(); i++)
    {
        ++count;
        next_ch = input[i];
        if(next_ch != prev_ch)
        {
            cout << count << prev_ch;
            count = 0;
            prev_ch = next_ch;
        }
    }
    cout << count + 1 << prev_ch;
}

int main()
{
    string input;
    cin >> input;
    dispRunLengthEncoding(input);
    return 0;
}
