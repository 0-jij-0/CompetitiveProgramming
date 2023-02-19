# Basic Techniques

Here you will find techniques that do not fall under any specific category, but which are nonetheless really important and helpful in a wide range of problems.

<br></br>
## Binary Search

Binary search, or the idea of bisection in general, is maybe the most important algorithm in computer science. You can find a comprehensive and high-quality Binary Search Tutorial on [Codeforces EDU](https://codeforces.com/edu/course/2). I highly encourage you to watch all videos and solve all problems in this tutorial.

Here are some additional practice problems.

| Easy                                           | Medium                                        | Hard                                          |
|:----------------------------------------------:|:---------------------------------------------:|:---------------------------------------------:|
| https://codeforces.com/contest/371/problem/C   | https://codeforces.com/contest/1119/problem/B | https://codeforces.com/contest/817/problem/C  |
| https://codeforces.com/contest/1118/problem/D2 | https://codeforces.com/contest/1169/problem/C | https://codeforces.com/contest/1251/problem/D |
| https://codeforces.com/contest/1490/problem/C	 | https://codeforces.com/contest/1610/problem/C | https://codeforces.com/contest/1701/problem/C |

<br></br>
## Difference Array

By the end of Level 0, you should have learned how to find prefix sums and suffix sums using STL functions. [Here](https://codeforces.com/blog/entry/78762) is a blog describing what a difference array is and what type of problems can it solve. More generally, I would like to point out that it is most useful when we are asked to increment ranges in an array and we only care about the array AFTER all queries have been processed. The blog and comments include some practice problems related to this technique, and here are few more:

| Easy                                              |
|:-------------------------------------------------:|
| https://atcoder.jp/contests/abc183/tasks/abc183_d |
| https://codeforces.com/contest/276/problem/C      |
| https://codeforces.com/contest/296/problem/C	    |
| https://codeforces.com/contest/629/problem/B      |
| https://codeforces.com/contest/816/problem/B      |

Finally, here's a [famous interview question](https://leetcode.com/problems/merge-intervals/) that can be solved using that technique and few other smart tricks.

<br></br>
## Simulation Algorithms

Simulation problems are often asked to assess your competence with your programming language of choice, and hence practicing such problems is a great way of improving in that area. No specific algorithm is needed, you're just given a process and are asked to determine some state at the end of that process. You'll find some practice problems in the [USACO Simulation Section](https://usaco.guide/bronze/simulation?lang=cpp), and by participating in contests regularly you'll get exposed to more and more such problems since they are somewhat frequent.

<br></br>
## Sliding Window Techniques

A more general technique is Two Pointers which is presented below, but what we mean here are problems where you're given an array of size $N$ and an integer $K \leq N$, and you have to report some information about all subarrays of the array of size $K$. These problems are very common and the pattern can be used to speed up other algorithms. Famous such problems are:
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) (You should aim for a solution in $O(N)$ and reason about how to solve the Minimum variant)
- [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/) (You should aim for a solution in $O(N\log K)$)

Finally, here is an [additional practice problem](https://cses.fi/problemset/task/1077/).


<br></br>
## Sorting Algorithms

Although every programming language has its own sorting function, the ideas behind sorting algorithms can be very useful and sometimes need to be implemented from scratch.

There are two concepts of interest when talking about sorting algorithms. The first one is the concept of <b/>in-place sorting</b>, which are sorting algorithms that operate of the array itself, instead of using additional memory. The second one is the concept of <b/>stability</b>. A sorting algorithm is called stable if elements deemed equal preserve their relative order. This means if I'm sorting the list $\{34, 12, 1, 1024, 239\}$ based on the number of digits, $\{1, 34, 12, 239, 1024\}$ is called a stable sorting whereas $\{1, 12, 34, 239, 1024\}$ is not, because $34$ and $12$ have equal number of digits but did not preserve their relative order.

Here's a list of interesting sorting algorithms:

| $O(N^2)$                                       | $O(N\log N)$                                  | Others                                        |
|:----------------------------------------------:|:---------------------------------------------:|:---------------------------------------------:|
| [Bubble Sort](https://www.youtube.com/watch?v=xli_FI7CuzA)    | [Merge Sort](https://www.youtube.com/watch?v=4VqmGXwpLqc) | [Counting Sort](https://www.youtube.com/watch?v=OKd534EWcdk) |
| [Selection Sort](https://www.youtube.com/watch?v=g-PGLbMth_g) | [Quick Sort](https://www.youtube.com/watch?v=Hoixgm4-P4M) | [Radix Sort](https://www.youtube.com/watch?v=XiuSW_mEn7g) |
| [Insertion Sort](https://www.youtube.com/watch?v=JU767SDMDvA) | [Heap Sort](https://www.youtube.com/watch?v=2DmK_H7IdTo) | [Bucket Sort]() |

I encourage you to think for each one of those algorithms, if they are in-place/stable or not, and what would it take to make them in-place/stable, if possible. Some interesting readings about that are:
- [Stable Quick Sort](https://iq.opengenus.org/3-way-partitioning-quick-sort/)
- [Stable Counting Sort](https://medium.com/javarevisited/counting-sort-algorithm-implementation-in-java-an-analysis-of-stability-parallelizability-and-48ac7e43bcf1)
- Merge [Sorted Arrays](https://leetcode.com/problems/merge-sorted-array/) vs [Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) and the implication on the in-place property of Merge Sort.

Finally, here is a very nice reading: [Comparison-Based Lower Bounds for Sorting](https://www.cs.cmu.edu/~avrim/451f11/lectures/lect0913.pdf)

<br></br>
## Two Pointers

Two Pointers method generalizes the idea of sliding window, it's a method for maintaining some information across a segment of the array moving in one direction, although this segment may increase or decrease in size. You can find a comprehensive and high-quality Two Pointers Tutorial on [Codeforces EDU](https://codeforces.com/edu/course/2). I highly encourage you to watch all videos and solve all problems in this tutorial.
