### Solution 1 priority queue

- t-complexity: $O(klogn)$
    n is length of arr
- s-complexity: $O(n)$

for every j as denominator, numerator arr[0] - arr[i] is increasing

initialize priority queue with value $arr[0] / arr[1], ..., arr[0] / arr[n-1]$

then proceed k steps, in every step, pop out smallest element, denoted as $arr[i] / arr[j]$, if i+1 < j, we push $arr[i+1] / arr[j]$ in queue.

after k pops, we get result

