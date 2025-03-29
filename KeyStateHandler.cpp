#include "KeyStateHandler.h"
#include<Windows.h>

void KeyStateHandler::update(int key, int clk)
{
    if (clk != clock[key]) {
        previousState[key] = currentState[key];
        clock[key] = clk;
        currentState[key] = GetKeyState(key);
    }
}

bool KeyStateHandler::clickedDown(int key, int clk)
{
    update(key, clk);
    return (currentState[key]<0 != previousState[key]<0) && (currentState[key] < 0);
}

bool KeyStateHandler::clickedUp(int key, int clk)
{
    update(key, clk);
    return (currentState[key]<0 != previousState[key]<0) && (currentState[key] >= 0);
}

bool KeyStateHandler::pressing(int key, int clk)
{
    update(key, clk);
    return currentState[key] < 0;
}

bool KeyStateHandler::clickedDownOrUp(int key, int clk)
{
    update(key, clk);
    return (currentState[key] < 0 != previousState[key] < 0);
}

bool KeyStateHandler::pressingAnyOf(vector<int> keys, int clk)
{
    for (auto key : keys) {
        if (pressing(key, clk)) {
            return true;
        }
    }
    return false;
}

bool KeyStateHandler::pressingAllOf(vector<int> keys, int clk)
{
    for (auto key : keys) {
        if (!pressing(key, clk)) {
            return false;
        }
    }
    return true;
}

bool KeyStateHandler::clickedDownAnyOf(vector<int> keys, int clk)
{
    for (auto key : keys) {
        if (clickedDown(key, clk)) {
            return true;
        }
    }
    return false;
}

