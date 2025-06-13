#include <iostream>
using namespace std;

#define akitama return 0
#define ll long long int

#ifdef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( int X, List L );
void Delete( int X, List L );
Position FindPrevious( ElementType X, List L );
void Insert ( ElementType X, List L, Position P );
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );

#endif // _List_H

/* Place int the implementation file */

struct Node {
    ElementType Element;
    Position Next;
}