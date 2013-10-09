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
				ALOGD(">>>Construct:(%p) %s\n", this,  mName);
			}

			~Bigclass(){
				ALOGD("<<<destruct: (%p) %s\n", this, mName);
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

	printf("A: *[%p] B: *[%p]\n", &A, &B);
	printf("-------\n");
	A->setStrongRefs(B);
	printf("-------\n");
	B->setWeakRefs(A);
	printf("-------\n");
}

void testCrossRef() {
	sp<Bigclass> A = new Bigclass("testNormalClassA");
	sp<Bigclass> B = new Bigclass("testNormalClassB");

	A->setWeakRefs(B);
	B->setWeakRefs(A);
}

int main(){
	ALOGD("* Start testStrongClasses..\n");
	testStrongCrossRef();
	ALOGD("* testStrongClasses Should be destructed!!\n\n");

	ALOGD("* Start testWeakClasses..\n");
	testWeakCrossRef();
	ALOGD("* testWeakClasses Should be destructed!!\n\n");

	ALOGD("* Start testNormalClasses..\n");
	testCrossRef();
	ALOGD("* testNormalClasses should be destructed!!\n\n");

	return 0;
}

