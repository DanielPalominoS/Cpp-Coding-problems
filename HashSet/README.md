# Problem description

Suppose we have a simple hash table that consists of a vector of integers. We can preallocate the table to have a specific size and fill the values with -1 to begin with, to mark those elements empty. For simplicity, this table will actually be a hash set rather than a hash map; in other words, rather than mapping unique keys to values, we simply have a collection of unique keys, so it is not a dictionary ADT. Such a table merely answers the question of whether any given integer is part of the set (can be found) or is not part of the set (cannot be found).

In the code below, you need to implement the insert function:
```cpp
int insert(int value, std::vector<int> &table);
```

This insert function should first compute a specific hash function of value. This hash function should return the least-significant three decimal digits (a number from 0 to 999) of the variable value. This hash result should be used as an index into the thousand-element vector table that has been previously initialized with -1 in each element. If the element at this location of table is available (currently set to -1), you can replace the element with value. If this location is not available (currently set to some other value than -1) then you should check the next element, repeatedly, until you find an available element and can store value there. The insert() function should then return the number of times a location in the hash table was identified to store the given value but was not available.

Example: If your function is able to insert the value in the hash location on the first try, return 0. If your function has to check the next two locations before finding an empty space, return 2.

The main() procedure below will create an appropriate table, then create 500 random values and call insert() on each one of them to insert them into the table. At the end, this procedure will report the length of the longest cluster encountered when inserting a value (as reported by your insert() function) and then print out the contents of the hash table so you can see how clusters form. Since the original hashed position will be the three least significant digits of the value stored there, it will be easy to see which values had to be relocated by linear probing, and how much probing was needed.

When you submit your code, the length of the longest cluster encountered when inserting a value as reported by your insert() function will be compared to the result from the reference code for correctness.

(To pass the exercise, please make sure you implement exactly what we describe above. If your hashing function or collision prevention algorithms are different than asked, even if they are more advanced, the grader won't award points.)