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

Our proposed test 1 will search for specific phrases or sentiments within the "Review" column. We'll generate table values for sample patterns, such as "Loved" or "not good".
We'll validate the consistency of these tables, ensuring that they align with the known, expected values for said patterns.

Our proposed test 2 will identify patterns correlating with the "Liked" column values (1 for positive sentiment, 0 for negative). For example, we'll validate if reviews containing "Loved" predominantly have a "Liked" value of 1. 

Our proposed test 3 will use varied patterns to preprocess tables so we can validate if the generated tables are consistent in terms of the positions being shifted correctly. We can use example patterns like "tasty” and "recommendation".

For our methods, we will write additional tests as we continue the development process.

## Data Description

Our selected dataset, "Restaurant Reviews", is sourced from Kaggle. Stored in the /data directory, this dataset provides data regarding restaurant reviews. The data is formatted with each row representing an individual written review of the restaurant and whether they liked the food or not, determined by a 1 or a 0. The dataset is structured as a table with numerical values and string reviews. It is downloadable as a TSV, so it is already a tab separated dataset of values. 
