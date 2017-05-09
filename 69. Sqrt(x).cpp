class Solution {
public:
	int mySqrt(int x) { // a*a=x
    	if (x == 0) 
    	    return 0;
		int left = 1, right = 0x7fffffff;
		while(1){
		    int min = left + (right - left)/2;
		    if(min > x/min){
                right = min - 1;
		    }
		    else{
		        if((min+1) > x/(min+1))
		            return min;
		        left = min + 1;
		    }
		}
	}
};
