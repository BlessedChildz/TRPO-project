#include <cxxtest/TestSuite.h>
#include "../src/utils.cpp"

class MyTestSuite : public CxxTest::TestSuite
{
public:
   void testSetupAlphabet1( void )
   {
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("n"), "1" );
   }
   void testSetupAlphabet2( void )
   {
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("p"), "1" );
   }
   void testSetupAlphabet3( void )
   {
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("y"), "1" );
   }
   void testSetupAlphabet4( void )
   {
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("N"), "1" );
   }
   void testSetupAlphabet5( void )
   {
	TS_ASSERT_DIFFERS( utils::setupPassAlphabet("npy"), "1" );
   }
   void testSetupAlphabet6( void )
   {
	TS_ASSERT_EQUALS( utils::setupPassAlphabet("z"), "1" );
   }
   void testPassGen1( void )
   {
   	TS_ASSERT_DIFFERS( utils::randomPass(1,"abcdefghijklmnopqrstuvwxyz"),"1");
   }
   void testPassGen2( void )
   {
	TS_ASSERT_DIFFERS( utils::randomPass(10,"abcdefghijklmnopqrstuvwxyz"),"1");
   }
   void testPassGen3( void )
   {
	TS_ASSERT_DIFFERS( utils::randomPass(100,"abcdefghijklmnopqrstuvwxyz"),"1");
   }
   void testPassGen4( void )
   {
	TS_ASSERT_DIFFERS( utils::randomPass(999,"abcdefghijklmnopqrstuvwxyz"),"1");
   }
   void testPassGen5( void )
   {
	TS_ASSERT_EQUALS( utils::randomPass(0,"abcdefghijklmnopqrstuvwxyz"),"1");
   }
};
