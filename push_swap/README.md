*This project has been created as part of the 42 curriculum by nmariah and andriraz.*

# Push Swap - Sorting Algorithm Optimizer

## Description

Push Swap is an advanced sorting algorithm project that sorts a stack of integers using two stacks (A and B) with a limited set of operations. The program intelligently selects the most efficient sorting algorithm based on the disorder level (entropy) of the input data.

This project implements a comprehensive sorting solution that handles various scenarios with optimized strategies:
- **Small datasets**: Bubble sort variant for minimal operation count
- **Medium datasets**: Chunk-based sorting using square root partitioning
- **Large datasets**: Radix sort (binary representation)
- **Adaptive mode**: Automatically selects the optimal algorithm based on data disorder

## Instructions

### Compilation

```bash
make
```

This compiles the project and generates the `push_swap` executable.

### Basic Usage

```bash
./push_swap [numbers]
```

**Example:**
```bash
./push_swap 4 2 7 1 8
```

The program outputs a sequence of operations needed to sort stack A in ascending order.

### Available Flags

Use algorithm-specific flags to force a particular sorting strategy:

- `--simple`: Force simple sort algorithm (bubble sort variant)
- `--medium`: Force medium sort algorithm (chunk-based √n sorting)
- `--complex`: Force radix sort algorithm (binary radix sort)
- `--adaptive`: Let the program choose the best algorithm based on disorder
- `--bench`: Run benchmarking mode and display operation statistics

**Example with flags:**
```bash
./push_swap 4 2 7 1 8 --adaptive
./push_swap 4 2 7 1 8 --bench --complex
```

### Stack Operations

The following operations are used to manipulate the stacks:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element from stack B to stack A |
| `pb` | Push the top element from stack A to stack B |
| `ra` | Rotate stack A upwards (first element goes to end) |
| `rb` | Rotate stack B upwards |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element comes to top) |
| `rrb` | Reverse rotate stack B |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## Resources

### Useful site for the sorting algorithm

https://www.geeksforgeeks.org/dsa/radix-sort/
https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
https://www.geeksforgeeks.org/dsa/sorting-algorithms/
https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81

### How AI Was Used

This project leveraged AI assistance (GitHub Copilot) in multiple ways:

1. **Algorithm Implementation**: AI assisted in implementing the core sorting algorithms while maintaining efficiency and code clarity.

2. **Code Optimization**: AI suggestions helped optimize the radix sort implementation and chunk-based sorting logic for better operation counts.

3. **Debugging**: AI provided debugging assistance to identify and fix edge cases in parsing, stack operations, and memory management.

4. **Adaptive Logic**: AI helped develop the adaptive algorithm selection mechanism that evaluates disorder and chooses the optimal strategy.

5. **Utility Functions**: AI contributed to the development of helper functions like `ft_atol`, `ft_split`, `ft_sqrt`, and stack manipulation utilities.

6. **Printf Implementation**: The integrated `printf` module was developed with AI assistance for performance tracking and benchmarking.

### Project Files

- **Main files**:
  - `push_swap.c`: Main sorting dispatcher and flag handling
  - `main.c`: Entry point and stack initialization
  - `push_swap.h`: Header with all function declarations and data structures

- **Sorting algorithms**:
  - `algo_simple.c`: Simple bubble sort variant for small datasets
  - `algo_medium.c`: Medium chunk-based sort with √n complexity
  - `algo_complex.c`: Radix sort using binary representation
  - `adaptive.c`: Adaptive algorithm selector

- **Stack operations**:
  - `swap.c`, `rotate.c`, `reverse_rotate.c`, `push.c`: Core stack operations

- **Utilities**:
  - `parse.c`: Command-line argument parsing
  - `count_disorder.c`: Calculate input entropy/disorder
  - `ft_split.c`, `ft_atol.c`, `ft_sqrt.c`: Standard utility functions
  - `push_swap_utils.c`, `push_swap_util_02.c`: Additional helpers

- **Benchmarking**:
  - `bench.c`: Performance measurement and statistics

## The Algorithm

### Overview

The Push Swap program uses an **adaptive sorting strategy** that dynamically selects the best algorithm based on input disorder. Disorder is calculated as the ratio of non-matching consecutive elements to total possible pairs.

```
Disorder = (number of inversions) / (total possible pairs)
```

### Algorithm Selection Logic

The adaptive engine (`adaptive.c`) makes decisions based on disorder thresholds:

1. **Disorder < 0.2** → Use **Simple Sort** - O(n²)
   - Best for nearly-sorted or small datasets
   - Minimizes operation count for low entropy data

2. **Disorder 0.2 - 0.5** → Use **Medium Sort** - O(n√n)
   - Optimal for moderately disordered data
   - Uses chunk-based partitioning

3. **Disorder ≥ 0.5** → Use **Radix Sort** - O(n log n)
   - Best for highly randomized data
   - Sorts by bit representation

### Algorithm Details

#### Simple Sort (Bubble Variant)
- Finds the minimum element in the stack
- Rotates it to the top
- Repeats for each position
- Most efficient for data with < 20% disorder
- Example operation count for 100 elements (nearly sorted): ~200-300 operations

#### Medium Sort (Chunk-Based)
- Divides the dataset into chunks of size √n
- Pushes chunks from A to B while maintaining order
- Retrieves elements back in sorted order
- Efficient for moderate disorder
- Example operation count for 100 elements: ~800-1200 operations

#### Complex Sort (Radix Sort)
- Assigns rank indices to elements
- Performs bit-by-bit sorting (from least to most significant)
- Handles highly randomized data efficiently
- Consistent O(n log n) performance regardless of order
- Example operation count for 100 elements (random): ~1100-1500 operations

### Memory Model

```
Stack A (Input)          Stack B (Auxiliary)
┌─────────────┐          ┌─────────────┐
│   Element   │          │   Element   │
│   Element   │          │   Element   │
│   Element   │          │   Element   │
│   ...       │          │   ...       │
└─────────────┘          └─────────────┘
 (Top → Bottom)          (Top → Bottom)
```

Data structures used:
- **t_stack**: Stack container with size and pointers to top/bottom
- **t_list**: Doubly-linked list node for each element
- **t_bench**: Performance tracking structure

### Performance Characteristics

| Algorithm | Best Case | Average | Worst Case | Use Case |
|-----------|-----------|---------|-----------|----------|
| Simple | O(n) | O(n²) | O(n²) | Nearly sorted data |
| Medium | O(n√n) | O(n√n) | O(n√n) | Moderately disordered |
| Radix | O(n log n) | O(n log n) | O(n log n) | Random/highly disordered |

### Benchmarking

Use the `--bench` flag to see performance statistics:

```bash
./push_swap 100 200 50 1 75 300 --bench
```

Output includes:
- Total number of operations
- Breakdown of each operation type
- Selected algorithm strategy
- Disorder level percentage