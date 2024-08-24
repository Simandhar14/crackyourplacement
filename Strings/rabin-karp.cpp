#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RabinKarp
{
private:
    const int prime = 101; // A prime number

    long long createHash(const string &str, int end)
    {
        long long hash = 0;
        for (int i = 0; i <= end; i++)
        {
            hash += str[i] * pow(prime, i);
        }
        return hash;
    }

    long long recalculateHash(const string &str, int oldIndex, int newIndex, long long oldHash, int patternLength)
    {
        long long newHash = oldHash - str[oldIndex];
        newHash /= prime;
        newHash += str[newIndex] * pow(prime, patternLength - 1);
        return newHash;
    }

public:
    vector<int> search(const string &text, const string &pattern)
    {
        vector<int> result;
        int patternLength = pattern.length();
        int textLength = text.length();

        if (patternLength > textLength)
            return result;

        long long patternHash = createHash(pattern, patternLength - 1);
        long long textHash = createHash(text, patternLength - 1);

        for (int i = 0; i <= textLength - patternLength; i++)
        {
            if (patternHash == textHash)
            {
                if (text.substr(i, patternLength) == pattern)
                {
                    result.push_back(i);
                }
            }

            if (i < textLength - patternLength)
            {
                textHash = recalculateHash(text, i, i + patternLength, textHash, patternLength);
            }
        }

        return result;
    }
};

int main()
{
    RabinKarp rk;
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    vector<int> positions = rk.search(text, pattern);

    if (positions.empty())
    {
        cout << "Pattern not found in the text." << endl;
    }
    else
    {
        cout << "Pattern found at indices: ";
        for (int pos : positions)
        {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}