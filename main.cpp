#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(vector<int> candles) {
    int maxHeight = 0;
    int tallestCount = 0;

    //Count each number in the array
    for (int i = 0; i < candles.size(); i++) {
        int currentHeight = 0;
        currentHeight = candles[i];
        //Flag the tallest height
        if (currentHeight > maxHeight) {
            maxHeight = currentHeight;
            tallestCount = 1;
        }
        else if (currentHeight == maxHeight) {
            tallestCount++;
        }
    }

    //return the number of tallest candles
    return tallestCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string candles_count_temp;
    getline(cin, candles_count_temp);

    int candles_count = stoi(ltrim(rtrim(candles_count_temp)));

    string candles_temp_temp;
    getline(cin, candles_temp_temp);

    vector<string> candles_temp = split(rtrim(candles_temp_temp));

    if (candles_count >= 1 && candles_count <= 1e5) {
        vector<int> candles(candles_count);

        for (int i = 0; i < candles_count; i++) {
            int candles_item = stoi(candles_temp[i]);

            if (candles_item >= 1 && candles_item <= 1e7) {
                candles[i] = candles_item;
            }
        }

        int result = birthdayCakeCandles(candles);

        fout << result << "\n";

        fout.close();
    }


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
