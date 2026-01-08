#include <iostream>
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
};

int main(){
  Trie trie;
  trie.insert("apple");
  trie.insert("app");
  cout<<"inserted some words in the trie"<<endl;
  return 0;
}
