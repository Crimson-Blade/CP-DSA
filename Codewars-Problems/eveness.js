function iqTest(numbers) {
  const arr = numbers.split(' ').map(a => parseInt(a));
  const odd = arr.filter(num => n % 2 === 0);
  const even = arr.filter(num => n % 2 === 1);
  if (odd.length === 1) return odd; else return even;
}
