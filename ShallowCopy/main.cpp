#include "Shallow.h"

											/*@SuperCoolNinja*/
/*
	I made this little project to understand and show how can shallow copy be bad using with pointer.
	So the best choice we have is to use deep copy. which I will probably share it into another repo just for learning purpose.
*/


//Now when this will be used it will cuz an out of scope then the destructor will be call and guess what ... :
static void displayShadowData(Shallow sourceOne, Shallow sourceTwo)
{
	std::cerr << "\nData with :" << sourceOne.getShadowDataName() << " " << sourceOne.getShadowData() << "\n";
	std::cerr << "\nData with :" << sourceTwo.getShadowDataName() << " " << sourceTwo.getShadowData() << "\n";
}

int main()
{
	//Init our obj1 ptr to have 42 :
	Shallow obj1{ 42, "Obj1"};

	//Now come to the shallow copy : 
	Shallow obj2{ obj1, "obj2"};

	//Setting new value on obj2 will be reflected so all copy got the same ptr data : 150 in this case.
	obj2.setShadowData(150);


	/*
		When this will be call it will free the obj1 memory then it will try to free the obj2 memory but 
		since both share the same memory, the obj2 will have an invalid memory cuzing the crash.
	*/
	displayShadowData(obj1, obj2);

	std::cin.get();

	EXIT_SUCCESS();
}
