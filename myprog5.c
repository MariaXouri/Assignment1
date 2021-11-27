#include <stdio.h>


void perimeter(float radius){

float perimeter;

if(radius<0){

	printf("Wrong value");
	
	
}

else {
	perimeter=2*3.14159*radius;
	
	printf("The circle perimeter is : %f\n",perimeter);

}


}

int main(){


perimeter(8.2);

return 0;

}


