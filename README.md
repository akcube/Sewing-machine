# Needleman-Wunsch Algorithm Optimization


## Team
- A Kishore Kumar
- Vidit Jain

## Description 

<img src="equation1.png" alt="Base Case" width="250"/>
<img src="equation2.png" alt="Recurrence Relation" width="300"/>



This project involves optimizing a dynamic programming algorithm that cannot be parallelized trivially.

In this project, we worked on reordering the way we process the recurrence relation by iterating over the diagonals instead of a row-wise or column-wise method, and stored only the diagonals needed for computing the future values to save space. Doing so allowed us to make the algorithm parallelizable by removing inter-dependencies. 

We also modified the way we stored these diagonals by storing them in a linear fashion instead of accessing the elements as a diagonal of a grid, making the array access much more **cache-efficient**. 

This optimizations provided a 100x speedup with no loss of accuracy, while only taking up `O(n)` space.
