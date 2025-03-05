#pragma once
class KeyStateHandler
{
	int clock;
	short previousState[256];// 0:up, 1:down
    short currentState[256];

	void update(int key, int clk);

public:
	KeyStateHandler()
	{
		clock = 0;
		for (int i = 0; i < 256; i++) {
            previousState[i] = currentState[i] = 0;
		}
	}
	
	bool clickedDown(int key, int clk);
	bool clickedUp(int key, int clk);
	bool pressing(int key, int clk);
	bool clickedDownOrUp(int key, int clk);
};

