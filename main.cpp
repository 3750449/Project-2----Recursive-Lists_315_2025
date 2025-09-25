#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

int main()
{

    std::cout << "Enter a list: ";
    list p = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p);
    std::cout << "The number of nodes at the top level of the input list is: "
        << numNodesAtTheTopLevel(p) << std::endl;

///

    std::cout << "Enter a list: ";
    list p2 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p2);
    std::cout << "is_lat is: " << is_lat(p2) << std::endl;

    std::cout << "Enter an atom then a list: ";
    list atom3 = read_list();
    list q3 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(atom3);
    write_list(q3);
    std::cout << "member is: " << member(atom3, q3) << std::endl;

    std::cout << "Enter a list: ";
    list p4 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p4);
    std::cout << "last is: ";
    write_list(last(p4));
    std::cout << std::endl;

    std::cout << "Enter two lists of atoms of SAME length: ";
    list p5 = read_list();
    list q5 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p5);
    write_list(q5);
    std::cout << "list_pair is: ";
    write_list(list_pair(p5, q5));
    std::cout << std::endl;

    std::cout << "Enter a list whose elements are lists of atoms: ";
    list p6 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p6);
    std::cout << "firsts is: ";
    write_list(firsts(p6));
    std::cout << std::endl;

    std::cout << "Enter a list: ";
    list p7 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p7);
    std::cout << "flat is: ";
    write_list(flat(p7));
    std::cout << std::endl;

    std::cout << "Enter two lists: ";
    list p8 = read_list();
    list q8 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p8);
    write_list(q8);
    std::cout << "two_the_same is: " << two_the_same(p8, q8) << std::endl;

    std::cout << "Enter two recursive lists: ";
    list p9 = read_list();
    list q9 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p9);
    write_list(q9);
    std::cout << "equal is: " << equal(p9, q9) << std::endl;

    std::cout << "Enter a recursive list: ";
    list p10 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p10);
    std::cout << "total_reverse is: ";
    write_list(total_reverse(p10));
    std::cout << std::endl;

    std::cout << "Enter a list (not an atom): ";
    list p11 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p11);
    std::cout << "shape is: ";
    write_list(shape(p11));
    std::cout << std::endl;

    std::cout << "Enter two lists of DISTINCT atoms: ";
    list p12 = read_list();
    list q12 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p12);
    write_list(q12);
    std::cout << "intersection is: ";
    write_list(intersection(p12, q12));
    std::cout << std::endl;

    std::cout << "Enter two lists of DISTINCT atoms: ";
    list p13 = read_list();
    list q13 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p13);
    write_list(q13);
    std::cout << "list_union is: ";
    write_list(list_union(p13, q13));
    std::cout << std::endl;

    std::cout << "Enter OLD atom, NEW atom, then a LIST: ";
    list old14 = read_list();
    list new14 = read_list();
    list p14 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(old14);
    write_list(new14);
    write_list(p14);
    std::cout << "substitute is: ";
    write_list(substitute(old14, new14, p14));
    std::cout << std::endl;

    std::cout << "Enter a LIST of atoms, then an ATOM: ";
    list p15 = read_list();
    list atom15 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p15);
    write_list(atom15);
    std::cout << "remove is: ";
    write_list(remove(p15, atom15));
    std::cout << std::endl;

    std::cout << "Enter two lists: ";
    list p16 = read_list();
    list q16 = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p16);
    write_list(q16);
    std::cout << "subset is: " << subset(p16, q16) << std::endl;

    std::cout << "\nDone.\n";

    return 0;
}
