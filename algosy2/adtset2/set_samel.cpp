#include <cppunit/extensions/HelperMacros.h>

#include "set.hpp"
#include <string>

class Palacz01 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Palacz01);
    CPPUNIT_TEST(testPierwszy);
    CPPUNIT_TEST(testDrugi);
    CPPUNIT_TEST(testCzwarty);
    CPPUNIT_TEST_SUITE_END();

public:

    void testPierwszy()
    {
        Set<int> s1, s2;
        for(int i=0; i<6; i++)
        {
            s1.insert(i);
            s2.insert(i+3);
        }
        s1.Union(s2);

        CPPUNIT_ASSERT( s1.contains(3) );
        CPPUNIT_ASSERT( s1.contains(2) );
        CPPUNIT_ASSERT( s1.contains(8) );
    }

    void testDrugi()
    {
        Set<std::string> s1;
        s1.insert("foo");
        s1.insert("bar");
        s1.insert("uuu");
        s1.insert("oeir");

        Set<std::string> s2;
        s2.insert("bar");
        s2.insert("baz");

        s1.intersection(s2);

        CPPUNIT_ASSERT( s1.contains("bar") );
        CPPUNIT_ASSERT( !s1.contains("foo") );
        CPPUNIT_ASSERT( !s1.contains("baz") );
        CPPUNIT_ASSERT( !s1.contains("uuu") );
        CPPUNIT_ASSERT( !s1.contains("oeir") );
    }

    void testCzwarty()
    {
        Set<int> s1, s2;
        for(int i=0; i<6; i++)
        {
            s1.insert(i);
            s2.insert(i+3);
        }
        s1.difference(s2);

        CPPUNIT_ASSERT( !s1.contains(3) );
        CPPUNIT_ASSERT( s1.contains(2) );
        CPPUNIT_ASSERT( !s1.contains(8) );
    }
};

class Palacz02 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Palacz02);
    CPPUNIT_TEST(testTrzeci);
    CPPUNIT_TEST_SUITE_END();

public:

    void testTrzeci()
    {
        CPPUNIT_ASSERT( 2 + 2 == 4 );
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Palacz01);
CPPUNIT_TEST_SUITE_REGISTRATION(Palacz02);
