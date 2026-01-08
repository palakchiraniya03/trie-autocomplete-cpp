# Trie Based Autocomplete System using C++

This project is a simple implementation of an autocomplete system using the
Trie data structure in C++. The program suggests possible words based on the
prefix entered by the user.

## Features
- Stores words using a Trie
- Provides suggestions for a given prefix
- Fast and efficient prefix searching

## Technologies Used
- Programming Language: C++
- Data Structure: Trie

## Working Principle
All words are stored in a Trie structure. When the user enters a prefix, the
program traverses the Trie up to the last character of the prefix. From that
point, Depth First Search (DFS) is used to find and display all possible word
completions.

## How to Run the Program
```bash
g++ src/main.cpp -o autocomplete
./autocomplete
