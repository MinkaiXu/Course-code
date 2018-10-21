//Encoding GBK
//多项式相加

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

class node
{
  public:
    int coff, exp;
    node *next;

    node() { next = NULL; }
    node(int n1, int n2, node *p = NULL) : coff(n1), exp(n2), next(p) {}
};

node *add(node *exp1, node *exp2)
{
    node *res, *p, *tmp;

    res = p = new node();
    exp1 = exp1->next;
    exp2 = exp2->next;
    while (exp1 != NULL && exp2 != NULL)
    {
        if (exp1->exp < exp2->exp)
        {
            p->next = new node(exp1->coff, exp1->exp);
            exp1 = exp1->next;
        }
        else if (exp1->exp > exp2->exp)
        {
            p->next = new node(exp2->coff, exp2->exp);
            exp2 = exp2->next;
        }
        else
        {
            p->next = new node(exp1->coff + exp2->coff, exp2->exp);
            exp1 = exp1->next;
            exp2 = exp2->next;
        }
        p = p->next;
    }

    if (exp1 == NULL)
        tmp = exp2;
    else
        tmp = exp1;
    while (tmp != NULL)
    {
        p->next = new node(tmp->coff, tmp->exp);
        tmp = tmp->next;
        p = p->next;
    }
    
    return res;
}