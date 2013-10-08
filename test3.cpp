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
	sp<Apple> spA;

	Apple *pA = new Apple("God's");
	
	spA = pA;

	wp<Apple> wpA(spA);

	return 0;
}
