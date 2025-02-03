#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

vector<int> decomposite(int n)
{
    if (n == 1)
        return { 2, L'³ª', 2 };
    if (n < 10)
        return { n };

    for (int i = 9; i > 1; --i)
    {
        if (n % i == 0)
        {
            vector<int> result = decomposite(n / i);
            result.push_back(L'µû');
            result.push_back(i);
            return result;
        }
    }

    int cand = -1, maxdiv = -1;
    for (int i = 2; i < 10; ++i)
    {
        for (int j = 2; j < 10; ++j)
        {
            if ((n - i) % j == 0 && j > maxdiv)
            {
                maxdiv = j;
                cand = i;
                break;
            }
        }
    }

    vector<int> result = decomposite(n - cand);
    result.push_back(L'´Ù');
    result.push_back(cand);
    return result;
}

wstring each(int n)
{
    wstring name[] = { L"", L"", L"¹Ú", L"¹Þ", L"¹ã", L"¹ß", L"“Q", L"¹à", L"“P", L"¹á" };
    vector<int> arr = decomposite(n);
    wstring result;

    for (int i = arr.size() - 1; i >= 0; i -= 2)
    {
        result += name[arr[i]];
    }
    for (size_t i = 1; i < arr.size(); i += 2)
    {
        result += (wchar_t)arr[i];
    }
    result += L"¸Ä";

    return result;
}

wstring aheui(const wstring& input)
{
    wstring ret;
    for (wchar_t c : input)
    {
        ret += each((int)c);
    }
    return ret + L"Èñ";
}

int main(void)
{
    wcin.imbue(locale(""));
    wcout.imbue(locale(""));

    wstring input;
    wcout << L"ÀÔ·Â: ";
    getline(wcin, input);
    wcout << L"º¯È¯ °á°ú: " << aheui(input);

    return 0;
}