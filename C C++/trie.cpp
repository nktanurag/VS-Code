// TRIE IMPLEMENTATION USING POINTER//
class Solution {
public:
    struct TrieNode
    {
        struct TrieNode* children[26];
        bool isEndWord;
    };
    TrieNode* GetNewNode()
    {
        TrieNode* newNode=new TrieNode();
        newNode->isEndWord=false;
        for(int i=0;i<26;i++)
            newNode->children[i]=NULL;
        return newNode;
    }
    void Insert(TrieNode* root,string word)
    {
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(!curr->children[word[i]-'a'])
                curr->children[word[i]-'a']=GetNewNode();
            curr=curr->children[word[i]-'a'];
        }
        curr->isEndWord=true;
    }
    bool Search(TrieNode* root,string word)
    {
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(!curr->children[word[i]-'a'])
               return false;
            curr=curr->children[word[i]-'a'];
        }
        return(curr!=NULL && curr->isEndWord);
    }
    bool isEmpty(TrieNode* root)
    {
        for(int i=0;i<children_size;i++)
        {
            if(root->children[i])
               return false;
        }
        return true;
    }
    TrieNode* delete(TrieNode* root,string word,int depth=0)
    {
        if(!root)return NULL;
        if(depth==word.length())
        {
            if(root->isEndWord)
                root->isEndWord=false;
            if(isEmpty(root))
            {
                delete(root);
                root=NULL;
            }

        }
        int index=word[depth]-'a';
        root->children[index]=delete(root->children[index],word,depth+1);
        if(isEmpty(root))
        {struct
            delete(root);
            root=NULL;
        }
        return NULL;
    }
    int main()
    {
        struct TrieNode* root=GetNewNode();

    }
    
};
// TRIE IMPLEMENTATION USING POINTER END//






// pre,post & level order n-ary traversal
class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root)return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;i++)  //size (not q.size() as it will be changing always)
            {
                temp.push_back(q.front()->val);
                for(int j=0;j<q.front()->children.size();j++)
                {
                    q.push(q.front()->children[j]);
                }
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};



class Solution {
public:
    vector<int>ans;
    void PostOrder(Node* root)
    {
        if(root)
        {
            for(int i=0;i<root->children.size();i++)
            {
                PostOrder (root->children[i]);
            }
            ans.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) 
    {
        PostOrder(root);
        return ans;
    }
};


class Solution {
public:
    vector<int>ans;
    void PreOrder(Node* root)
    {
        if(root)
        {
            ans.push_back(root->val);
            for(int i=0;i<root->children.size();i++)
            {
                PreOrder (root->children[i]);
            }
        }
    }
    vector<int> preorder(Node* root) 
    {
        PreOrder(root);
        return ans;
    }
};
//trie implementation using array//
int trie[1000005][27];
bool stop[1000005][27];

int ct=0;

void Insert(string &s)
{
    int node=0;
    for(int i=0;i<s.length;i++)
    {
        if(!trie[node][s[i]-'a'])
           trie[node][s[i]-'a']= ++ct;
        node=trie[node][s[i]-'a'];
    }
    stop[node][s[s.length()-1]-'a']=1;
}

bool Search(string word)
{
    int node=0;
    for(int i=0;i<word.length();i++)
    {
        if(!trie[node][word[i]-'a'])
          return false;
        node=trie[node][word[i]-'a'];
    }
    return (node!=0 && stop[node][word[word.length()-1]-'a']==1);
}
bool isEmpty(TrieNode* root)
{
    int node=0;
    for(int i=0;i<26;i++)
    {
        if(trie[node][i])
            return false;
    }
    return true;
}



//trie implementation end//





