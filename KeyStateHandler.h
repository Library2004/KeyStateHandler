#pragma once
#include<vector>
using std::vector;
class KeyStateHandler
{
	int clock[256];
	short previousState[256];// 0:up, 1:down
    short currentState[256];

	void update(int key, int clk);

public:
	KeyStateHandler()
	{
		for (int i = 0; i < 256; i++) {
			clock[i] = 0;
            previousState[i] = currentState[i] = 0;
		}
	}
	
	bool clickedDown(int key, int clk);
	bool clickedUp(int key, int clk);
	bool pressing(int key, int clk);
	bool clickedDownOrUp(int key, int clk);

	bool pressingAnyOf(vector<int> keys, int clk);
	bool pressingAllOf(vector<int> keys, int clk);
	bool clickedDownAnyOf(vector<int> keys, int clk);
};

