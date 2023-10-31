## Academic Reference

The algorithm we are proposing to implement is Boyer and Moore's exact string matching algorithm.

We will use this provided website for our main in depth understanding of the algorithm: https://dl.acm.org/doi/10.1145/359842.359859

To help us understand the paper, we are using the Wikipedia explanation for the logic and pseudocode of the algoprithm: https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string-search_algorithm

## Algorithm Summary

The Boyer-Moore algorithm is an efficient string searching (or substring searching) algorithm that skips sections of the text, leading to a reduced number of average operations needed to be performed on the string. The algorithm uses preprocessing tables based on the pattern it seeks to find and applies the positional shifts that allow us to have efficient string searching. 

## Function I/O

There are two main preprocessing tables (bad character heuristic and good suffix heuristic) and a search function to consider:

1. `void preprocess_bad_character(std::string pattern, int badChar[NO_OF_CHARS])`
```
@param pattern -- The pattern string for which the table is being prepared
@param badChar -- An array to store the bad character heuristic
```

This function will preprocess the "bad character" heuristic, which is used to determine how many positions we should jump when we come across a mismatch between the pattern and given text.

2. `void preprocess_good_suffix(std::string pattern, int* goodSuffix)`
```
@param pattern -- The pattern string for which the table is being prepared
@param goodSuffix -- An array to store the good suffix heuristic
```
This function will preprocess the "good suffix" heuristic, which determines how many positions to jump based on the substring match being found.

3. `std::vector<unsigned> BoyerMoore(std::string text, std::string pattern)`

```
@param text -- The main text where the pattern needs to be searched
@param pattern -- The pattern string being searched for in the text
@return A vector of unsigned integers indicating the starting indices where pattern is found in text
```
This function will take the text and the pattern being searched for as parameters and use the preprocessing tables to search for the pattern in the text using the algorithm.

Our proposed Test 1 will search for specific DNA sequences within the "DNA_dataset_5.txt" dataset. We'll examine sequences for specific patterns, such as "CAGTC" which is located at the start of the dataset. We'll validate the consistency of the search results, ensuring that they align with the known, expected positions for said patterns.

Our proposed Test 2 will look for specific subsequences within the larger sequences of the "DNA_dataset_50.txt" dataset. For instance, we'll validate if sequences containing the pattern "GTCTAA" are accurately identified by the algorithm, given that this subsequence is a part of one of the DNA sequences in the dataset.

Our proposed Test 3 will search for distinct DNA sequences in the more extensive "DNA_dataset_500.txt" dataset. We will validate if the algorithm can consistently detect the pattern "GCGCTCATGT" within the dataset.

For our methods, we will write additional tests to ensure the accuracy and efficiency of the search algorithm, especially as we scale to larger datasets or introduce variations in the patterns we are searching for.


## Data Description

Our selected datasets were manually generated using a python script, that randomly created DNA sequences using ACTG combinations. Stored in the /data directory, this data is formatted with each row representing an individual DNA sequence. The dataset is structured as a text file with string sequences. It is downloadable as a .txt so we can utilize the data efficiently. We manually generated our datasets using the python code shown below.

```
import random

def sequences(length=10):
    return ''.join(random.choice('ACGT') for _ in range(length))

def dataset(num, slength=10):
    return [sequences(slength) for _ in range(num)]

dssize = [5, 50, 500, 5000, 50000]
slength = 10

for s in dssize:
    ds = dataset(s, slength)
    with open(f"DNA_dataset_{s}.txt", "w") as file:
        for seq in ds:
            file.write(seq + "\n")
```
