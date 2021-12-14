#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
vector <int> visited;

int dfs(vector <vector<int>> &graph,int &v){
    int c=0;
    visited[v] = 1;
    int n = graph[v].size();
    for(auto i=0;i<n;i++){
        if(!visited[graph[v][i]]){
            c += dfs(graph,graph[v][i]);
        }
    }
    return c+1;
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    int m = astronaut.size();
    vector <vector<int>> graph(n);
    for(auto i=0;i<m;i++){
        graph[astronaut[i][0]].push_back(astronaut[i][1]);
        graph[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    visited.resize(n,0);
    vector <int> ans;
    for(auto i=0;i<n;i++){
        if(!visited[i]){
            ans.push_back(dfs(graph,i));
        }
    }
    int size = ans.size();
    int sum[size];
    sum[size-1] = ans[size-1];
    for(auto i=size-2;i>=0;i--){
        sum[i] = sum[i+1]+ans[i];
    }
    long long final_ans=0;
    for(auto i=0;i<size-1;i++){
        final_ans += ans[i]*sum[i+1];
    }
    cout << final_ans;
    return final_ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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
