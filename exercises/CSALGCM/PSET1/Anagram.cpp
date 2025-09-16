#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    int n = s.length();
    // check if string is even
    if (n%2 == 0) {
        string s1, s2;
        for (int i = 0; i < n/2; i++) 
            s1 += s[i];
        for (int i = (n/2); i < n; i++) 
            s2 += s[i];
        
        cout << s2 << '\n';
        
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                if (s1[i] == s2[j]) {
                    s2.erase(j,1);
                    break;
                }
            }
        }
        return s2.length();
    } else 
       return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

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