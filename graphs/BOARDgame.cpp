// set has faster lookup time but no
// direct updation - delete whole entry and
// add new one
#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie();
    cin.tie();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen(" output.txt", "w", stdout);
#endif
}
#define M 3
#define N 4

class Node
{
public:
    char s;
    unordered_map<char, Node *> children;
    string word;
    bool isTerminal;

    Node(char c)
    {
        this->s = c;
        word = "";
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }
    void addWord(string word)
    {

        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
        temp->word = word;
    }
};

// main algorithm 8-way dfs + trie guided search
void dfs(char board[M][N], Node *node, int i, int j, bool visited[][N], unordered_set<string> &output)
{
    char ch = board[i][j];
    if (node->children.count(ch) == 0)
    {
        return;
    }

    visited[i][j] = true;
    node = node->children[ch];

    if (node->isTerminal)
    {
        output.insert(node->word);
    }
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    for (int k = 0; k < 8; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if (ni >= 0 and nj >= 0 and ni < M and nj < N and !visited[ni][nj])
        {
            dfs(board, node, ni, nj, visited, output);
        }
    }
    visited[i][j] = false;
    return;
}

int main()
{
    file_io();
    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "GO", "TUNES", "CAT"};
    char board[M][N] = {{'S', 'E', 'R', 'T'},
                        {'U', 'N', 'K', 'S'},
                        {'T', 'C', 'A', 'T'}};
    Trie t;
    for (auto w : words)
    {
        t.addWord(w);
    }
    unordered_set<string> output;

    // 8-dfs calls from each cell;
    bool visited[M][N] = {0};
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            dfs(board, t.root, i, j, visited, output);
            // reset the visited array after every call (while backtracking)
        }
    // print the output
    for (auto word : output)
    {
        cout << word << endl;
    }
    return 0;
}