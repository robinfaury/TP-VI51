#ifndef CELL_H_
#define CELL_H_

#include <vector>

#include "PhysicalObject.h"

class Cell
{
private:
	PhysicalObject* worldObject;
	std::vector<Cell*> nearCell;

public:
	Cell(void);

	void addNearCell(Cell* cell) {this->nearCell.push_back(cell);}
	void setWorldObject(PhysicalObject* worldObject) {this->worldObject = worldObject;}

	~Cell(void);
};

#endif