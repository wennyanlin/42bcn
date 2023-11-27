#include "push_swap.h"

/*
We want to push elements from A to B whilst
maintaining B sorted from highest to lowest.
Once all elements are in B, we push them back to A (pa until B is empty)
The result will be all elements sorted from smallest to biggest in A.

When head A is bigger than head B
    We can compare the top two elements of A and B.
    If head of A is > head B then
        head of A should be pushed on top of B (pb)

When head A is smaller than Min B
    We can also keep track of the smallest element in B, Min B
    If head of A is < last B then
        head of A should be at the bottom of B (pb & rb)
        and we update the Min B value to be the new Min

What if it isn't the smallest or biggest? i.e. what if it is in the middle?

When head A is in the middle
    When the top of A is in the middle, we need to find its spot in B and push it
    We can find the spot with the following:
    1. compare head of A to head of B
    2. if head A > head B then push to B and go to 4.
    3. else repeat from 1.
    4. undo all the rotations from the steps above

    for example:
    1. is 6 > 9? No, rotate B
    2. is 6 > 7? No, rotate B
    3. is 6 > 3? Yes, push B
    4. undo all rotations (there were 2 rotations)
    
    Total, it took 5 operations (2 rb, 1 pb, 2 rrb)

        1           2           3         4          5
        rb          rb         pb         rrb        rrb
    A  B   ->   A  B   ->   A  B  ->   A  B  ->   A  B  ->   A  B 
    ----   ->   ----   ->   ----  ->   ----  ->   ----  ->   ---- 
    6  9   ->   6  7   ->   6  3  ->   2  6  ->   2  7  ->   2  9 
    2  7   ->   2  3   ->   2  2  ->   3  3  ->   3  6  ->   3  7 
    3  3   ->   3  2   ->   3  9  ->      2  ->      3  ->      6 
       2   ->      9   ->      7  ->      9  ->      2  ->      4 
                                          7          9          3


*/