#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// Union-Find set
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for ( int i = 0; i < n; ++i ) {
            parent[i] = i;
        }
    }

    // path compression
    int Find(int p) {
        if ( parent[p] != p ) {
            parent[p] = Find(parent[p]);
        }
        return parent[p];
    }

    // union by rank
    void Union(int p, int q) {
        int proot = Find(p), qroot = Find(q);
        if ( proot == qroot ) {
            return;
        }
        if ( proot < qroot ) {
            parent[proot] = qroot;
        } else if ( qroot < proot ) {
            parent[qroot] = proot;
        } else {
            parent[proot] = qroot;
            ++rank[qroot];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // mail count
        int mail_val = 0;
        // mail to id
        unordered_map<string, int> mail_id;
        // mail to name
        unordered_map<string, string> mail_name;
        for ( const auto& account : accounts ) {
            string name = account[0];
            int len = account.size();
            for ( int i = 1; i < len; ++i ) {
                if ( mail_id.find(account[i]) == mail_id.end() ) {
                    mail_id[account[i]] = mail_val++;
                    mail_name[account[i]] = name;
                }
            }
        }
        // mail count: mail_val
        UnionFind union_find(mail_val);
        for ( const auto& account : accounts ) {
            int len = account.size();
            if ( len < 3 ) continue;
            string first_mail = account[1];
            int    first_mail_id = mail_id[first_mail];
            for ( int i = 2; i < len; ++i ) {
                union_find.Union(first_mail_id, mail_id[account[i]]);
            }
        }
        // id to mails with the same root
        unordered_map<int, vector<string>> id_mails;
        for ( const auto& p : mail_id ) {
            string mail = p.first;
            int    root = union_find.Find(p.second);
            if ( id_mails.find(root) == id_mails.end() ) {
                id_mails[root] = vector<string>();
            }
            id_mails[root].emplace_back(mail);
        }
        // merger
        vector<vector<string>> megered;
        for ( const auto& p : id_mails ) {
            int root = p.first;
            vector<string> mails = p.second;
            sort(mails.begin(), mails.end());
            string name = mail_name[mails[0]];
            vector<string> account;
            account.emplace_back(name);
            for ( const auto& mail : mails ) {
                account.emplace_back(mail);
            }
            megered.emplace_back(account);
        }
        return megered;
    }
};
