#include <cxxtest/TestSuite.h>
#include "../src/utils.cpp"

class MyTestSuite : public CxxTest::TestSuite
{
public:
   void testRandom( void )
   {
	TS_ASSERT_EQUALS( utils::random(2,0), 1 );
	TS_ASSERT_EQUALS( utils::random(0,0), 1 );
	TS_ASSERT_DIFFERS( utils::random(2,3), 1 );
	TS_ASSERT_DIFFERS( utils::random(4,10), 1 );
	TS_ASSERT_DIFFERS( utils::random(10,100), 1 );
	TS_ASSERT_DIFFERS( utils::random(0,999), 1 );
   }
   void testSetupAlphabet( void )
   {
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("n"), "1" );
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("p"), "1" );
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("y"), "1" );
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("N"), "1" );
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("npy"), "1" );
	TS_ASSERT_EQUALS( utils::setupPassAlphabet("z"), "1" );
   }
   void testPassGen( void )
   {
	TS_ASSERT_DIFFERS( utils::randomPass(1,"abcdefghijklmnopqrstuvwxyz"), "1");
	TS_ASSERT_DIFFERS( utils::randomPass(10,"abcdefghijklmnopqrstuvwxyz"), "1");
	TS_ASSERT_DIFFERS( utils::randomPass(100,"abcdefghijklmnopqrstuvwxyz"), "1");
	TS_ASSERT_DIFFERS( utils::randomPass(999,"abcdefghijklmnopqrstuvwxyz"), "1");
	TS_ASSERT_EQUALS( utils::randomPass(0,"abcdefghijklmnopqrstuvwxyz"), "1");
   }
};
