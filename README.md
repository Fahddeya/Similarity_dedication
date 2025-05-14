# Similarity Detecting Program

This C++ program simulates string sets and calculates the similarity between them. It allows users to load data from files or direct string input, perform various set operations, and view the results.

## Features

- **Data Loading:**
  - Load sets from text files.
  - Load sets from direct string input.
  - Load one set from a file and the other from string input.
- **Set Operations:**
  - Add words to a set.
  - Remove words from a set.
  - Clear all words from a set.
- **Calculations & Display:**
  - Display the contents of each set.
  - Calculate and display the union of the two sets.
  - Calculate and display the intersection of the two sets.
  - Calculate and display the similarity score between the two sets.
- **Text Processing:**
  - Removes punctuation from words.
  - Converts words to lowercase for case-insensitive comparison.

## How to Compile and Run

### Prerequisites

- A C++ compiler that supports C++11 or later (e.g., g++).

### Compilation

The program uses the `<bits/stdc++.h>` header, which is a non-standard GCC extension.

**Option 1: Using GCC (or a compatible compiler)**

If you are using GCC, you can compile the program directly:

```bash
g++ A2_S7-8_20230287_Sheetpb2.cpp -o similarity_detector -std=c++11
```

**Option 2: Using Standard Headers (for other compilers)**

If your compiler does not support `<bits/stdc++.h>`, you will need to replace it with the equivalent standard C++ headers in `A2_S7-8_20230287_Sheetpb2.cpp`. The necessary headers would typically include:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cmath>
// Potentially others depending on specific standard library features used indirectly.
```

After modifying the includes, compile as usual:

```bash
g++ A2_S7-8_20230287_Sheetpb2.cpp -o similarity_detector -std=c++11
# Or for other compilers, e.g., Clang:
# clang++ A2_S7-8_20230287_Sheetpb2.cpp -o similarity_detector -std=c++11
```

### Running the Program

Once compiled, you can run the executable:

```bash
./similarity_detector
```

On Windows, you might run it as:

```bash
.\similarity_detector.exe
```

The program will then present a menu with options to guide you.

## Program Workflow

1.  **Main Menu:**

    - **A) Load two files:** Prompts for two file names to create the sets.
    - **B) Adding two strings:** Prompts for two strings to create the sets.
    - **C) Add file and a string:** Prompts for one file name and one string.
    - **D) Exit:** Terminates the program.

2.  **After Loading Data (Sub-menu):**
    - **A) Edit first set:**
      - Add a word.
      - Remove a word.
      - Clear the set.
      - Return to the previous menu.
    - **B) Edit second set:** (Same options as for the first set)
    - **C) Display all data:** Shows words in set 1, words in set 2, intersection, union, and the similarity score.
    - **D) Return:** Goes back to the main menu.

## Input Processing

- When loading from files, the program reads words separated by whitespace.
- Each word is "cleaned" by removing punctuation and converting it to lowercase.
- Duplicate words within the same input source are ignored (sets store unique elements).

## Author

Fahd Deya El-din Salah El-din Ahmed

## Date

15 Nov 2024
