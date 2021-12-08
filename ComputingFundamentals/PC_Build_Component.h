#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

//Class used to initialize each component for the PC Building Mode 
class PC_Build_Component
{
private:
	String name;
	float price;
	int performance;
	bool isUnlocked;
	bool isUse;
};

