*This project has been created as part of the 42 curriculum by nmariah and andriraz.*

# Push_swap

## Description

**push_swap** is a 42 School project that challenges you to sort a stack of integers using a limited set of operations, with the goal of using as **few moves as possible**.

The program receives a list of integers as arguments, stores them in a stack called `a`, and must output the sequence of instructions that sorts them in ascending order — with the smallest element at the top. A second empty stack `b` is available as a buffer.

### Available operations

| Operation | Effect |
|-----------|--------|
| `sa` | Swap the top two elements of stack `a` |
| `sb` | Swap the top two elements of stack `b` |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top element of `b` onto `a` |
| `pb` | Push the top element of `a` onto `b` |
| `ra` | Rotate `a` upward (top → bottom) |
| `rb` | Rotate `b` upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate `a` (bottom → top) |
| `rrb` | Reverse rotate `b` |
| `rrr` | `rra` and `rrb` simultaneously |

### Strategy overview

The sorting strategy is adapted to the input size:

- **n ≤ 3** — hardcoded case matching for all 6 permutations, solved in at most 2 moves.
- **n ≤ 5** — push 1 or 2 elements to `b`, sort the 3 remaining in `a`, then reinsert from `b` in the correct order.
- **n ≤ 100 / 500** — a chunk-based algorithm that partitions values into ranges, pushes them to `b` in order, and reinserts them with optimised rotations.

An optional `--simple` flag can be passed anywhere in the arguments to display a visual representation of the stacks at each step.

---

## Instructions

### Requirements

- A C compiler (`cc` or `gcc`)
- GNU `make`
- A Unix-like environment (Linux or macOS)

### Compilation

```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-6c8eed4c-5628-4674-8583-3f781a1b06a3-7336221-andriraz push_swap
cd push_swap
make
```

This produces two executables:

- `push_swap` — outputs the list of operations to sort the stack
- `checker` — reads operations from stdin and verifies whether they correctly sort the stack

To remove compiled objects:

```bash
make clean   # removes .o files
make fclean  # removes .o files and executables
make re      # fclean + make
```

### Execution

```bash
# Basic usage
./push_swap 5 3 1 4 2

# With a quoted string
./push_swap "5 3 1 4 2"

# Mixed arguments (flag can appear anywhere)
./push_swap 5 3 --simple 1 4 2
./push_swap --simple "5 3 1 4 2"

# Count the number of operations
./push_swap 5 3 1 4 2 | wc -l

# Verify correctness using checker
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2
```

### Error handling

The program prints `Error` to stderr and exits if:

- A non-integer argument is provided
- An integer is out of `INT` range
- Duplicate values are detected

---

## Resources

### Documentation & references

- [Sorting networks — Knuth, *The Art of Computer Programming*, Vol. 3](https://www-cs-faculty.stanford.edu/~knuth/taocp.html) — foundational reference for optimal small-array sorting
- [Wikipedia — Sorting network](https://en.wikipedia.org/wiki/Sorting_network) — visual overview of optimal comparator networks for n ≤ 5
- [Wikipedia — Selection sort / Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) — conceptual basis for the chunk reintegration phase
- [push_swap visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer) — graphical tool to observe and debug your instruction sequence step by step
- [42 push_swap checker (Linux)](https://github.com/42School/push_swap_checker) — reference checker binary for validating output
- https://www.giacomazzi.fr/infor/Tri/TRadix.html
- https://www.geeksforgeeks.org/dsa/radix-sort/


### Use of AI (Claude — Anthropic)

AI assistance was used at several stages of this project, always as a thinking partner rather than a code generator:

**Conceptual understanding**
- Clarifying the logic of optimal sorting networks for n ≤ 5 (minimum comparator sequences, parallelism within steps)
- Understanding why rank-based indexing is preferable to working with raw values, and how to assign ranks in O(n²)

**Code review & debugging**
- Reviewing the `assign_ranks` function for correctness and potential issues (uninitialized variables, field placement in structs)
- Identifying bugs in the argument-parsing logic (`ft_take_arg`): uninitialized `count`, `j` not reset between arguments, memory leaks on non-matching paths, wrong type for the `flag` parameter
- Suggesting a cleaner two-pass approach for flag detection that works regardless of flag position in `argv`

**Architecture decisions**
- Discussing where to store `index` (in `t_list` per element, not in `t_stack`) and confirming that `->value` is not mutated by the rank assignment

# The algorithm
clear