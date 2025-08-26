# Stable Marriage Problem (Gale-Shapley algorithm)

## Overview
This C++ program implements the Gale-Shapley algorithm using object-oriented design and separate compilation. The goal is to find a stable matching between men and women based on their preferences.

## Compilation
Use a C++ compiler (e.g., g++):

```bash
g++ -std=c++20 main.cpp Person.cpp StableMarriage.cpp -o stable_marriage
./stable_marriage
```

## Input format (input.txt)
```
t
n
man1 preference1 preference2 ...
...
woman1 preference1 preference2 ...
...
```
t - test cases <br>
n - number of people (equal for each group)

## Test Cases(input.txt)
### Case 1:
Men: A, B, C, D, E  
Women: L, M, N, O, P

### Case 2:
Men: Alex, Bill, Callum, David  
Women: Emily, Fiona, Gemma, Harriet  

### Case 3:
Men: A, B, C  
Women: D, E, F  




## Algorithm
The Gale-Shapley algorithm ensures a stable matching by letting each man propose in order of his preference.
Each woman accepts or rejects proposals based on her own preferences.
The algorithm runs at worst in O(n^2) time.

## Output
Each man is shown with his final stable match.
