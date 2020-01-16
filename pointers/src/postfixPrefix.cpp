int postfixPlasPlas(int *number) {
	int temp = *number;
	*number = *number + 1;
	return temp;
}

int prefixPlasPlas(int *number) {
	*number = *number + 1;
	return *number;
}
