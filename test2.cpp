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

	printf("-------\n");

	sp<Bigclass> B = new Bigclass("testStrongClassB");

	printf("-------\n");

	A->setStrongRefs(B);

	printf("-------\n");

	B->setStrongRefs(A);

	printf("-------\n");
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

void testW() {
	Bigclass *p = new Bigclass("PPPP");
	wp<Bigclass> A;
	{

	   printf("in\n");
	   wp<Bigclass> B(p);
	   wp<Bigclass> C(p);
	   A = B;
	   printf("out\n");
	}
	wp<Bigclass> D = A;
}

void testS() {
	Bigclass *p = new Bigclass("QQQQ");
	{
	   sp<Bigclass> A(p);
	   sp<Bigclass> B(p);
	   sp<Bigclass> C(p);
	   printf("out\n");
	}
	sp<Bigclass> D(p);
}

int main(){
	ALOGD("* Start testStrongClasses..\n");
//	testStrongCrossRef();
	ALOGD("* testStrongClasses Should be destructed!!\n\n");

	ALOGD("* Start testWeakClasses..\n");
	testWeakCrossRef();
	ALOGD("* testWeakClasses Should be destructed!!\n\n");

	ALOGD("* Start testNormalClasses..\n");
//	testCrossRef();
	ALOGD("* testNormalClasses should be destructed!!\n\n");

	// printf("segment fault \n";
	//testW();
	//testS();
	return 0;
}

