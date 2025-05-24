https://codeforces.com/contest/380/problem/C
Feature	First Code (Pointers)	Second Code (Direct Objects)
Memory allocation	Heap (slow)	Stack (fast)
Extra overhead	Yes (new calls)	No extra overhead
Speed of access	Slower (pointers)	Faster (direct access)
Simplicity & Safety	Less safe (no delete)	Safer and simpler


First Code (Using info*, i.e., pointers):
You create objects using new, like this:

info* ans = new info(...);
This creates the object in heap memory, which is slower to access and manage.

Also, using new takes extra time compared to just creating an object normally.

Every time you call merge() or query(), you're creating new heap objects → this adds overhead.

Second Code (Using info directly, i.e., normal objects):
You create objects like this:

info ans = info(...);
This creates the object in stack memory, which is faster to access and automatically managed.

No need to allocate or deallocate memory manually.

No pointer dereferencing → operations are faster and simpler.
