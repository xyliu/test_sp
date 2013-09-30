#include "stdio.h"
#include "string.h"

#include "RefBase.h"
#include "StrongPointer.h"
#include "apple.h"

using namespace android;

int main()
{
	printf(" 1. \n");
	Apple *pA = new Apple("God's");

	wp<Apple> wp1(pA);
	sp<Apple> sp1 = wp1.promote();

	/*
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
   */
	printf(" 3.\n");
	return 0;
}
