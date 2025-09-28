#include "reclists.hpp"
#include "solutions.hpp"

/*
 * Project 2
 *
 * Purpose:
 *
 * Implement classic recursive-list operations using only the provided
 * ADT primitives (null, is_null, is_atom, eq, car, cdr, cons) and recursion
 *
 */

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp.
//


int numNodesAtTheTopLevel(list p) {
    // p is one of
    //    a null list
    //    an atom
    //    a recursive list

    // The function returns the number of nodes at the top-level
    // of p.

    if( is_null(p) )
        return 0;
    if( is_atom(p) )
        return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}

////

//------------------------------------------------------------------------------
// Name: append
// Purpose: Append q to the end of list p (top-level only)
// Preconditions: p and q are lists (possibly empty), not atoms
// Postconditions: Returns a new list with all elements of p followed by q
//------------------------------------------------------------------------------
list append(list p, list q) {

    if (is_null(p))
        return q;

    return cons(car(p), append(cdr(p), q));
}

//------------------------------------------------------------------------------
// Name: reverseTopLevel
// Purpose: Reverse the top-level elements of p (does not recurse into sublists)
// Preconditions: p is a list (possibly empty), not an atom
// Postconditions: Returns a list with p's top-level elements in reverse order
//------------------------------------------------------------------------------
list reverseTopLevel(list p) {

    if (is_null(p))
        return p;

    return append(cons(car(p), null()), reverseTopLevel(cdr(p)));
}

//------------------------------------------------------------------------------
// Name: is_lat
// Purpose: Return true if p contains only atoms at the top level
// Preconditions: p is a list (possibly empty), not an atom
// Postconditions: Returns true iff every top-level element of p is an atom
//------------------------------------------------------------------------------
bool is_lat(list p) {

    if (is_null(p))
        return true;

    return is_atom(car(p)) && is_lat(cdr(p));
}

//------------------------------------------------------------------------------
// Name: member
// Purpose: Return true if atom p appears anywhere in q (any depth)
// Preconditions: p is intended to be an atom; q is a (possibly nested) list
// Postconditions: Returns true iff p occurs in q
//------------------------------------------------------------------------------
bool member(list p, list q) {

    if (is_null(q))
        return false;

    list h = car(q);

    if (is_atom(h)) {

        if ( eq(p, h))
            return true;

        return member(p, cdr(q));
    }

    return member(p, h) || member(p, cdr(q));
}

//------------------------------------------------------------------------------
// Name: last
// Purpose: Return the last top-level element of a non-empty list p
// Preconditions: p is a non-empty list (not an atom)
// Postconditions: Returns the last element at the top level of p
//------------------------------------------------------------------------------
list last(list p) {

    if (is_null(cdr(p)))
        return car(p);

    return last(cdr(p));
}

//------------------------------------------------------------------------------
// Name: list_pair
// Purpose: Pair corresponding atoms of two lists of equal length
// Preconditions: p and q are flat lists of atoms and have the same length
// Postconditions: Returns ((p1 q1) (p2 q2) ...). If either is empty, returns ()
//------------------------------------------------------------------------------
list list_pair(list p, list q) {

    if (is_null(p) || is_null(q))
        return null();

    return cons(cons(car(p), cons(car(q), null())), list_pair(cdr(p), cdr(q)));
//    return cons(cons(car(p), car(q)), list_pair(cdr(p), cdr(q)));
}

//------------------------------------------------------------------------------
// Name: firsts
// Purpose: Return a list of the first element from each sublist in p
// Preconditions: p is a list whose elements are lists of atoms (may include ())
// Postconditions: Returns (car(p1) car(p2) ...). Empty sublists are skipped
//------------------------------------------------------------------------------
list firsts(list p) {

    if (is_null(p))
        return null();

    if(is_null(car(p))) {
        return firsts(cdr(p));
    }

    if (is_atom(car(p))) {
        return null();
    }

    return cons(car(car(p)), firsts(cdr(p)));
}

//------------------------------------------------------------------------------
// Name: flat
// Purpose: Flatten p by removing all internal parentheses (preserve order)
// Preconditions: p is a list (possibly nested)
// Postconditions: Returns a flat list of atoms in left-to-right order
//------------------------------------------------------------------------------
list flat(list p) {

    if (is_null(p))
        return null();

    list h = car(p);

    if (is_atom(h))
        return cons(h, flat(cdr(p)));

    return append(flat(h), flat(cdr(p)));
}

//------------------------------------------------------------------------------
// Name: two_the_same
// Purpose: Return true if p and q share at least one atom (at any depth)
// Preconditions: p and q are lists (possibly nested), not atoms
// Postconditions: Returns true iff there exists an atom present in both
//------------------------------------------------------------------------------
bool two_the_same(list p, list q) {

    if (is_null(p))
        return false;

    list h = car(p);

    if (is_atom(h)) {

        if (member(h, q))
            return true;

        return two_the_same(cdr(p), q);
    }

    if (two_the_same(h, q))
        return true;

    return two_the_same(cdr(p), q);
}

