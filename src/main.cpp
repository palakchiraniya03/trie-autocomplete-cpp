#include <iostream>
#include<vector>
using namespace std;

class TrieNode{
  public:
  TrieNode* children[26];
  bool isEnd;

  TrieNode(){
    isEnd=false;
    for(int i=0;i<26;i++){
      children[i]=NULL;
    }
  }
};

class Trie{
  public:
  TrieNode* root;

  Trie(){
    root=new TrieNode();
  }

  void insert(string word){
    TrieNode* curr=root;
    for(char c:word){
      int index=c-'a';

      if(curr->children[index]==NULL){
        curr->children[index]=new TrieNode();
      }
      curr=curr->children[index];
    }
    curr->isEnd=true;
  }

  void dfs(TrieNode* node,string prefix,vector<string>&a result){
    if (node->isEnd){
      result.push_back(prefix);
    }

    for(int i=0;i<26;i++){
        if (node->children[i]!= NULL){
          char nextChar=i + 'a';
          dfs(node->children[i], prefix + nextChar,result);
        }
    }
  }

  
  vector<string> autocomplete(string prefix){
    TrieNode* curr=root;
    vector<string> result;

    for (char c:prefix) {
        int index = c-'a';
        if (curr->children[index] == NULL)
            return result;
        curr = curr->children[index];
    }

    dfs(curr, prefix, result);
    return result;
  }
};

int main(){
  Trie trie;
  trie.insert("apple");
  trie.insert("app");
  trie.insert("application");
  trie.insert("banana");
  vector<string> words=trie.autocomplete("app");

  for(string w:words){
    cout<<w<<endl;
  }
  return 0;
}
