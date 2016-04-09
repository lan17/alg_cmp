const lim = 10000000;
var sum = 0;
for (var i = 3; i < lim; i += 1) {
  if (i % 3 == 0 || i % 5 == 0) {
    sum += i;
  }
}
console.log(sum);