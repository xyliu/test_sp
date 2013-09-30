#ifndef MY_CLASS_APPLE
#define MY_CLASS_APPLE

#include "stdio.h"
#include "string.h"

#include "RefBase.h"

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

#endif
