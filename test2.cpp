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
			Bigclass(const char *name){
				strcpy(mName, name);
				ALOGD(">>>Construct: %s\n", mName);
			}

			~Bigclass(){
				ALOGD("<<<destruct: %s\n", mName);
			}

			void setStrongRefs(sp<Bigclass> b){
				spB = b;
			}   	

			void setWeakRefs(sp<Bigclass> b) {
				wpB = b;
			}

		private:	
			sp<Bigclass> spB;
			wp<Bigclass> wpB;
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

void testWeakCrossRef() {
	sp<Bigclass> A = new Bigclass("testWeakClassA");
	sp<Bigclass> B = new Bigclass("testWeakClassB");

	A->setStrongRefs(B);
	B->setWeakRefs(A);
}
int main(){
	ALOGD("* Start testStrongClasses..\n");
	testStrongCrossRef();
	ALOGD("* testStrongClasses Should be destructed!!\n\n");

	ALOGD("* Start testWeakClasses..\n");
	testWeakCrossRef();
	ALOGD("* testWeakClasses Should be destructed!!\n\n");
	return 0;
}

