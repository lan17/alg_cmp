"use strict";

var lim = 1000;
var sum = 0;
var nums = [3,5];
var seen = {};
for( var i = 1; i < lim; ++i )
{
	for( var j in nums )
	{
		var t = nums[j] * i;
		if( t < lim )
		{
			if( ! (t in seen ) )
			{
				sum += t;
				seen[t] = true;
			}
		}
	}
}
console.log(sum);