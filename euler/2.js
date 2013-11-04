"use strict";

var lim = 4000000;

var a = 0;
var b = 1;
var sum = 0;
while( b <= lim )
{
	console.log(a);
	if( b % 2 == 0 ) sum += b;
	var t = b;
	b = a + b;
	a = t;
}
console.log(sum);