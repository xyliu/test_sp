#include "stdio.h"
#include "string.h"
#include "RefBase.h"
#include "StrongPointer.h"

#ifndef ALOGD
#define ALOGD printf
#endif


namespace android{

	class Bigclass : public RefBase 
	{ 
		public:
			Bigclass(char *name){
				strcpy(mName, name);
				ALOGD(">>>Construct: %s\n", mName);
			}

			~Bigclass(){
				ALOGD("<<<destruct: %s\n", mName);
			}

			void setStrongRefs(sp<Bigclass> b){
				spB = b;
			}   	

		private:	
			sp<Bigclass> spB;
			char mName[64];	
	};

}

using namespace android;

void testStrongCrossRef(){
	sp<Bigclass> A = new Bigclass("testStrongClassA");
	sp<Bigclass> B = new Bigclass("testStrongClassB");

	A->setStrongRefs(B);
	B->setStrongRefs(A);
}

int main(){
	ALOGD("* Start testStrongClasses..\n");  
	testStrongCrossRef();
	ALOGD("* testStrongClasses Should be destructed!!\n");

	return 0;
}

