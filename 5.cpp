//
//  I'm perfectly aware that this code is much too long for a leetcode submission, however given enough spare time and the oppertunity, 
//  I just had to implement a palindromic tree
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

static const int ALPH_SIZE = 256;

struct node{
    char val;
    node* suffix_link;
    node* parent;
    node* children[ALPH_SIZE];
    int pal_length;
};

string word;

node* imaginary_root;
node* real_root;
node* current_node;

vector<node* > palindromes;

void fill_null(node* at){
    for(int i=0;i<ALPH_SIZE;++i){
        at->children[i] = NULL;
    }
    return;
}

string ans = "";

void print_palindrome(node* at){
    if(at == real_root || at == imaginary_root){
        return;
    }
    ans += at->val;
    print_palindrome(at->parent);
    if(at->parent != imaginary_root){
        ans += at->val;
    }
    return;
}

node* surf(int pos, node* at){
    while(1){
        if(pos - at->pal_length - 1 < 0){
            at = at->suffix_link;
            continue;
        }
        if(word[pos] != word[pos - at->pal_length - 1]){
            at = at->suffix_link;
            continue;
        }
        return at;
    }
    return NULL;
}

void insert(int pos){
    while(1){
        if(pos - current_node->pal_length - 1 < 0){
            current_node = current_node->suffix_link;
            continue;
        }
        if(word[pos] != word[pos - current_node->pal_length - 1]){
            current_node = current_node->suffix_link;
            continue;
        }
        if(current_node->children[word[pos]] == NULL){
            current_node->children[word[pos]] = new node;
            node* temp = current_node->children[word[pos]];
            temp->val = word[pos];
            temp->parent = current_node;
            node* temp2 = surf(pos, current_node->suffix_link);
            temp->pal_length = current_node->pal_length + 2;
            if(current_node == imaginary_root){
                temp->suffix_link = real_root;
            }else{
                temp->suffix_link = temp2->children[word[pos]];
            }
            fill_null(temp);
            current_node = temp;
        }else{
            current_node = current_node->children[word[pos]];
        }
        palindromes.push_back(current_node);
        break;
    }
    return;
}

string longestPalindrome(string s) {
    if(s == "")
        return "";
    imaginary_root = new node;
    imaginary_root->pal_length = -1;
    imaginary_root->suffix_link = imaginary_root;
    fill_null(imaginary_root);
    real_root = new node;
    real_root->pal_length = 0;
    real_root->suffix_link = imaginary_root;
    fill_null(real_root);
    current_node = imaginary_root;
    word = s;
    for(int i=0;i<word.size();++i){
        insert(i);
    }
    node* best = palindromes[0];
    for(node* at : palindromes){
        if(at->pal_length > best->pal_length){
            best = at;
        }
    }
    ans = "";
    print_palindrome(best);
    return ans;
}

int main(){
    string inp;
    cin >> inp;
    cout << longestPalindrome(inp) << endl;
}