//------------------------------------------------------------------------------
// Name: equal
// Purpose: Structural equality of two recursive lists (atoms & parentheses)
// Preconditions: None
// Postconditions: Returns true iff shapes and atoms match exactly
//------------------------------------------------------------------------------
bool equal(list p, list q) {

    if (is_atom(p) && is_atom(q))
        return eq(p, q);

    if (is_atom(p) != is_atom(q))
        return false;

    if (is_null(p) && is_null(q))
        return true;

    if (is_null(p) || is_null(q))
        return false;

    return equal(car(p), car(q)) && equal(cdr(p), cdr(q));
}

//------------------------------------------------------------------------------
// Name: total_reverse
// Purpose: Reverse p and all its sublists recursively (mirror image)
// Preconditions: None
// Postconditions: Returns a new recursive list with reversed order at all levels
//------------------------------------------------------------------------------
list total_reverse(list p) {

    if (is_atom(p) || is_null(p))
        return p;

    return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
}

//------------------------------------------------------------------------------
// Name: shape
// Purpose: Return only the parentheses structure of p; atoms become ()
// Preconditions: p is a list (not an atom)
// Postconditions: Returns a recursive list with the same shape; atoms => ()
//------------------------------------------------------------------------------
list shape(list p) {

    if (is_null(p))
        return null();

    list h = car(p);

    if (is_atom(h))
        return cons(null(), shape(cdr(p)));

    return cons(shape(h), shape(cdr(p)));
}

//------------------------------------------------------------------------------
// Name: intersection
// Purpose: Set intersection of two flat lists of distinct atoms
// Preconditions: p and q are flat lists of distinct atoms (set semantics)
// Postconditions: Returns atoms in both p and q, without repetition
//------------------------------------------------------------------------------
list intersection(list p, list q) {

    if (is_null(p))
        return null();

    list a = car(p);

    if (member(a, q))
        return cons(a, intersection(cdr(p), q));

    return intersection(cdr(p), q);
}

//------------------------------------------------------------------------------
// Name: list_union
// Purpose: Set union of two flat lists of distinct atoms (no duplicates)
// Preconditions: p and q are flat lists of distinct atoms
// Postconditions: Returns atoms in p ∪ q, without repetition
//------------------------------------------------------------------------------
list list_union(list p, list q) {

    if (is_null(p))
        return q;

    list a = car(p);

    if (member(a, q))
        return list_union(cdr(p), q);

    return cons(a, list_union(cdr(p), q));
}

//------------------------------------------------------------------------------
// Name: substitute
// Purpose: Replace every occurrence of oldAtom with newAtom in p
// Preconditions: oldAtom and newAtom are atoms; p is a recursive list
// Postconditions: Returns a copy of p with substitutions applied
//------------------------------------------------------------------------------
list substitute(list oldAtom, list newAtom, list p) {

    if (is_null(p))
        return null();

    list h = car(p);

    if (is_atom(h)) {

        list r = eq(h, oldAtom) ? newAtom : h;

        return cons(r, substitute(oldAtom, newAtom, cdr(p)));
    }

    return cons(substitute(oldAtom, newAtom, h), substitute(oldAtom, newAtom, cdr(p)));
}

//------------------------------------------------------------------------------
// Name: remove
// Purpose: Remove all occurrences of atom q from flat list p
// Preconditions: p is a flat list of atoms; q is an atom
// Postconditions: Returns p with all occurrences of q removed
//------------------------------------------------------------------------------
list remove(list p, list q) {

    if (is_null(p))
        return null();

    list h = car(p);

    if (eq(h, q))
        return remove(cdr(p), q);

    return cons(h, remove(cdr(p), q));
}

//------------------------------------------------------------------------------
// Name: containsEqual (helper for subset)
// Purpose: Return true if some element in q is structurally equal to p
// Preconditions: q is a list (possibly empty)
// Postconditions: Returns true iff ∃x∈q such that equal(p, x) is true
//------------------------------------------------------------------------------
bool containsEqual(list p, list q) {

    if (is_null(q))
        return false;

    if (equal(p, car(q)))
        return true;

    return containsEqual(p, cdr(q));
}

//------------------------------------------------------------------------------
// Name: subset
// Purpose: Structural subset: every top-level element of p appears in q
// Preconditions: p and q are lists (not atoms)
// Postconditions: Returns true iff ∀x∈p, ∃y∈q with equal(x, y)
//------------------------------------------------------------------------------
bool subset(list p, list q) {

    if (is_null(p))
        return true;

    if (containsEqual(car(p), q))
        return subset(cdr(p), q);

    return false;
}

