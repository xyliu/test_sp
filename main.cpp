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

		void setStrongRefs(sp<Apple> a){
			spM= a;
		}   	

	private:	
		sp<Apple> spM;
		char mName[64];	
};

int main()
{
	Apple *pA = new Apple("God's");
	{
		sp<Apple> spA(pA);
		wp<Apple> wpA(spA);
	}
	return 0;
}
