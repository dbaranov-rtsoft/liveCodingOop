#pragma once

class Base {};
class PublicDerived : public Base {};
class PrivateDerived : private Base {};
class ProtectedDerived : private Base {};

void test() {
    PublicDerived   publicD;
    PrivateDerived  privateD;
    ProtectedDerived protectedD;

    Base& base1 = publicD;
    Base& base2 = privateD;
    Base& base3 = protectedD;
}