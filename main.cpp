#include "stdio.h"
#include "string.h"

#include "RefBase.h"
#include "StrongPointer.h"

using namespace android;

class Apple: public RefBase
{
	public:
		Apple(const char *name){
			strcpy(mName, name);
			printf("Construct: %s\n", mName);
		}

		~Apple(){
			printf("destruct: %s\n", mName);
		}

		void foo(void) {
			printf("this is foo in Apple()\n");
		}

	private:	
		char mName[64];	
};

int main()
{
	printf(" 1. \n");
	Apple *pA = new Apple("God's");

	printf(" 2. \n");
	{
		printf(" 2.1. \n");
		sp<Apple> spA(pA);
		spA->foo();

		printf(" 2.2. \n");
		wp<Apple> wpA(spA);

		printf(" 2.3. \n");
		sp<Apple> spA2(pA);
	}

	printf(" 3.\n");
	return 0;
}
