// multimeth.cpp
#include <iostream>
using namespace std;

/* Possible combinations (in ascending "most derived" order); existing methods marked*:
Y V A*
Y V B*
Y V C*
Y W A*
Y W B*
Y W C*
Y X A*
Y X B*
Y X C*
Z V A*
Z V B*
Z V C*
Z W A*
Z W B*
Z W C*
Z X A*
Z X B*
Z X C*
*/

class A { public: virtual ~A(){} };
class B : public A {};
class C : public B {};
class V { public: virtual ~V(){} };
class W : public V {};
class X : public W {};
class Y { public: virtual ~Y(){} };
class Z : public Y {};

string dispatch(const Y& y, const V& v, const A& a) {
    //Derivitives of Y
    const Z* pz = dynamic_cast<const Z*>(&y);
    
    //Derivitives of V
    const W* pw = dynamic_cast<const W*>(&v);
    const X* px = dynamic_cast<const X*>(&v);

    //Derivitives of A
    const B* pb = dynamic_cast<const B*>(&a);
    const C* pc = dynamic_cast<const C*>(&a);

    if (pz)
    {
        if (px)
        {
            if (pc)
            {
                return "Z X C";
            }
            else if (pb)
            {
                return "Z X B";
            }
            else
            {
                return "Z X A";
            }
        }
        else if (pw)
        {
            if (pc)
            {
                return "Z W C";
            }
            else if (pb)
            {
                return "Z W B";
            }
            else
            {
                return "Z W A";
            }
        }
        else
        {
            if (pc)
            {
                return "Z V C";
            }
            else if (pb)
            {
                return "Z V B";
            }
            else
            {
                return "Z V A";
            }
        }
    }
    else
    {
        if (px)
        {
            if (pc)
            {
                return "Y X C";
            }
            else if (pb)
            {
                return "Y X B";
            }
            else
            {
                return "Y X A";
            }
        }
        else if (pw)
        {
            if (pc)
            {
                return "Y W C";
            }
            else if (pb)
            {
                return "Y W B";
            }
            else
            {
                return "Y W A";
            }
        }
        else
        {
            if (pc)
            {
                return "Y V C";
            }
            else if (pb)
            {
                return "Y V B";
            }
            else
            {
                return "Y V A";
            }
        }
    }
}

void f(const Y& y, const V& v, const A& a) {
    cout << dispatch(y,v,a) << "\n";
}

int main() {
    A a;
    B b;
    C c;
    V v;
    W w;
    X x;
    Y y;
    Z z;

    f(y, v, a);
    f(y, v, b);
    f(y, v, c);
    f(y, w, a);
    f(y, w, b);
    f(y, w, c);
    f(y, x, a);
    f(y, x, b);
    f(y, x, c);
    f(z, v, a);
    f(z, v, b);
    f(z, v, c);
    f(z, w, a);
    f(z, w, b);
    f(z, w, c);
    f(z, x, a);
    f(z, x, b);
    f(z, x, c);
}
