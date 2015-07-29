#ifndef STACK_H
#define STACK_H

class stack
{
public:
	stack(int initialNumberOfMatches);
	~stack();

	bool isEmpty();
	int numberOfMatchesRemaining();
	void takeNMatches(int N);
	void putNMatches(int N);

private:
	int numberOfMatches;
};

#endif
