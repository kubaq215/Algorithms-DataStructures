#include <cppunit/extensions/HelperMacros.h>

#include "pqueue.hpp"
#include <string>

class Samel01 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Samel01);
    CPPUNIT_TEST(testPierwszy);
    CPPUNIT_TEST(testDrugi);
    CPPUNIT_TEST(testCzwarty);
    CPPUNIT_TEST_SUITE_END();

public:

    void testPierwszy()
    {
        PQueue<int> p;
        p.enqueue(3,3);
        p.enqueue(2,2);
        p.enqueue(1,1);
        p.enqueue(5,5);
        p.enqueue(4,4);
        CPPUNIT_ASSERT( p.dequeue() == 5 );
        CPPUNIT_ASSERT( p.dequeue() == 4 );
        CPPUNIT_ASSERT( p.dequeue() == 3 );
        CPPUNIT_ASSERT( p.dequeue() == 2 );
        CPPUNIT_ASSERT( p.dequeue() == 1 );
    }

    void testDrugi()
    {
        PQueue<string> p;
        p.enqueue("3",3);
        p.enqueue("2",2);
        p.enqueue("1",1);
        p.enqueue("5",5);
        p.enqueue("4",4);
        CPPUNIT_ASSERT( p.dequeue() == "5" );
        CPPUNIT_ASSERT( p.dequeue() == "4" );
        CPPUNIT_ASSERT( p.dequeue() == "3" );
        CPPUNIT_ASSERT( p.dequeue() == "2" );
        CPPUNIT_ASSERT( p.dequeue() == "1" );
    }

    void testCzwarty()
    {
        PQueue<int> p;
        p.enqueue(3,3);
        CPPUNIT_ASSERT( p.front() == 3 );
    }
};

class Samel02 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Samel02);
    CPPUNIT_TEST(testTrzeci);
    CPPUNIT_TEST_SUITE_END();

public:

    void testTrzeci()
    {
        CPPUNIT_ASSERT( 2 + 2 == 4 );
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Samel01);
CPPUNIT_TEST_SUITE_REGISTRATION(Samel02);
