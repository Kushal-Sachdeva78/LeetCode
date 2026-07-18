# LeetCode Solutions

Solutions to 56 LeetCode problems in C++ and Python: problems 1 through 50 complete, plus a set of harder problems, all with LeetCode-compatible `Solution` signatures ready to submit.

![C++](https://img.shields.io/badge/C%2B%2B-49%20solutions-blue)
![Python](https://img.shields.io/badge/Python-12%20solutions-yellow)
![License](https://img.shields.io/badge/License-MIT-green)

## At a glance

| | |
| --- | --- |
| Problems solved | 56 (all of #1-50, plus #72, #85, #417, #778, #2300, #3494) |
| Difficulty | 10 Easy, 34 Medium, 12 Hard |
| Languages | C++ (49 files), Python (12 files), 5 problems in both |

## Organization

Each problem lives in its own folder named `<number>-<title>`, for example `1-two-sum` or `417-pacific-atlantic-water-flow`. Folder names follow LeetCode's internal question IDs, which for a few newer problems differ from the public problem numbers (for example, `794-swim-in-rising-water` is public problem #778). Every folder contains:

- The official problem statement with a difficulty badge (`README.md`)
- One or two solutions (`.cpp` and/or `.py`) that mirror LeetCode's `class Solution` interface, so they can be pasted straight into the platform

## Highlights

- **Sudoku Solver (#37, Hard)**: bitmask backtracking with per-row, per-column, and per-box 9-bit masks, `__builtin_popcount`/`__builtin_ctz` bit tricks, and a minimum-remaining-values heuristic that always fills the most constrained cell first.
- **Maximal Rectangle (#85, Hard)**: reduces the 2D matrix to per-row histograms and applies a monotonic-stack largest-rectangle routine, O(rows x cols) overall.
- **Swim in Rising Water (#778, Hard)**: Dijkstra-style search with a min-heap over `(time, row, col)` states.
- **Merge k Sorted Lists (#23, Hard)**: a `priority_queue` with a custom comparator and dummy-head list construction.
- **Edit Distance (#72, Medium)**: space-optimized dynamic programming with a single rolling 1D array.

## Techniques covered

Arrays and two pointers, strings, sliding window, linked lists, hash maps, stacks and monotonic stacks, heaps and priority queues, recursion and backtracking, dynamic programming (1D and 2D), binary search, BFS on grids, Dijkstra's algorithm, greedy algorithms, bit manipulation, and math.

## Style

- C++ solutions lean on the STL (`vector`, `unordered_map`, `set`, `priority_queue`) and are written for performance.
- Python solutions favor readability and idiomatic constructs.
- Signatures and class names match LeetCode exactly, so every file is submission-ready.

## Connect

- **LeetCode profile**: [leetcode.com/u/Kushal-Sachdeva](https://leetcode.com/u/Kushal-Sachdeva/)
- **More of my work**: [github.com/Kushal-Sachdeva78](https://github.com/Kushal-Sachdeva78), including [autonomous soccer robots](https://github.com/Kushal-Sachdeva78/VVS-Ballers-RoboCup) and a [post-quantum identity prototype](https://github.com/Kushal-Sachdeva78/PQ-Identity-Prototype)

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
