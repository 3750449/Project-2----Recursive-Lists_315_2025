#include "reclists.hpp"
#include "solutions.hpp"

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

list append(list p, list q) {

    if (is_null(p))
        return q;

    return cons(car(p), append(cdr(p), q));
}

list reverseTopLevel(list p) {

    if (is_null(p))
        return p;

    return append(cons(car(p), null()), reverseTopLevel(cdr(p)));
}

bool is_lat(list p) {

    if (is_null(p))
        return true;

    return is_atom(car(p)) && is_lat(cdr(p));
}

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

list last(list p) {

    if (is_null(cdr(p)))
        return car(p);

    return last(cdr(p));
}

list list_pair(list p, list q) {

    if (is_null(p) || is_null(q))
        return null();

    return cons(cons(car(p), cons(car(q), null())), list_pair(cdr(p), cdr(q)));
//    return cons(cons(car(p), car(q)), list_pair(cdr(p), cdr(q)));
}

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

list flat(list p) {

    if (is_null(p))
        return null();

    list h = car(p);

    if (is_atom(h))
        return cons(h, flat(cdr(p)));

    return append(flat(h), flat(cdr(p)));
}

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

list total_reverse(list p) {

    if (is_atom(p) || is_null(p))
        return p;

    return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
}

list shape(list p) {

    if (is_null(p))
        return null();

    list h = car(p);

    if (is_atom(h))
        return cons(null(), shape(cdr(p)));

    return cons(shape(h), shape(cdr(p)));
}

list intersection(list p, list q) {

    if (is_null(p))
        return null();

    list a = car(p);

    if (member(a, q))
        return cons(a, intersection(cdr(p), q));

    return intersection(cdr(p), q);
}

list list_union(list p, list q) {

    if (is_null(p))
        return q;

    list a = car(p);

    if (member(a, q))
        return list_union(cdr(p), q);

    return cons(a, list_union(cdr(p), q));
}

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

list remove(list p, list q) {

    if (is_null(p))
        return null();

    list h = car(p);

    if (eq(h, q))
        return remove(cdr(p), q);

    return cons(h, remove(cdr(p), q));
}

// helper for subset
static bool containsEqual(list p, list q) {

    if (is_null(q))
        return false;

    if (equal(p, car(q)))
        return true;

    return containsEqual(p, cdr(q));
}

bool subset(list p, list q) {

    if (is_null(p))
        return true;

    if (containsEqual(car(p), q))
        return subset(cdr(p), q);

    return false;
}
