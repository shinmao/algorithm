## Segment tree
| Problem        | Source           | Writeup  |
| ------------- |:-------------:| -----:|
| Range Sum Query and update        | [struct implementation](RSQ-with-Node.cpp)      | This solution is ezier to understand, but use more memory than integer type |
|         | [array implementation](RSQ-with-Arr.cpp)      |  use the feature of index relationship between parent(x) and childs(`2*x` and `2*x+1`) |

> I get several times of wrong answer on codefordce, and finally find that the value of node might cause to integer overflow. Therefore I change int to long long...